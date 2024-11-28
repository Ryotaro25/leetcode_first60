## ステップ1
与えられた文字列を分割しながら、wordDict内に存在するのかチェックする
wordDictはvectorからsetに入れ直してcontainsを使いたい

ある地点で分割して、その地点から左側と右側に分ける
左側が辞書内に存在していれば右側をチェック。
右側に対して、ある地点で分割をして左側と右側に分け上記の作業をくりかえる

時間計算量O(n^2) <-自信ないので間違っていたら指摘お願いいたします
contains関数の計算量はlog n
再帰とforループ部分はn(n+1) / 2で省略するとn^2

空間計算量
O(n)

## ステップ2
・substr() によって string のコピーが作られるのを避ける
string_viewが使えそう。string_viewのsubstrの計算量はO(1)
https://www.modernescpp.com/index.php/c-17-avoid-copying-with-std-string-view/
https://en.cppreference.com/w/cpp/string/basic_string_view

早いからといって毎回string_viewを使うのではなく破壊的(恒久的)な変更を行いたい場合はstringを使う
今回は単にwordDict内に存在するかチェックしたいだけなのでコピーの発生しないstring_viewを使う
https://medium.com/@chittaranjansethi/exploring-the-differences-std-string-vs-std-string-view-d1c7015162f0

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
Auxって言葉知らなかった　Auxiliary(補助)
https://github.com/philip82148/leetcode-arai60/pull/8
こちらの方は深さ優先探索を用いている。
幅優先探索で解くことができる。またTrieというものがある
https://github.com/Yoshiki-Iwasa/Arai60/pull/67/commits/3bd8c415249792da181d1351a108f3208c62ffce
https://github.com/fhiyo/leetcode/pull/40
https://github.com/sakupan102/arai60-practice/pull/40
https://github.com/SuperHotDogCat/coding-interview/pull/23

## 他の解法など
幅優先探索をbfs.cppに実装
startとendの文字を分割する情報を持っておく。
開始位置を0から初めて終了地点を動かしながら探索を行う。分割できる点があれば、それを次の開始位置として同様に探索する

深さ優先探索をdfs.cppに実装
starts_withがc++のstring_viewにも存在していた

Trieはtrie.cppに実装(写経)
Trie
https://en.wikipedia.org/wiki/Trie

Trieの練習問題は下記(どこかでやってみる)
https://leetcode.com/problems/implement-trie-prefix-tree/editorial/

