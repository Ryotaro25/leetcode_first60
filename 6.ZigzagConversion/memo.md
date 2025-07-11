## ステップ1
手作業でするならどうするのか考えてみる
まずnumRows行の方眼紙を用意する。列数はわからないので予め用意しておくか、必要になれば広げる
sから一文字ずつ転記する
・まずは行の1番下まで埋まるように
・次は一文字ずつ行の1番上まで辿り着くように
　この時は一文字転記したら次の列に移動
1番上までたどり着いたらまた行の1番下まで埋まるように文字を転記する
上の作業が終わったら今度は列、行という順で文字を拾って組み合わせる

1人1転記で作業をさせるなら、下記の情報が必要かな。
・下向きに作業をしているのか上むきに作業すしているのかのフラグ
・前の作業者はどこに転記したのか

1 5 9
2468
3 7
3にたどり着いたら、次は上むきと伝える。
5に辿り着いたら、次は下向きと伝える。

numRowsをm、stringの長さをnとすると
時間計算量と空間計算量どちらもO(m n)

## ステップ2
step2.cppでは下記について対応。
・条件分岐が多いので読み辛い
・vector<vector<char>>で必要以上の領域を確保していないか

・条件分岐が多いので読み辛い
　転換する処理を、上方向と下方向に動く処理の中から外だし。
  移動処理が重複していたので切り離し

・vector<vector<char>>で必要以上の領域を確保していないか
  colはs.size()で領域を確保している
  =>leetcodeの解説にミニマムで確保する方法の説明があった。
    上から下まで下がって、また上まで上がる部分を一つのセクションを捉えると
    上から下方向にはnumRows文字
    下から上方向には、numRows - 2文字必要で、1セクションに対してnumRows + (numRows - 2)文字必要
    必要なセクション数は、s.size() / (2numRows - 2)
    各セクションは、numRows - 1列必要なのでs.size() / (2numRows - 2) * (numRows - 1)が最小で必要な数

step2_1.cpp
step2.cppのvector<vector<char>>からvector<string>へ
  Yoshiki-Iwasaさんの回答を参照
  何度か調べた気がするが効率のいいstringの繋げ方を調べてみる

  stringstreamは前に一度使った気がするけど、効率的でないのか。
  >Is std::stringstream any better for this purpose?
  >No, iostreams are notoriously slow (in spite of theoretical possible high speed):
  >you can be reasonably sure that it will be slower than most any alternative, due to flawed locale support.
  https://www.reddit.com/r/cpp_questions/comments/wxiyg1/most_efficient_way_to_concatenate_strings/

  こちらの中でも色々議論されている
  reserveを使って予め必要なメモリを確保しておけば先確保を減らすことができる。
  https://stackoverflow.com/questions/611263/efficient-string-concatenation-in-c

  今回stringの最長は1000文字。numRowsが1000の場合、一文字ずつ繋げる必要がある。
  下記の記事によると、環境にもよるがだいたい初期は32文字まで確保されている。
  https://stackoverflow.com/questions/53216377/how-much-memory-is-allocated-to-an-uninitialized-stdstring-variable
  ~~1000 / 32 ≒ 31なので、31回リアロケーションが発生する。~~
  →これは誤り。領域は確保のたびに倍のサイズになるので、6回発生
  あらかじめreserveで確保しておくと、1度ですむ。

  Mac OS上でテスト
  sは1000文字にしてリアロケーションがどのように発生するのか確認
  capcityの変化 : 22 47 95 191 383 767 1535

  #include <chrono>を用いて実行速度を計測する。
  https://www.rk-k.com/archives/6973
  ・sは1000文字、numRows = 1000
    reserve無し
    処理時間: 0.000161757 秒
    reserveあり
    処理時間: 0.000206844 秒

  ・sは1000文字、numRows = 1000
    reserve無し
    処理時間: 3.6マイクロ 秒
    reserveあり
    処理時間: 3.6マイクロ 秒

  reserveを使うことで、リアロケーションは発生しなくなったが
  1000文字では、実行速度に差が見られなかった。

step2_2.cpp
step2_1.cppで使っていたbool is_downforwardをint directionに置き換え
fhiyoの回答を参考
個人的には、boolで管理した方が理解しやすいと感じた。
row += directionまでいかないとdirectionがどう動作するのか理解できないからか

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**
step2_1.cppを用いる

## 他の方の解法
・確かに、領域確保にいきなり数式が出てくると何をしているのか理解できないので
  コメントで補足があった方が良さそう
・テーブル全部埋める必要はなくて、行ごとに文字列を入れる
  なるほどです。空間計算量を抑えられますね。
https://github.com/Yoshiki-Iwasa/Arai60/pull/65/commits/fba81a9cffadbaf178b3f63871ab2ea644ec790d

>文字列を走査しながら各文字に行番号(ArrayListのindex番号)を振る
>`s = "PAYPALISHIRING"`, `numRows = 3` であれば `01210121012101`
こういう法則に気づけるようになりたい。ここからだとvector<string>での解法を導き出せそう。

・1行でのifや三項演算子を自分は使わないので読むのに少し苦労した。

>Google Style Guide は条件が1行、中身が1行のときだけぶら下がりを許容としています。
>時々、編集を重ねているうちに事故を起こすんですよ。
  こんな視点もあるんですね。
https://github.com/Hurukawa2121/leetcode/pull/5#discussion_r1874549052
https://github.com/katsukii/leetcode/pull/7/commits/53f8587b823e99f591e551ecdfc3315d97b203db

上方向とした方向の処理をboolで管理していたけど、int directionで表す方法がある
これを使ってrowの更新を行う
https://github.com/fhiyo/leetcode/pull/58/commits/8689c74cda55693bdaaeca6721e9c80c9aaacf02#diff-9924eba75ce80cfb26b487ccdaaf7bae5d8affe8661b63382ef4051a602e81f6
## Discorなど

