## ステップ1
vectorを使って常に降順にしておいて、k番めの数値を返却すれば解けそう
毎回sortしているのでエラーが出ている？
Kthより大きい場合だけ要素の追加とsortなら大丈夫？
この場合でもエラー。
そもそもsortがruntime errorになる要素数は？

# テストケース9個目、初期値かなり大きいもののRuntime Errorの回避方法がわからなかったので
# ここで回答確認した。
毎回並び変えるのではなく、イテレータを使って要素を挿入することで時間内に解くことができる。
https://leetcode.com/problems/kth-largest-element-in-a-stream/solutions/3554410/stl-sort-lower-bound/

降順で取得してiteratorはreverse_iteratorになるのでinsertを使うことが出来ない。
lower_boundを初めて見たので常識的なものか分からないので一旦whileループで解いてみた。

priority_queueで解くのが主流？そうだけど、使ったことはなく名前を知っているレベル。

この問題の計算量について
https://qiita.com/takechanman1228/items/73623446fdfb6ff7152e

時間計算量
O(n^2)
sort部分が最も時間をとる
https://cpprefjp.github.io/reference/algorithm/sort.html

lower_bound
最大で log2( last - first ) + O(1) 回の比較を行うとのことなので、最悪O(logn) + O(1)
https://cpprefjp.github.io/reference/algorithm/lower_bound.html

insert
要素数に影響を受けるので、O(n)
https://cpprefjp.github.io/reference/vector/vector/insert.html

空間計算量
O(n)
vectorに全てを追加する場合

## ステップ2
lower_boundを使うとシンプルに書くことができる
lower_boundについて
https://cpprefjp.github.io/reference/algorithm/lower_bound.html

## 他の解法
priority_queueを使った解法
https://leetcode.com/problems/kth-largest-element-in-a-stream/solutions/596093/c-solution-with-understandable-explaination/

priority_queueとは
ヒープの応用例の1つ。maxもしくはminの優先度キューを加えたもの
参照：アルゴリズムイントロダクション(p145)

https://cpprefjp.github.io/reference/queue/priority_queue.html
時間計算量
pushはO(logn) 追加と並びかえを含む
https://www.geeksforgeeks.org/priority_queuepush-priority_queuepop-c-stl/

popとtopはO(1)

空間計算量
kのサイズに左右されるのでO(n)

priority_queueを用いた回答priority_queue.cppに実装

## Discordなど
odaさんのHeap
https://discord.com/channels/1084280443945353267/1192736784354918470/1194613857046503444
sakupanさんのHeap
https://github.com/sakupan102/arai60-practice/pull/9/files
TORUSさんのHeap
https://github.com/TORUS0818/leetcode/pull/10/files
fhiyoさんのHeap
https://github.com/fhiyo/leetcode/blob/703_kth-largest-element-in-a-stream/703_kth-largest-element-in-a-stream.md

皆さんの回答を見ながらheapを一から作成した回答heap.cppに実装
基本的な考え方はアルゴリズムイントロダクションを読んだ

