## ステップ1
Permutationの回答から変形したらいけそうだと思った。
Permutationではforループで要素を順番に選びながら、再帰呼び代しで全順列を作った

ここから派生させてsubsetを作る関数にsubsetのサイズを指定することでサイズごとの全subsetを回答に追加する
Permutaionとは異なり、順番違いの同じ要素を除外する必要がある。
なんとか回答できたがGenerateSubsetに対する引数が多い＝追うべきものが多すぎる

## ステップ2
変更点 step2.cpp
・含まれているのか含まれていないかのチェックを削除
　この確認をしなくてもインデックスで管理しているので、重複は発生しない

・subset_sizeと部分subsetの大きさが同じだけというチェックを削除
  再帰呼び出し回数に合わせたおきさになる為不要

Leetcodeの解説より
一つ前の状態に新しい部分集合を足していく方法
cascating.cppに実装
初期      => {} 追加
nums = 1 => {1} 追加
nums = 2 => {2} {1, 2} 追加
nums = 3 => {3} {1, 3} {2, 3} {1, 2, 3}
こちらの方が自分的には理解しやすかった

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の解法
step1の直したコードに対して、includeの役割を追うのに時間がかかった
呼び出してから一連の処理を追って要約理解できたので、コメントがあってもいいかもです
https://github.com/nittoco/leetcode/pull/19/commits/964a4def0273bf53a4442f8b8908f6c4f99e022a

バックトラッキングで解いている
>バックトラックは、要するに、その場所までが固定されたときに、残りをどうやって重複や漏れがないように、分類するかということです。
https://github.com/goto-untrapped/Arai60/pull/39/commits/c8e8ee07bb84ff15a310415a6c5a551d626bd18e

indexを使って、サイズを管理している
自分もstep1の時に行なっていたが、サイズの管理は再帰関数の呼び出し回数に吸収させたい
yieldを何か調べた。一時停止させてまた再開をすると処理を追うのが大変そう。。。
あとC++にはなさそう
https://github.com/fhiyo/leetcode/pull/51/commits/201509ce3b67a697e84ea970c7e9e65b4b2aa00d

https://github.com/Yoshiki-Iwasa/Arai60/pull/56/commits/79711318d8fe43048883ce60f3a35e9dffbcd0ac
## Discorなど

