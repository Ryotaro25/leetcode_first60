## ステップ1
numsは最初からソートされているのでnumsの真ん中をnodeの値として作る
真ん中で配列を2つに分けて、真ん中をnodeの値として再帰的に呼び出して親Nodeに紐付ける
この問題を読んですぐに思いついたのは再帰で解く方法
15分ほど

時間計算量O(n)
~~空間計算量O(n)~~
空間計算量O(log n)
n/2, n/4, n/8...となるため

## ステップ2
・半開区間に変更
・関数内で値を書き換えないものをconstに変更
  参照にしているがpointerとintはそこまでコストは高くない
・バイナリーツリーを作る関数からの返却値を変数に入れていたけどそのままreturnへ
制約上、numsが０になることはないので頭に置いている判定はいらないか

・他の方のPRなど
>この問題だとnumsが偶数個のときにmiddleの決め方で作られるBSTの形が変わるのは把握されていますか？
https://github.com/sakupan102/arai60-practice/pull/25
たとえば例題にあるようにInput: nums = [-10,-3,0,5,9]の場合
区間の取り方[0,-3,9,-10,null,5]や[0,-10,5,null,-3,null,9]になるということかな

>dummyの値を持ったcomplete binary treeを構築して、inorder traversalしながら値をセット
https://github.com/kazukiii/leetcode/pull/25/commits/0f5349d5c358c4e31df7c0d10fd03a926d03d729


>閉区間、半開区間ともに書いている
https://github.com/Mike0121/LeetCode/pull/13/commits/769de902ce428e6864ee23aca762ce6f3f365f63
閉区間、半開区間とは(用語がうまく頭の中に入っていない)
https://scrapbox.io/ganariya-competitive/%E9%96%89%E5%8C%BA%E9%96%93%E3%81%A8%E5%8D%8A%E9%96%8B%E5%8C%BA%E9%96%93
・違いは分かったけどそれぞれどう影響するのは？
閉区で重なっていた部分が探索範囲から除外されて、無駄な探索を減らせること(?)

queueに入れてloopで解く方法もある
↓いつも纏まっていてすごく勉強になる
https://github.com/TORUS0818/leetcode/pull/26/commits/a0076ed7fb3d6c7d5410d4f960c6a997d308d054?short_path=f90af66#diff-f90af665c7c9be35afaf8e105d92ceba0f1c7c14d95fcac6cb0f77d153da311c
こちらを参考にbfsで解いてみる(loop.cpp)

## Discordなど

