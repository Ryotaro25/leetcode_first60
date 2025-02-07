## ステップ1
愚直にステップごとにrowを生成する方法で実装した。
これだと内側のループの処理数が2^n-1だけ増えるのでTLEとなってします。
step1_ng.cpp

計算量を減らす方法がわからなかったのでここでleetcodeのdiscussionを確認する。
ステップごとにどのような構造になっているのかビジュアル化されていてわかりやすい。
1. 0
2. 0 1
3. 01 10
4. 0110 1001
5. 01101001 10010110
下記のようなルールとなっている。
・真ん中で割った左側は、一つ前のステップと一致する
・真ん中で割った左右はそれぞれビット反転させたものとなっている

これらを利用して、毎回rowを作ることなくターゲットを見つけることができる。
n 5でk = 9が条件だとする。右側だけ探索できるように分割する
i. 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16
5. 0 1 1 0 1 0 0 1  1 0  0  1  0  1  1  0
↓
i. 1 2 3 4 5 6 7 8  1 2 3 4 5 6 7 8
5. 0 1 1 0 1 0 0 1  1 0 0 1 0 1 1 0
インデックスは、k - (今いるrowのサイズの半分)で求めることができる。
左側を、反転刺されば右側のビットを求めることができるので再帰で実装する。

## ステップ2
・認知不可の低いループでも解いてみる
  loop.cpp
  step1.cpp(再帰)と異なりbitはrowの1番上から、インデックスは1番下から進むので違和感を感じる

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
iwasaさんもおっしゃっている通りstep2の再帰がわかりやすい。
sizeよりlengthの方が適切そうなので自分の変数名も変更
https://github.com/Yoshiki-Iwasa/Arai60/pull/39/commits/1b795bb44a2f0d976d1feb07dc8db732c036fa34

法則から解くこともできる
leetcodeに解説が載っていたがあまり理解できなかった
https://github.com/fhiyo/leetcode/pull/47/commits/0ea02d4ed10cb50e9801ce09e721215ac3a4393e
c++のpopcount
https://cpprefjp.github.io/reference/bit/popcount.html

>n == 1 より k == 1 の方が速い
~~nを使うとO(n)となってkだと常に半分だけ探索すのでO(log n)になるからか。~~
常にnの数だけ、行を作る必要があるので計算量としては変わらない。
https://github.com/goto-untrapped/Arai60/pull/26/commits/becc7ca1a17b5e53a721fd051cb8443d614afd9b
https://github.com/Mike0121/LeetCode/pull/18/commits/65a2b703a054a7b4c204211079a1c053d19c37cf

ボトムアップでツリーのような構造を用いている方法
紙に処理を書いてみてやっと理解できたが、思いつけなさそう。。。
https://github.com/SuperHotDogCat/coding-interview/pull/26/files

