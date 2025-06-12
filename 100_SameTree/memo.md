## ステップ1での思考過程
まず思いついた方法は、inorder、preorder、postorderを使って探索して
その探索結果をvectorか何かに格納して等しいか判断。
使う探索は一つでいいのか、複合的に確認する必要があるのか小さい例で確認する
Trueの場合は、いずれの探索方法でも出力結果は同じになるはずなのでfalseのケースを確認。

例よりnodeが2つある場合
1. p = [1,2], q = [1,null,2] output = false
inorder
p [2, 1] | q [1, 2]
preorder
p [1, 2] | q [1, 2]
postorder
p [2, 1] | q [2, 1]
inorderを用いれば判断できる?

2. p = [1,2,1], q = [1,1,2] output = false
inorder
p [1, 2, 1] | q [1, 1, 2]
preorder
p [1, 2, 1] | q [1, 1, 2]
postorder
p [2, 1, 1] | q [1, 2, 1]
いずれの探索でも判断できる?

3. p = [1, 2, 3, 4] q = [1, 2, 3, null, null, 4] output = false
inorder
p [4, 2, 1, 3] | q [2, 1, 3, 4]
preorder
p [1, 2, 4, 3] | q [1, 2, 3, 4]
postorder
p [4, 2, 3, 1] | q [2, 4, 3, 1]
inorderだけで十分そう。

再帰関数で探索を行いながら、vectorに数字を入れていく。
実装前に見積もってみる
計算量はO(m)もしくはO(n) 
mはpのノード数
nはqのノード数
mとnの大きさに依存

### step1_wa
上記の方法だと、全て同じ数字が入っている場合検出できない
pとqのnodeを同時に探索しつつvectorに入れないでその場で判定する
無駄に難しく考えたけどこの方が素直ですね。

探索途中で、
片方のnodeのみnullptr -> false
valueが一致しない -> false
全体でacceptまで35分(NGまで25分、acceptまで10分)ほど

## ステップ2
* step1では、探索部分を外だしをして関数定義をしたが
  特に何かしているわけではないので外だしをやめる
  したかったことといえば、pとqの変数名を書き換えたかったこと

* prefixにfirstやsecondを使って表現していたが
  nodeとother_nodeとしてみた

* 再帰からqueueを使ったバージョンへの変更
何度も同じようなチェックをしている気がする
ノード数は最大でも100個なので今回は再帰の方が可読性が高いので個人的には好き

>C 言語の場合の話となりますが、関数呼び出しを行うたびにスタックフレームが作られます。スタックフレームには以下のような値が格納されます。
>・引数
>・オート変数
>・リターンアドレス
>・リターン値設定アドレス
>・レジスタ退避域
>・一時変数
https://github.com/Ryotaro25/leetcode_first60/pull/30#discussion_r1734602153

* 過去にいただいた指摘から64bitコンピュータを想定して計算してみる
・引数 それぞれ8バイト
・オート変数　今回は未使用
・リターンアドレス 8バイト
・リターン値設定アドレス 8バイト
・レジスタ退避域 16(たいていが16のよう)
・一時変数　今回は未使用
なので40バイト * 100 = 4000バイト ≒ 4KB
>リンカーで使用される既定のスタック予約サイズは 1 MB です
https://learn.microsoft.com/ja-jp/windows/win32/procthread/thread-stack-size
とのことなので問題なしか
Linuxは8MB

下記みたいな話もあるんですね。
>you can approximate that with the size of the arguments plus a constant return address size.
https://stackoverflow.com/questions/47606967/how-can-i-calculate-approximate-the-memory-used-by-a-stack-frame-of-a-recursive


## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の解法
調べた感じ、再帰で探索するかstackもしくはqueueを用いて探索するかのどちらかかな


## Discorなど

