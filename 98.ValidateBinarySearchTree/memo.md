## ステップ1
rootから順に全探索を行なっていく
  テストケースで分かったこと
  ・親子が同じ値を持っている場合がある
  ・直接の親でなくても左側に大きい数字がいることがある
  ・rootの時点で条件を満たしていないものがある
  途中で、階層ごとに下限値と上限値を設定する必要があることに気づいた
  下限値を常に有効なnode->left->valで上書きしていてハマった
  acceptまで45min

## ステップ2
・変数名変更
  node -> nodes_and_ranges
  step2では変数node内に、nodeとlower_valueとupper_valueを入れていたため
・15~17行目に対するrootの有効性チェックを削除
  ループないで確認しているため

## 他の解法
in-orderで解くことができる
こちらの実装を参考
https://github.com/TORUS0818/leetcode/pull/30/commits/ef97e1246c2213f954eb9337a371dd24ce6cc0c9
https://github.com/Mike0121/LeetCode/pull/8
https://github.com/fhiyo/leetcode/pull/30/commits/052994b11f3e92a38b3636466d3eb4c5fe04a77b
この探索方法は頭に入れておく
書いてみたけど、探索中のnodeに紐づく左右だけとなってしまい
[5,4,6,null,null,3,7]を通すことができなかった。修正してみたがstep2やrecursion.cppのようになった

・再帰でも解くことができる
https://github.com/kazukiii/leetcode/pull/29
  メモリに関しても勉強になりました。
  メモリ量を見積もって再帰でも処理できるのかあらかじめ確認する癖をつける
  recursion.cppに実装


