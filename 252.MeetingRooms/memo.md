## ステップ1
全ての予定をカレンダーに書き込むイメージでした。
intervalsから各startとendを取り出して、
set内に全ての時間(start ~ end)を入れる。
途中で重複があればfalse、全部突っ込めたらtrue

startもendも24までじゃなく10^4
intervalsの要素数をn
startからendの距離の合計がm　O(m n)かかる
下記みたいにダブリなく続く場合が最も長いのかな？
[1 2] [3 4] [5 6]みたいに続いて、最後の要素が[10^2, 10^6]かな？

効率化は思い浮かばず断念

## ステップ2
なるほどsortして前から見ていって重複があればその時点でfalseなんですね
forループは一度で済むのでコストはsortする部分のみか

intervalsをコピーして使うかどうかは要件次第か
sort.cppに実装

step2での変更点は、for (vector<int>& interval : intervals) から
for (const vector<int>& interval : intervals) へ変更。忘れがちです。

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
・初手がsortの方法
>やはりどちらかというと問題はやりかたを思いつくところにありそうですね。
愚直な方法から改良できる力を付けないとですよね。
・指摘のある通り、startやendを変数として定義するのかコメントがあった方が親切
https://github.com/goto-untrapped/Arai60/pull/60/commits/660c10ca5b1016aee0bea57246e9d4bd085999bd

・こちらの方もsortする方法を最初に浮かべている。
・end_1やstart_2のように数字の意味を考えてしまう。curr_endとnext_startとかにする方が分かりやすそう

>鍵を借りる時間と返す時間をばらばらにソートして、鍵の数が2つ以上でたかを確認という手もありますね。
two_keys.cppに実装
https://github.com/Yoshiki-Iwasa/Arai60/pull/60/commits/9a196986631d3f52dad6e7ea577adb64204af31e

やはりみなさんsortを思いついていますね。
https://github.com/Mike0121/LeetCode/pull/27/commits/7a07ed70331f16dafe236e553add8b7e1849019e
## Discorなど

