## ステップ1
>if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. 
[1,2,3]の次は[1,3,2]ということ
>If such arrangement is not possible, the array must be rearranged as the lowest possible order
[3,2,1]の次は[1,2,3]に戻るということ

これだけだと分からないので
[1,2,3,4]で考える
[1,2,4,3] 
[1,3,2,4]
[1,3,4,2]
[1,4,2,3]
[1,4,3,2]
[2,1,3,4]
.
.
.
20分ほど考えて分からなかったので、回答を見る
前に、next_permutationを使った際に実装方法まで見ておけばよかった
https://en.cppreference.com/w/cpp/algorithm/next_permutation

次の順列を作る流れは以下の通りとなっている。
1.後ろから探索して、numsの中で最初に、前から昇順に並んでいるインデックスを探す
2.1のインデックスに対応する値より大きい、最も右にある要素を探す
3.1と2の要素を入れ替える
4.1.のインデックス以降を昇順にする(元々は降順)


## ステップ2
・first_increasing_order_index
  この変数名から何をしたいのか分かりにくいのと、
  実際はfirst_increasing_order_index - 1として使っていることが多いため
  単にpivotとかでも良さそう

・next_larger_index
  nextよりrightmostの方がまだ良さそう
  コメントがないと何をしているのか伝わらない
  コメントも微妙なので、改善等あれば言って頂けると助かります。

・reverse
  pivot以降を逆順に並び変える箇所について
  元々pivot以降は降順に並んでいるので、reverseを使い結果として昇順に並び替えているが
  sortを使った方がわかりやすいような気がする
  O(n)からO(n log n)になるが、昇順に並び替えているというのは伝わりそう

next_permutation関数を使うのは、求めらていないだろう

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法

自分の知らない関数をいくつか使われていて勉強になる
https://en.cppreference.com/w/cpp/algorithm/adjacent_find
https://en.cppreference.com/w/cpp/algorithm/iter_swap

>// Find the first DSC pair from the tail : [4,(5,7),6,3,2,1]
>// to point to the second element of the pair :
>// [4,(*5,7),6,3,2,1]
この辺りのコメントの書き方が分かりやすいと思った。

iteratorを使って処理することでコードを綺麗に纏められそう
https://github.com/usatie/leetcode/pull/2/commits/f0875e0db129eb5eabcb5fd6363de8258befe3ce


>引数は広い型で指定した方が使える場面が増えるかなと思って、一応そうしてみてます。
目先の問題に囚われないで実務を想定している。この考え方なるほどです。

二分探索の選択肢は持っておく
lower_bound.cppに実装
https://github.com/fhiyo/leetcode/pull/56/commits/6836d3c8ee01216ccd303dc5df93b199311a4e18

>実際はleftより後ろの要素のうち、nums[left]より大きい一番後ろの要素のindexを返しているので
確かに処理に対して適切な名前を付けるは難しい
関数に分けて、関数名や引数から処理を予想させるは良さそう
https://github.com/Mike0121/LeetCode/pull/15/commits/cac8eb6c5ecc3db4644cb5f9b34c7046238b53e1

## Discordなど

