## ステップ1
一度解いたことがあり解き方を覚えていた。
左側のインデックスをleft、右側のインデックスをrightとする。
変数sumにleftからright区間の合計値を持たせておいて、
sumがtargetを超える場合はleftを進める。target以下の間はrightを進める。

## ステップ2
左側をループで回す方法がありstep2_2で実装。
右側をループで回す方が直感的な気がする。

累積和で解くことも可能、cumulative_sum.cppで実装
>nums は役割を全うして prefix_sum が代わりに進む準備ができた
>prefix_sum の left, right を使って考える
自分のこの考え方がしっくりきました
https://github.com/Yoshiki-Iwasa/Arai60/pull/43/commits/4423fb7f61bb4507ed7846c0964b0832b5d387de

累積和を作る際にprefixSums[i] = prefixSums[i - 1] + nums[i - 1];を使っている。
ここは好みの問題か
https://github.com/goto-untrapped/Arai60/pull/40

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
leetcodeの解答例でsum += nums[r++];というふうにインクリメントしながらsumに追加する方法があった。
1行に２つの処理を纏めるより分けた方が好み。

Pythonのmath.infは型がfloat。言語が変わるとこの辺りの仕様は理解しておかないとバグに繋がりそう。
右側をループで回す方法で解いたが、左側を回す方法もあり。
余談、cumulative sumを略してcum sumというの知らなかった。。。
https://github.com/fhiyo/leetcode/pull/49

numsに負の値が入ってきたときを考える
→自分のコードだと動かない
  sum -= nums[left];の際に意図しない挙動になる。
https://github.com/goto-untrapped/Arai60/pull/40
https://github.com/Mike0121/LeetCode/pull/22

## Discorなど

