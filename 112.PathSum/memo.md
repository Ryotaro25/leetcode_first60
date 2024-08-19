## ステップ1
dfsや再帰を使えば解くことができる
葉にたどり着くまで通ったNodeの数値を記録し、葉についたタイミングでtargetSumと比較する
4:37でaccept

## ステップ2
・rootがnullptrかどうか判定するのではなく、一旦queueに突っ込んでループ内で確認するように変更
・sumを足してからqueueに入れるのではなく、ループ内の処理で足すように変更
  queueに入れる前の左右のNodeがnullptrかどうかの判定が入らなくなる

## 他の解法
recursion.cppにて再帰を実装
こちらはtargetSumからNodeのvalを引いていく方式
右側や左側のみにnodeが紐づくことを考慮して
時間計算量O(n)
空間計算量O(n)

return self.hasPathSum(root.left, targetSum - rootl.val) or self.hasPathSum(root.right, targetSum - root.val)のようにも書くことができる
https://github.com/kazukiii/leetcode/pull/26#pullrequestreview-2176578846
recursion_step2.cppにて実装
自分で書いた時と処理している内容は同じだがこちらの方がifを分けていない分シンプルに書ける

## Discordや他の方のPRなど
backtrackingで途中で戻りながらSUMを計算する方法がある
この発想はなかった。
他の方から指摘があるように、targetSumに合致するようなパスがいくつあるか数えるような問題なら良さそう
https://github.com/nittoco/leetcode/pull/31/commits/022ee4f0b76c3d6bb9514f949e85df2ecb625234#diff-b4b5f9e02019847ced4bcdf2e9c797122a98fdca815f1def17c05e23c0d8f21a

処理の最初にrootがfalseかどうか判定するのではなく、ループの最初に処理すほうがスッキリかける
https://github.com/TORUS0818/leetcode/pull/27/commits/a4d245c85ca122ad8c2b11cc2b74e94829408bd0

targetSumから引いていく方が多い
再帰は引く方式で解いてみる
https://github.com/TORUS0818/leetcode/pull/27/commits/a4d245c85ca122ad8c2b11cc2b74e94829408bd0