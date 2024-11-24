## ステップ1
サークル上になっている記述から少し身構えたが、
・numsの1番後ろを探索に含んだ場合は先頭を含むことができない
・先頭から
nums[0] ~ nums[n -1]とnums[1] ~ nums[n]のそれぞれで最大の場合を求めて
どちらかのMaxを返却すれば解くことができる

acceptまで35分
それぞれ区間ごとの最大値に対する変数名が思い浮かばなかった。

他にはトップダウン方式でも解けそう(トップダウンの方が苦手)

時間計算量O(n)
空間計算量O(1)

## ステップ2
・最大値を求める箇所を関数化
  numsは参照にして、区間をint型で渡す

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の解法
関数化している
区間ごとにnumsのコピーを作って渡している
https://chatgpt.com/c/6706408c-3e2c-800b-b4f0-253cfaadbe94

・トップダウン方式でも実装
  top_down.cpp
  再起よびだしをする箇所で、2つの区間の処理が走るので苦手意識がある

## DiscorやPRなど
参考
みなさん基本ボトムアップ
https://github.com/fhiyo/leetcode/pull/37/commits/5abbc5083b428a9cc6108d6d9f564fe74a58e481
https://github.com/goto-untrapped/Arai60/pull/37/commits/abb682573890d17e720521b3d8356372f4db8c2f
DPで全部値を記録していくのではなく、１つ前と２つ前の値を記録する
https://github.com/Yoshiki-Iwasa/Arai60/pull/51/commits/5047b05d629fd965e1eed052e61fe1e2173ab73d
確かに変数名は難しいと思いました

https://github.com/seal-azarashi/leetcode/pull/34/files/05c7a9d480e29878dee1feafb4f7f46be5685eb9



