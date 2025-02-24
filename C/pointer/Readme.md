# ポインタとハードウェア依存な入力
## 実行方法の例
WSLで以下のようにコマンド入力を行う。
```bash
programming_memo/C/pointer$ gcc pointer.c -o pointer
programming_memo/C/pointer$ ./pointer
```

## 問題
実行して0以上255以下の数字を二つ入力すると何が標準出力されるでしょうか？  
※二つ入力するときは一つ目と二つ目の間に空白か改行を入れてください

例えば1,2を入力するとこんな感じです
```bash
programming_memo/C/pointer$ ./pointer
Enter two integers between 0 and 255.
1 2
```
<details>
<summary>答え</summary>

上記の入力1,2の例で考えます。

1. お使いのCPUがリトルエンディアンなら
    ```bash
    1
    2
    ```
    と表示されます。
1. お使いのCPUがビッグエンディアンなら
    ```bash
    2
    1
    ```
    と表示されます。

</details>