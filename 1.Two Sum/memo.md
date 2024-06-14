## ステップ1
forを２重で回せば解けたけどO(n^2)となってしまう
どうすれば計算量を抑えられるのかが今回の問題だと思う。
時間
O(n^2)
空間
O(1)

~~問題のジャンルがhash mapなのでmapを使った解法を考える~~
liquo-riceさんから指摘があったようにMapは平衡二分探索木、unordered_mapがhash map

<数値、インデックス>でmapを作りこれをループで回して
targetから数値を引いた数をもつindexを探せばO(1)ですみそう

Keyが重複する場合の回答の見つけ方が分からなかったので回答を参照
https://leetcode.com/problems/two-sum/
ループの最後に挿入することで
重複を上書きする前に、keyとvalueを見つけることができる
~~時間~~
~~O(n)~~
空間
O(n)

時間
mapのcontainsを使う場合(log n)なので合計O(n log n)
unordered_mapのcontainsを使う場合はO(n)なのでO(n^2)
https://en.cppreference.com/w/cpp/container/unordered_map/contains
## ステップ2
・解なしの場合も考慮する、今回だと{}をreturnすることで差別化
https://github.com/colorbox/leetcode/pull/3#discussion_r1519068995
https://github.com/cheeseNA/leetcode/pull/1

・命名について
numsとnumbersどちらも存在しているのは気持ち悪いような気がするのでどちらかに統一
https://github.com/sakupan102/arai60-practice/pull/12

・算術演算子についてもスタイルガイドが存在する
https://github.com/fhiyo/leetcode/pull/14

## 他の解法
２重ループの回答はloop.cppに実装

## Discordなど
私は紙と鉛筆でやるんだったら、カードをソートして、頭と尻から辿っていくと思いますね。
はじめに、一番初めと一番最後に着目します。
着目しているものを足します。
目標よりも小さかったら、前の方の着目しているのを一つ後ろにずらします。
目標よりも大きかったら、後ろの方の着目しているのを一つ前にずらします。
https://discord.com/channels/1084280443945353267/1183683738635346001/1187326805015810089
