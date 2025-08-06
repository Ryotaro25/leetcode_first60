## ステップ1
愚直に総当たりで解く方法を思いついたがTLE
https://ja.wikipedia.org/wiki/Long_Term_Evolution

brue_force.cppに実装

ループを一つにするために最小の数値を記録し、
今いる地点の値 - 記録しておいた最小の数値を引くことで最大利益を求めることができる

acceptまで約25分
時間計算量O(n)
空間計算量O(1)

最大値を記録する方法も試したが、下記条件のため解くことが出来なかった
> Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
最小の値を記録すること=売る前に購入していることとなる

## ステップ2
・continueを削除してmin関数に置き換え
  コードは短くなるがstep1のように(prices[i] < minimum_price)の条件で最小を更新し、
  でcontinueしたほうがわかり易い気がする
  日毎に価格が決まっているので同じ日に購入して、同じ日に売却することはしない

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
基本は同じ
・gotoさんの解法
最初にpricesの長さが0であればreturn 0をしているが
返却用の値を0で初期化しておけば必要なさそう(ループは回らないため)

> 最大、最小の値というよりは、i日目以前の最小の値とi日目以後の最大の値という方が正確な気がしました。
こちらの説明の方がより正確だと思った

関数言語のような考え方
https://zvon.org/other/haskell/Outputprelude/scanl_f.html
1ステップごとに状態を保持しながら計算するもの
https://github.com/goto-untrapped/Arai60/pull/58/commits/1f7d312405a44b21068a54133b07728b38481c9d#diff-afb63c27dcc92421f2dee144967d013659e6480ca1c1583528379238633b7a02

https://github.com/Yoshiki-Iwasa/Arai60/pull/52/commits/7234fc56e0c14730d2883700e5650c787eeb0c2c

> loop中に呼び出す関数がどの程度コストがかかるかは気にしておいた方が良い、という趣旨でコメントしていました。仮にDB呼び出しするとよく言われるN+1問題に遭遇するので、、、くらいです。

今回でいえばminやmaxをループの中で使っているがコストの意識はしていなかった
https://github.com/fhiyo/leetcode/pull/38/commits/b45f9f0d79cfaf4c46bdf824d8e491e3b2c0cce7

https://github.com/erutako/leetcode/pull/3

## Discordなど

