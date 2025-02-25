# 事故の教訓からヒントを得た変なループ処理
## プログラムの内容
[loop.sh](./loop.sh)は以下のようになっています。
```bash
#! /bin/bash
export LOOP="echo 'hello'; echo \$LOOP >> temp.sh"
echo $LOOP > temp.sh
chmod 777 temp.sh
./temp.sh &
sleep 3
rm temp.sh

# 削除後に生成されうるので少し待って消す
sleep 1
rm temp.sh
```

## 実行方法の例
WSLで以下のようにコマンド入力を行う。
```bash
programming_memo/Bash/strange_loopp$ ./loop.sh
```

## 問題
実行すると何が標準出力されるでしょうか？  

<details>
<summary>答え</summary>

3秒間temp.shがhelloを繰り返し出力し続けます。

なんとBashのシェルスクリプトは実行中に書き込まれた行も読んで実行します。

本問では実行中にファイル末尾に追加した```echo 'hello'; echo \$LOOP >> temp.sh```を実行するため、```hello```を標準出力したあと```echo 'hello'; echo \$LOOP >> temp.sh```を末尾に書き込みループします。

```bash
#! /bin/bash
export LOOP="echo 'hello'; echo \$LOOP >> temp.sh" # 「temp.shの実行中にtemp.shの末尾に自分自身を追加する」コマンド列を文字列として変数LOOPに格納
echo $LOOP > temp.sh #temp.shを変数LOOPで初期化する。既にあれば内容を全て上書き。なければ生成。
chmod 777 temp.sh # 実行・削除できるように権限付与
./temp.sh & # loop.shが動作するようにバックグラウンド実行
sleep 3
rm temp.sh # 3秒後にtemp.shを消す

# 削除後にecho \$LOOP >> temp.shが実行されてtemp.shが生成されうるので少し待って消す(並行処理って難しいですね)
sleep 1
rm temp.sh
```

京大のスパコンでファイルが77TB消えた事件があったが、これは本問と同じ実行中スクリプト更新が原因らしいです([参考](https://xtech.nikkei.com/atcl/nxt/column/18/01157/012700053/))。普段の業務や学習でも気をつけないといけませんね。
</details>