## ステップ1
回転されているので身構えたが、中点をとって値で比較していけば解けそう
nums[middle] <= nums[right]がTrueの場合は最小値がleft ~ midのどこか左側に存在している
のでrightの範囲を狭める


## ステップ2
・min_numで最小値を保持するのではなく、nums[left]が最小値となるように変更

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
> 1. 閉区間 ↔︎ a ≤ x ≤ b ↔︎ left = 0, right = len(nums) - 1 
> 以上、以下の範囲で探索を行うため右端を調査対象に含むべき ↔︎ while left <= right
> 2. 半開区間 ↔︎ a ≤ x < b ↔︎ left = 0, right = len(nums)
>    以上、より小さいの範囲で探索を行うため右端を調査対象に含まない ↔︎ while left < right
この違い理解しておく

切れ目を求めることでnums[left]で解を求めることができる
https://github.com/Mike0121/LeetCode/pull/44/commits/2c9ba5788412db1adff6a6b0917760da05e70d7e

>野田さんの話はループや初期値を手癖で書いてないか、意味が分かっているか
完全に形で覚えて書いてしまっている。left
https://github.com/Yoshiki-Iwasa/Arai60/pull/35
野田さんの思考 **step2.cppはこれを意識する**
https://github.com/Yoshiki-Iwasa/Arai60/pull/35#discussion_r1699552857
https://github.com/fhiyo/leetcode/pull/43/commits/5f02850f0a2587bc30f3152fe1e28c5c36482a87

## Discordなど
>二分探索は、コードのパターンで覚えて書くのではなく、探索範囲が閉区間・半開区間・開区間のどれなのかを意識し、範囲を狭めるときに、範囲の端をどこまで狭めればよいかを意識して書くとよい
https://discord.com/channels/1084280443945353267/1230079550923341835/1233971068952121354
https://github.com/YukiMichishita/LeetCode/pull/7#discussion_r1561132164

区間の種類
https://www.optics-words.com/english_for_science/interval.html#:~:text=%E9%96%89%E5%8C%BA%E9%96%93(closed%20interval)%E3%81%A8,open%20interval)%E3%81%A8%E3%81%84%E3%81%84%E3%81%BE%E3%81%99%E3%80%82

>left = 0
>right = len(nums) - 1
>
>と書いたら、left と right の両端を含む、この範囲にある、ということを考えていますね。
>言い換えると、「target はあるとすると、left 以上、right 以下に必ずある」ということです。
この問題の場合見つけたい、最初うちはleft以上right以下に存在するので
left = 0;
right = nums.size() - 1;
でよさそう。
一方で一つ前のSearch Insert Positionの場合は全体の右側に来る可能性もあるのでrightはnums.size()か
https://discord.com/channels/1084280443945353267/1192736784354918470/1199018938005213234
