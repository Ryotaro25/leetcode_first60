## ステップ1
プログラムを使わないならどう処理するか考えてみた
文字列を渡された場合に前から見ていき、文字＋登場回数の記録をする
既出のものは登場回数を足していく

文字列を再度見ていき、記録していた文字の登場回数が1回のものに出会った時点で
今いる場所(index)を返却

今回は上記の方法で一発でacceptされた。（初めて？かも）
時間計算量
mapへの挿入に対してh、平均はO(log n)ワーストはO(n)なので
O(n^2)
↑認識合っているか自信ないです・

空間計算量は
O(n)

## ステップ2
一つ目のループで毎回コピーは必要ないのでautoの部分をauto&に変更。

## 他の解法
アルファベット分の入れ物を用意する方法
https://github.com/hayashi-ay/leetcode/pull/28/commits/77d8e91c2c36a4aede152b4ce1cbda65ed94b6fd

方針は同じ
変数名が型名となっているのが気になったけど、PythonにはChar型がなかった
for char in s:
https://github.com/sakupan102/arai60-practice/pull/16/commits/9bac37a73619050a67fdad2c29576362bc393b6c

## Discordなど
Pythonだとアルファベットに対するdictやlistを用意してカウントする方法が存在する
https://discord.com/channels/1084280443945353267/1233603535862628432/1237973103670198292
vectorで実装してみる。

この場合
時間はO(n)
空間はO(1)

## step4
参照について
https://en.cppreference.com/w/cpp/language/reference
参照のQA
https://isocpp.org/wiki/faq/references