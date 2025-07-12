## ステップ1
問題を理解するのに10分弱かかった
必要な処理を書き出してみる
・endWordがそもそもwordList内に存在しているのか
・一文字ずつ入れ替えて探索できるような関数
　DFSを使えば解けそう
・上記を走らせるたびに回数を記録すること

acceptされるケースとされないケースが出てきてわからなかったので答え確認
どこまで深く潜っているのか階層を記録する必要がある
元々の実装では、queueに追加するたびにインクリメントをしており同階層を探索する場合にも
カウントを増やしていたので答えが多く出る場合があった
ここまで1時間ほど

## ステップ2
変数名の変更と以下の部分を変更
・endWordがそもそもwordList内に存在しているのか確認している部分を削除
  最終的に作成した関数内では候補がない場合はインクリメントされないのでわざわざ必要ない

・関数内のtransformation_countを削除
　単に深さを返せばいいので、該当する単語に辿り着いた時の深さをリターン
　たどりつかなった場合は0を返す。

・構造体の命名変更
　ルールがあるのか知らないので調べてみた
  The names of all types — classes, structs, type aliases, enums, and type template parameters — have the same naming convention. Type names should start with a capital letter and have a capital letter for each new word. 
  https://google.github.io/styleguide/cppguide.html#Type_Names
   
  pairやtuppleではなく構造体を使う
  以前指摘あったけど、自分で調べていなかったのでgoogle guideを確認
  Prefer to use a struct instead of a pair or a tuple whenever the elements can have meaningful names.
  確かにfirst、secondより名前が付いている方が読みやすい

## 他の解法
隣接リストを作る方法
https://github.com/hayashi-ay/leetcode/pull/42#discussion_r1515819206
https://github.com/TORUS0818/leetcode/pull/22
隣接リストとは
https://ja.wikipedia.org/wiki/%E9%9A%A3%E6%8E%A5%E3%83%AA%E3%82%B9%E3%83%88

隣接リストのの実行時間など
run time 
506ms
memory
40.5MB

step2の実行時間
run time 
429ms
memory
21.95MB

データの持ち方は異なるけどメイン処理はほぼほぼ同じで上記の差があるので
隣接リストは今回使わない？使いこなせていないだけ？
