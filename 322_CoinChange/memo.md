## ステップ1
降順に並べ替えて、大きい数字からコインの枚数として数えていく
この方法だと下記のようなパターンでWAとなる
coins = [1, 6, 7, 9, 11] , amount = 13.
自分のロジックだと11 1 1となるが実際の答えは6 7

ボトムアップDPを使って0からamountまでの各ステップで最小のコインの数を数える
acceptまで約45分

時間計算量
O(m * n)
m = amountまでの数
n = コインの種類

空間計算量
O(m * n)

## ステップ2
・変数名変更
  マウントに対するコインの枚数を格納しているのでmin_amountsはおかしい
  forループのi を amountに変更

bfsでも実装 bfs.cpp
visitedの更新位置とnext_amountの有効性チェックでハマった
visitedの更新位置：訪問したらすぐに値を更新しないとqueueに値突っ込んでしまう
next_amountの有効性:amountが2147483647である場合に+1すると溢れる

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
ボトムアップで解いている
自分はiterationのiを用いたがamountのように変数を用いる方がわかりやすそう
dfsで解くことも可能
https://github.com/nittoco/leetcode/pull/38

一つの変数に無理に２つ以上の意味合いを持たせるより、変数を分けることも一つの選択肢
top downで解くことも可能
https://github.com/Yoshiki-Iwasa/Arai60/commit/d99a348354e057b59b4ba3763ff3fbd97dd33f3e

>上限はamount + 1でもよさそうですね。coinの最小の値が1なので解の最大値はamount枚になります。
確かに
>最短経路問題で深さ優先探索をすると、無駄な探索をしてしまうと思います。これが原因だと思います。最短経路問題で、かつ枝の距離が 1 のため、 2nd のように幅優先探索を使うとよいと思います。
なっとくアルゴリズムにさらっと書いていた気がする。さまざまな解法を理解することに加えて向き不向きも理解する
https://github.com/fhiyo/leetcode/pull/41

こちらのステップ３が1番しっくりきた
自分の場合、今見ているamountに対してコインの数字の方が大きい場合amountを作ることができないのでcontinueしている
が、残りが負でないか確認する方が伝わり易いか
https://github.com/goto-untrapped/Arai60/pull/34
https://github.com/sakupan102/arai60-practice/pull/41
## Discorなど

