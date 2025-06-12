## ステップ1
inorderもしくはpreorderの要素を一方のKeyとして
インデックスを取得することで何かできないか。。。
preorderの最初の3つの要素がrootとその左右になるのか

15分考えて分からなかったので、答えを見ないでそれぞれpreorderとinorderはどういったものなのか確認
preorder traversal
https://www.geeksforgeeks.org/preorder-traversal-of-binary-tree/
inorder traversal
https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/

ここで再挑戦
15分考えて分からなかったので回答確認
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/5632202/video-2-solutions-with-o-n-2-and-o-n-time/
preorderの要素からinorderのindexを取得して、そのindexの左側が左のnodeに右側が右のnodeに紐づく
これはinorderが常に左側を優先してトラバースするため

時間計算量
O(n^2)
eraseとindexを探すforループの部分でそれぞれO(n)
上記を要素の数だけ再帰的にn回呼び出すため

空間計算量
O(n^2)
左右それぞれのvectorを呼び出す部分がO(n)
上記を要素の数だけ再帰的にn回呼び出すため

## ステップ2
・イテレーターの定義方法変更
  forループでindexを見つけてからiteratorに変換していたがfind関数が存在していた


## 他の解法
hash_mapを用いた解法もある
https://github.com/Mike0121/LeetCode/pull/12/commits/d4ccd11c98bbb8982422a7588dee7fddcb062ff7?short_path=37c38ad#diff-37c38adee77a00d4840ea0049203ac45f60966aa4ad1c8b6d80b1dc78d6def37
step2に似ているが、vectorを再帰的に呼び出すのではなく
index(int)をを渡して再帰を行うので処理が軽い

hash_mapでなくともmapでも可能

## Discordや他のPRなど
・自分の解法と違ってpreorder側も新たに作成している
　自分のは破壊的変更を行なっているので元のpreorderは使えない
　preorder側をindex渡して管理
  step4.cppに実装
https://github.com/TORUS0818/leetcode/pull/31/commits/24492ff4388f596583de9dbf504f7a010a554fc7
https://github.com/kazukiii/leetcode/pull/30#discussion_r1685735022
https://github.com/Yoshiki-Iwasa/Arai60/pull/33
