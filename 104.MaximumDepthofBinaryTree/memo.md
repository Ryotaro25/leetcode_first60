## ステップ1
階層が深くなるごとに数値を足していって、再帰でnullptrになるまで潜れば解けそう
関数化したけどこの長さなら関数化する必要ないかもだけど
もっと複雑化することを想定して今回は分けてみた

時間計算量
深さに影響され、全て左に紐づく場合を考慮してO(n)

空間計算量
O(n)

## ステップ2
rootがnullptrとなっている場合を考慮してstep2で追加

return 1+max(maxDepth(root->left),maxDepth(root->right));のようにも書けるが
若干可読性が下がると感じた。
https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/3192154/cpp-solve-easy-solve/

## 他の解法
・BFSを使っても解くことができる　bfs.cppに実装
structで深さとnodeを持つ構造を定義
命名ルールは下記参照
https://google.github.io/styleguide/cppguide.html#Type_Names

参考にした回答
同階層をforループで回すよりは、階層ごとの深さをもつ方が良さそう
https://github.com/rossy0213/leetcode/pull/10/commits/827bf9f2ed20d4c647561fe9a0d73b761d04564e

popしてからnodeを確認する方法がある。
https://github.com/NobukiFukui/Grind75-ProgrammingTraining/pull/38
これをすることで左と右それぞれ確認してからqueueに追加する必要がなくなり
シンプルに書くことができる

・「この環境では大丈夫」なコードは可能ならば避ける
https://github.com/kazukiii/leetcode/pull/22/commits/f2d8eedba1e98a8da5c97093224cca35326e7cca#diff-e6fac96b6faeb56aacc2da73ab20276cbd0c1c118797522d3a88bd5d271b384c

https://github.com/rossy0213/leetcode/pull/10/commits/827bf9f2ed20d4c647561fe9a0d73b761d04564e

## Discorなど

