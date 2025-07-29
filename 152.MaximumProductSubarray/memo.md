## ステップ1
まず思いついた解法はbrute forceで愚直に積を求める方法
これだと時間計算量は、O(n^2)となる
nums.lengthは2 * 10 ^ 4なので4 * 10 ^ 8 C++だとギリギリ1秒ないに処理できそう

各ステップで最大になるタイミングを追いかける
・あるnums[i]でリセットする場合(負の数を奇数個含む場合はnums[i]の方が大きくなることがある)
・正の数ばかりがsubarrayに含まれる場合
・負の数偶数個含む場合
単に正の数だけ追うのではなく負の数も追いかけると1ループで見つけられそう
時間計算量はO(n)
空間計算量はO(1)

acceptまで12分

配列が空の場合にreturn 0とする。
本当はありえない数字を返したかった。エラーメッセージを表示するなどでも良さそう。

## ステップ2
step1の変数名が長いので、変更

maxとminの使い方変更
initializer listsを使うことで複数の値でも使うことができる
https://cplusplus.com/reference/algorithm/max/

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の解法
負の数が偶数個あると最大になりうる特性を活かして途中でswapすることで
自分のstep1で行った3パターンから2パターンへ比較回数を減らすことができる(step2_2で実装)
これは初見で思いつくことが難しそうなので愚直に比較したい
https://leetcode.com/problems/maximum-product-subarray/solutions/48230/possibly-simplest-solution-with-o-n-time-complexity/

## Discorなど

