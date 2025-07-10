## ステップ1
nums = [1, 2, 3]を手でやるなら下のように書いていく
1 - 2 - 3
  - 3 - 2

2 - 1- 3
  - 3 - 1]

3 - 1- 2
  - 2- 1 
(n!)で解けそうだけど、変動するnumsのサイズに合わせて
どのようにユニークに取り出すのか思いつかない

やっていることは
forループで要素を順番に選びながら、再帰呼び代しで全順列を作る
樹形図をイメージするとルートから始まり再帰関数が呼び出されるごとに子に移動するイメージ

処理の言語化難しい。
時間計算量 O(n * n!)
空間計算量 O(n!)

## ステップ2
step2.cpp   => 自分の回答をブラッシュアップしたもの
step2_2.cpp => Yoshiki-Iwasaのstackを使った解き方を練習したもの
step2_3.cpp => 重複を考慮したもの
step2_4.cpp => fhiyoのcpythonのpermutationの内容を使った解き方を練習したもの

step2.cppで
組み込んだ変更点
・permuted_combinationをpermutationsに変更
・current_numsをpartial_permutationsに変更
　変数名は少し長いが完成途中という意図でつけた
・CreatePermutedCombinationをGeneratePermutationに変更
・if文の条件を変更してネストを一つ浅くした

step2_2.cpp
気になる部分は、clonedを作る部分で毎回コピーが走ること
stack→vectorへの変換など登場人物が多いこと。vectorだけで完結したい

step2_3.cpp
重複がある場合は?どうすべきか？という疑問から
next_permutationの動作を見ていると重複は考慮する必要がありそう
思いついた方法は答えとなるpermutationsに入れる前に、
対象の組み合わせが存在するのかチェックして入れる方法
これだとO(n! * n!)となる
思いつかなかったのでChatGPTで確認。
usedの処理が分からなくて1時間ほどchatGPTと対話した。
順列を生成する中で、ある数字を選んでその順列に加えた後、
次にその数字をもう一度選ぼうとすると同じ順列が再度生成される

# step1が終わって疑問に思ったこと
・問題の制約上サイズ６が上限だがこれが、10であっらい100とかならどの様に解くのか？

  ツリーを使う
  https://www.reddit.com/r/learnpython/comments/9uf3uf/help_with_generating_a_large_set_of_permutations/

  heapを使う
  https://www.quora.com/What-is-the-most-efficient-algorithm-to-generate-permutations-of-n-distinct-elements
　他にも色々ありそう

・find(current_nums.begin(), current_nums.end(), num) == current_nums.end()を
  setやmapのようにcurrent_nums.contains(num) と出来ないか？
  => countを使って処理もできるが微妙

・そもそもC++にpermutation関数は存在するのか？
  => next_permutationが存在する
  true/falseを返却するのと内部操作の２つを行う関数
  関数＝処理結果1つ見たいなイメージがあったので新しい
  next_permutation.cppで使用
  https://en.cppreference.com/w/cpp/algorithm/next_permutation

一見単純な問題だったけど、考慮すべきことがかなりあった
PR出すまでにここ最近で1番時間をかけたと思う

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
stackを用いることで再帰で行っていたことを避けることができる。なるほどです。
余談ですが、Yoshiki-Iwasaさんのいろんな方法を試して理解する姿勢は見習わないとと思いました。素敵です。
https://github.com/Yoshiki-Iwasa/Arai60/pull/55/commits/b85fd4fa1c380125b3aa94e10fefd691abfc330e

>cpythonのpermutationの内容を思い出しながら書いた。
普段から内部実装もちゃんと確認しないとですね。凄いです。
理解するために見ながらstep2_4.cppに実装。正直処理を追いきれていないです。
https://github.com/fhiyo/leetcode/pull/50/commits/f1aba64cb79bd67af0f253324fda25623093a10e

indexで管理する方法もある
問題がvector<vector<string>>とかだったらこちらのようにintで管理する良さそう
https://github.com/fhiyo/leetcode/pull/50/commits/f1aba64cb79bd67af0f253324fda25623093a10e

swapを用いてnext permutationを管理する方法
https://github.com/nittoco/leetcode/pull/21/commits/26d7f6f621b73055fe2e6243cf9436b5f0464190

>入れ替えを複数行えば良いことに気がついたが、本番解けるかはかなり微妙。
いろんな解法を試してみてtackか再帰で管理するのが最もしっくりきました。
https://github.com/Mike0121/LeetCode/pull/14/commits/6eff8213ad65234355de3e42e10cf78d72a39ddd

## Discordなど
