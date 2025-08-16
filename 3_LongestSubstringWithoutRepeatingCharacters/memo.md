## ステップ1
まず思いついた方法は総当たりで解く方法。
substringを作るための開始点と終了点の2つのインデックス用意する。
setに一文字ずつ記録し重複があるのかないのか管理。
TLEにはならないが、2つのループで全ての位置を試しているため時間計算量がO(n^2)、空間計算量はO(n)

次にsliding windowで考える。
こちらもsubstringを作るための開始点と終了点の2つのインデックス用意する。
全ての位置を試すのではなく、必要な場合のみインデックスを動かす。

重複がない間は、set内に文字を入れながら終了点を後ろにずらす。
重複があれば開始点の位置を前に進める。またsetから開始点にあった文字を削除する。

## ステップ2
・setの変数名をunique_lettersにしたが、setに対してuniqueは助長か。
  setの中身は重複しないため。

・setからmapへの管理方法に変更
  mapを用いて文字ごとの登場回数を記録する方法ではsetと同じような処理になる。
  この場合setの方がシンプルな構造なのでsetが好み。

  mapには文字ごとのindexを記録する。
  これによりwhileループで開始位置を動かしていた処理をなくすことができる。

・変数名はstartとendよりleftとrightが一般的か

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
基本方針は同じ
https://github.com/katsukii/leetcode/pull/5/commits/7dee757451b863e0166c44d43329c6863b6ac6d9
https://github.com/Yoshiki-Iwasa/Arai60/pull/42

文字コードを使って使って、インデックスを管理する方法
レビューやり取りを見ていると理解できていない箇所がちらほらあるので別途調べる
https://github.com/philip82148/leetcode-arai60/pull/3

自分もsetを使う方が好みでした。
みなさん指摘されている通りindexも管理して、それを使って範囲を狭める方が効率的ですよね。
https://github.com/fhiyo/leetcode/pull/48/commits/77b26c5a02d26112cd7ff94bf4d330afdde8a68a

## Discorなど

