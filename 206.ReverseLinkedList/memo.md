## ステップ1
順番にStackに入れていけば解けそうだと思った。
他にはmap等に入れて逆順に並び替えてから新しくnodeを作れば解けそうだと思った。

これは10分以内に解くことができた。
時間計算量
O(n)

空間計算量
O(1)

## ステップ2
stackを使って解いているものを調べた
https://leetcode.com/problems/reverse-linked-list/solutions/4907174/easiest-c-solution-beginner-s-approach-beats-100-0ms/
この解法では、元々のheadの末尾から逆順を繋げているが、感覚的に新しく作ったいいと感じた。
これは元のnodeを使ったほうが良いのか分からなかった。

stackの型をListNod*にすることで少し短く書けるが、
AddressSanitizerのheap-use-after-freeエラーに注意
new演算子を使えばコンストラクターによって次のnodeにnullptrを設定してくれる。

## 他の解法
他には、再帰や特別な構造を使わないでポインタの付け替えだけでの対応などがあった。

# 再帰やスタックを使わずにポインタの付け替え
https://leetcode.com/problems/reverse-linked-list/solutions/4903834/easy-solution-optimal-solution-c-java-python3-kotlin/
iterative.cppで実装
現在のノードの次のものを、前のノードに付け替える部分など直感的に読み取りにくいと感じた。
時間計算量
O(n)

空間計算量
O(1)

## Discordなど
https://github.com/TORUS0818/leetcode/pull/9
