## ステップ1
0乗の場合、正の数の場合、負の数の場合に分けてとく

nがとても大きい場合にTLE
小手先の修正だと似たような数値のために分岐が増える

x^5 であれば愚直で計算するのではなく(x^2)^2 * x のように工夫する
nが-2147483648の場合、これを正の数に変換しようとするとintで表現できませんとなる

## ステップ2
・long longからlongへ intの最大値を符号変換できるデータサイズの小さいものへ
・冪乗を先に計算して後からマイナス乗なのかどうかの処理
  先にnを絶対値で加工して、冪乗の計算を行う
・ループでの実装に変更

absってこんなに種類があるんや
>In 2's complement systems, the absolute value of the most-negative value is out of range, e.g. for 32-bit 2's complement type int, INT_MIN is -2147483648, but the would-be result 2147483648 is greater than INT_MAX, which is 2147483647.
何度か遭遇したエラーは、公式に書かれているんですねこういった場合は少し余裕を持ったデータ型を用いれば良いか
https://learn.microsoft.com/ja-jp/cpp/c-runtime-library/reference/abs-labs-llabs-abs64?view=msvc-170
https://en.cppreference.com/w/cpp/numeric/math/abs


末尾最適化はc++のコンパイラ？には組み込まれていないようなので
以下は最適化の実装方法実務なら必要であれば組み込むのだろうか
もしくは呼び出しのたびにスタックフレームが生成されるのを避けるため、ループなどを用いるのだろうか
https://speakerdeck.com/shinonome517/cpp-tail-recursion-elimination?slide=12


キャストは何を使えばいいのか
役割が明確ななので可読性を考慮してcスタイルが良さそう
https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast

こちらを参考にビット演算実装
いざという場合に選択肢に出てこなさそう。。。
https://github.com/nittoco/leetcode/pull/17/files

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです**

## 他の解法
>nが負の場合、毎回割り算をするよりも最後に一発だけやったほうが精度が高くでるのでそうする
丸め誤差の影響があるんですね
他にもbit演算やループど解く方法も存在している
https://github.com/Yoshiki-Iwasa/Arai60/pull/38/commits/dcc7edee99cdfffc5307d429db1f567681d1caa7

step2では、再帰の最適化を行う方法を探すなどが良さそう
>同じ処理を書くならループと再帰のどちらが認知負荷が低いかアンケートを取ったところ、ループのほうが認知負荷が低いと答えた人のほうが多かったです
最近は再帰で実装する場面に出くわすけどループの方が安心感がある
https://github.com/fhiyo/leetcode/pull/46/commits/4e5386de9c146a47d21ead8bb604ef99e0ba77e0

nが負の数の場合分けは、冪乗の計算を行う前にするのが良さそう
https://github.com/goto-untrapped/Arai60/pull/29

## Discordなど

