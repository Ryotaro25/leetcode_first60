## ステップ1
map<int, pair<int, int>>かtupple<int, int, int>を使って最初にnum1とnum2と合計を用意しておいて
合計の昇順に並び替えてpairに入れ直せば解けそう

numsが重複する場合があるのでmultimapを使う
multimapはデフォルトでKeyの昇順で並んでいる

run time errorとなるのでここで解法確認
LeetCodeはほとんどpriority_queueを用いたもの

入力値にRTEについて
https://discord.com/channels/1084280443945353267/1183683738635346001/1187118473462173776

時間計算量
o(n) kの大きさに左右される

空間計算量
o(n)

LeetCode計測値
236ms

## ステップ2
multimap生成時に要素数をkになるように設定しているので、vector生成時にkであるかの判断は不要

**今回の場合は、multimapよりpriority_queueを用いた方がいい。**
同じようなことをしているが、multimapの最後の要素を削除する際に時間がかかる
->これは内部的に赤黒木で実装されており、並び直しが発生するため
挿入に関してはそこまで差は無い

参照
https://stackoverflow.com/questions/41807720/c-why-stdmultimap-is-slower-than-stdpriority-queue
https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8

## 他の解法
priority_queueでも実装

時間計算量
o(n log(n)) kの大きさに左右される

空間計算量
o(n) priority_queueもvectorもkの大きさに左右される

LeetCode計測値
234ms

## Discordなど
「あなたは部屋に入りました。数字の一つ書かれた紙を1000枚あります。その中から和が5000になる2枚を見つけてください。」
どう計算する？
https://discord.com/channels/1084280443945353267/1183683738635346001/1187326805015810089

## 分からなかったこと
nums1とnums2の全てをループで回すと要素数が最悪10^10となるからRTE？
以下の制約からRTEになる基準が分からなかった。

Constraints:
1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length

