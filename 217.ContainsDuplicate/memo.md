## ステップ1
実装前のイメージ
トランプのようなカードをイメージする。
裏向けにシャッフルに並べられた山札があるとして一枚引くごとに表に向けて並べていく
重複があればその時点で終了。山札がなくなれば重複なし


numsをループで回して、set内に含まれているか確認すれば解けそう
acceptまで1分30秒

mapを使う解法も思いついたが、
すでに存在しているかどうかを判断するだけでいいのでsetを選んだ

時間計算量
O(n)

空間計算量
O(n)

## ステップ2
* step1の変更点
unique_numsはsetということからuniqueであることが分かるので微妙そう
他の方がseenを使っていて良さそうだと思ったのでこちらに変更

* 他の方法がないか考えたが思いつかなかったので解法をみる
sortして前後のnumを比較する
これだと空間計算量をO(n) => O(1)にすることが可能
時間計算量はsortの分O(n log n)となる
sort.cppに実装

入力値は参照渡しなので、sortを直に使うときは破壊的変更となることは覚えておく
<=> コピーコストは掛かるが入力値に影響を与えない選択肢もある

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の解法
setの方が自然ではないかというコメントがあった。実装時にこれはよぎった
https://github.com/shintaroyoshida20/leetcode/pull/32/commits/3c8d72cb432e48abe4f507a246a24bc4303dad74

>return len(nums) != len(set(nums))
この解法も思いつかなかった。setに入れる際に重複があれば確かに長さが異なる
brute forceは見落としていた。
https://github.com/NobukiFukui/Grind75-ProgrammingTraining/pull/39/commits/a2a595caddbcc5b46bab24d18f03356314e7ecd0

自分が思いついたイメージに近い
resultにtrue、falseを持つよりは重複があったタイミングですぐにreturn trueした方が素直な気がする
https://github.com/erutako/leetcode/pull/5/commits/d902e9ffb35d089948576c15f4b93b200e860182

## Discorなど

