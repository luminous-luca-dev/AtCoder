import os
import time
import requests
from bs4 import BeautifulSoup

# 環境変数からユーザーIDを取得
USER_ID = os.environ.get("ATCODER_USER_ID")
if not USER_ID:
    print("Error: ATCODER_USER_ID is not set.")
    exit(1)

# AtCoder Problems APIのエンドポイント
API_URL = f"https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={USER_ID}&from_second="
LAST_TIMESTAMP_FILE = "last_timestamp.txt"

def get_extension(language):
    lang = language.lower()
    if "c++" in lang: return ".cpp"
    if "python" in lang or "pypy" in lang: return ".py"
    if "javascript" in lang or "node" in lang: return ".js"
    return ".txt" # その他の言語

def main():
    last_timestamp = 0
    # 前回どこまで取得したかをファイルから読み込む
    if os.path.exists(LAST_TIMESTAMP_FILE):
        with open(LAST_TIMESTAMP_FILE, "r") as f:
            content = f.read().strip()
            if content.isdigit():
                last_timestamp = int(content)

    print(f"Fetching submissions from timestamp: {last_timestamp}")
    
    # APIから提出履歴を取得
    res = requests.get(API_URL + str(last_timestamp))
    if res.status_code != 200:
        print(f"Failed to fetch API: Status {res.status_code}")
        return

    submissions = res.json()
    # 古い順にソート
    submissions.sort(key=lambda x: x["epoch_second"])

    if not submissions:
        print("No new submissions found.")
        return

    new_last_timestamp = last_timestamp

    for sub in submissions:
        sub_id = sub["id"]
        contest_id = sub["contest_id"]
        problem_id = sub["problem_id"]
        result = sub["result"] # AC, WA, CE など
        lang = sub["language"]
        ext = get_extension(lang)

        if sub["epoch_second"] < last_timestamp:
            continue

        # AtCoderのサーバーに負荷をかけないよう必ず1.5秒待機（超重要）
        time.sleep(1.5)
        
        # 提出詳細ページからコードを取得
        url = f"https://atcoder.jp/contests/{contest_id}/submissions/{sub_id}"
        print(f"Fetching: {url} ({result})")

        html = requests.get(url)
        soup = BeautifulSoup(html.text, "html.parser")
        code_block = soup.find("pre", id="submission-code")

        if not code_block:
            print(f"Could not find code for {sub_id}. (May be private or ongoing contest)")
            continue

        code = code_block.text

        # 保存先ディレクトリの作成 (例: abc300/abc300_a)
        dir_path = os.path.join(contest_id, problem_id)
        os.makedirs(dir_path, exist_ok=True)

        # ファイル名 (例: 12345678_WA.py)
        filename = f"{sub_id}_{result}{ext}"
        filepath = os.path.join(dir_path, filename)

        # コードを保存
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(code)

        # 最後に成功した時間を更新
        new_last_timestamp = sub["epoch_second"] + 1

    # 次回の実行のためにタイムスタンプを保存
    with open(LAST_TIMESTAMP_FILE, "w") as f:
        f.write(str(new_last_timestamp))

if __name__ == "__main__":
    main()
