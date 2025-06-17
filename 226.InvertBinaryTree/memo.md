## ステップ1
queueを使って探索し、探索中のnodeの子供をswapしていば解けそう
root = [4,2,7,1,3,6,9]で試してみる
queueに左右の順にqueueに入れることで4,2,7,1,3,6,9の順に探索できる

* node = 探索中のnode

node = 4
root = [4,7,2,6,9,1,3]

node = 2
root = [4,7,2,6,9,3,1]

node = 7
root = [4,7,2,9,6,3,1]
大丈夫そう

片側がない場合を考える
[1,2]
nullptrかどうかの判定はしないで、いれかえる
[1, null, 2]

acceptまで15分ほど
再帰でも同じことができそう

時間計算量 O(n)
空間計算量 O(n) 左右のどちらかに偏っていた場合

## ステップ2
左右のnode入れ替え部分にswapを用いる
なんとなく自分で定義していたが必要なさそう
https://en.cppreference.com/w/cpp/utility/swap.html

nullptrの判定位置を変えてみる
今回の場合どちらでも良さそう

* step2_2 
再帰でも解いてみる。
inverted_leftやinverted_rightなどの一旦変数において付け替えいとエラー
=>調べてみると、直接付け替えると
node->left = invertTree(node->right);
ここで元の左側のツリー情報がなくなる。

node->right = invertTree(node->left);
元の左のnodeの情報がなくなっている.
AddressSanitizer: heap-use-after-free on addressなので解放されてしまっているのか

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
基本的な方針は同じ。
queueを使う場合のnullptrかどうかの判断タイミングは、2パターンある。
https://github.com/kzhra/Grind41/pull/6
https://github.com/wf9a5m75/leetcode3/pull/13

>大体の場合、出てきてからチェックでもいいのですが、まれに BFS で(2度入力しているかのチェックを出てきてからすると)急激に遅くなることがあります。
丸覚えてコードを書かないで意識する
https://github.com/huyfififi/coding-challenges/pull/6

root.Left, root.Right = invertTreeRecursive(root.Right), invertTreeRecursive(root.Left)
Pythonだとこの書き方できそうだけど、C++ではサポートされていない
https://github.com/rihib/leetcode/pull/26/commits/2ef461f9770746f0279814fe302af1fe8ef0b35a

## Discorなど
>細かいですが、std は standard library で C++ 誕生とともにあったのに対して、STL は standard template library という std の一部で、SGI (シリコングラフィックス)という会社が作っていたライブラリーが一部取り込まれたものです。
知らんかった。
https://github.com/irohafternoon/LeetCode/pull/8

