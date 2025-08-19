## ステップ1
よく形成されたって何かを先に言語化するのが良さそう
OKパターン　例より
"((()))","(()())","(())()","()(())","()()()"
オープンはクローズより前に登場する必要がある
最終的にはオープン括弧の数 = クローズ括弧の数

括弧のオープン側とクローズ側の数で'('か')'を増やすのか考える。
オープン側とクローズ側を使用した数の合計が、与えられたnに一致すれば括弧の1パターンとして回答に追加する。

オープン側の数がnより少ない間は'('を追加することができる。
')'を追加するタイミングがよくわからないので回答を見る
https://leetcode.com/problems/generate-parentheses/solutions/6048157/video-increase-number-of-open-parentheses-until-we-reach-n-at-first/

なるほど、形成途中のオープン括弧の数 > クローズの括弧の数　が見えていなかった。。。
NG　
()))((
要件をよく理解する力を付けないと。。。

parenthesesやparenthesisはただでさえ長いのでprefixをつけると
コードがとても長くなるので命名がしっくりこない

## ステップ2
・formed_parenthesesの命名をparenthesisに変更
  単純に単数の括弧で伝わりそう

・num_open == num_close && num_open + num_close == num_parenthesis * 2
　をnum_open + num_close == num_parenthesis * 2だけに変更
  openはparenthesisより少なくないと追加できない
  closeはopen以下でないと追加できない
  closeの数 > openの数にはならない

memo.cppを実装(nittocoさんの回答を参照)

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
オープン側とクローズ側の括弧の数の数え方(nから引いていくのか、0から数え上げるのか)の違いだけそう
https://leetcode.com/problems/generate-parentheses/solutions/3290261/i-bet-you-will-understand-intutive-solution-beginner-friendly-c/


・Pythonだとyieldが使える。同ジャンルの他の問題でも皆さん使っている
・自分のやり方だとformed_parentheses + '('のように毎回stringのコピーを発生させている
　nittocoさんのように配列に入れて管理のが良さそう
・トータルの括弧の数を変数で置いてあげたほうが意図として伝わりやすいが、一度しか使わないので不要な気もする
・PythonのGeneratorってすごくよしなに動いてくれる
  https://zenn.dev/nakurei/articles/understanding-python-generators
・メモ(キャッシュ)しながら解く方法もある
https://github.com/nittoco/leetcode/pull/43/commits/e373af0cefa8ca2b5b73a4fb901666bd0880c8bd


・カタラン数という言葉を初めて聞いた
  まさに今回の問題のような() を正しく並べる方法など
  https://ja.wikipedia.org/wiki/%E3%82%AB%E3%82%BF%E3%83%A9%E3%83%B3%E6%95%B0
  >計算量はあくまでも極限での振る舞いなので、計算量を使って計算時間を見積もるのが大事です。
  概念を考えるとそうだけど見落としがちな気がします。
https://github.com/frinfo702/software-engineering-association/pull/10

>時間計算量: O(n * 2^(2n)) (文字列の任意の位置で開き括弧/閉じ括弧が許される仮定の甘い見積もり。厳密には n x カタラン数でO(4^n/(sqrt(n)))？ (ref: https://en.wikipedia.org/wiki/Catalan_number))
カタラン数：C_n = (2n)!/(n + 1)!n! これが4^n / n^(3/2)sqrt(pi)でオーダーを用いるので省略されて最終的にO(4^n / sqrt(n))になるのか
・parenという省略形は自分も初めて聞きました。
  調べるとそここ歴史があって、書籍などでも用いられているらしい
  https://english.stackexchange.com/questions/567443/questions-about-history-and-usage-of-the-word-paren
  早速使ってみました。
  
・pythonを知らないからなのかyieldの部分でコードを読むのが詰まる
  コメントにもある通りyieldというよりは1行内にいろんなことをしているからか
https://github.com/fhiyo/leetcode/pull/53/commits/d11f0d8f7c71a4cbd5b26e6e83e7fdfb9c2c381c

・leftやrightよりopen closeの方が自分はしっくりきます
https://github.com/wf9a5m75/leetcode3/pull/2
## Discorなど

