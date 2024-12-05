## ステップ1
こちらの考え方を参考に実装。step1.cppの中にコメントとして考えたこと記載しました。
https://github.com/Yoshiki-Iwasa/Arai60/pull/35#discussion_r1699552857

acceptまで50分ほど、手探りで条件を探してしまっている
時間計算量O(log n)
空間計算量O(1)

## ステップ2
・回転の起点(pivot)を探してからバイナリーサーチをするパターンも実装してみる
find_pivot.cpp
sort済みの部分を切り出してからバイナリーサーチをするので理解しやすい

・step1に対してどう改善すべきか正直わからなかった
pivotを探してからそこに対して、バイナリーサーチを行う二段構えの方が素直な気がする

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
一度最小値を探して、そこを起点として二分探索を行っている
分けて処理することも可能
https://github.com/Mike0121/LeetCode/pull/45/files/71311eb0967b3475dc0bac2ef3755594d48d486f#diff-109670d539eabff4dad0874fe8c5ac84297f597e1a7b46ffd73de77f1f4c2966
こちらも2段階で解いている
https://github.com/Yoshiki-Iwasa/Arai60/pull/36

>この問題を二分探索風のループ 1 個で解く発想が自分にはありませんでした。ただ、ややヒューリスティック気味で、他の人がソースコードを読むときに骨が折れそうです。各分岐に、どのような条件のときに、どのような理由で、どのようなことをするのか、コメントを書いておくと良いかもしれません。
こういったコメントがあることからも分けた方が素直そう
https://github.com/sakupan102/arai60-practice/pull/44
https://github.com/sakzk/leetcode/pull/7/files

Keyを使う方法
priorityがbisect_leftに対して動作用するのかわかっていない、二週目でじっくり考える
https://discord.com/channels/1084280443945353267/1233295449985650688/1239594872697262121
https://github.com/fhiyo/leetcode/pull/44
https://github.com/Yoshiki-Iwasa/Arai60/pull/36#discussion_r1704471895

## Discordなど

