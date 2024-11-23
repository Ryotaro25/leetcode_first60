## ステップ1
地点ごとに何パターンでたどり着くことができるのか記録する方法を思いついた
解答まで約30分

初期化や右端までのパターン数を数える処理の中で障害物に出くわせば記録を0で塗り替えた
障害物以降も0となる

時間計算量O(m n)
空間計算量O(m n)

## ステップ2
・初期化のための2つのforループを無くして二重forループの中で条件に応じてステップ数を更新する
  ステップ１よりこちらが好み。
  forループは0始まりの方がすっきりする(実際ステップ1で0スタートで書いてエラー発生させていた)

・i jをx yに変更
  違和感なくi jを使っていたが、row colより明確に伝わりそう
  https://github.com/goto-untrapped/Arai60/pull/33/commits/3508246fa07e5aad5d6792e4e51cae3a7f8314df

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
https://github.com/sakupan102/arai60-practice/pull/35/commits/8406061ebe94cd041af07988b7d5e314d24a1eb5
rowとcolumn(左端と最上部)をそれぞれ初期化するのではなくループの中で更新する
https://github.com/hayashi-ay/leetcode/pull/44/commits/db064e32de32562d92c3f379ae70a3fa83b2e250
https://github.com/nittoco/leetcode/pull/27

一次元でで管理する方法もある(one_loop.cppに実装)そうすれば空間計算量を抑えられる
二次元で管理する方が愚直で理解はしやすいと感じた
https://github.com/Yoshiki-Iwasa/Arai60/pull/49/files

## Discordなど

