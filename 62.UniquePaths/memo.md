## ステップ1
問題を見て思いついたのは
(m + n)!/m!n!の公式を使う解法と1マスごとに、ロボットが何パターンで進むことができたのか記録する方法。
今回は後者の方法で行う。右端に辿り着いた時点でのパターン数が解答になる。

時間計算量O(m n)
空間計算量O(m n)

## ステップ2
i jを使うかrow colを使うかは好みの問題か
空間計算量を抑えることはできる

## 参考にした他の方の解法
基本的は方針は同じ
~~数学的な解き方でも解いてみる。C++に階乗やコンビネーションのライブラリはなさそう。~~
数学的な解き方でも解いてみる。C++に階乗やコンビネーションの標準ライブラリはなさそう。
https://github.com/Yoshiki-Iwasa/Arai60/pull/47
combitation.cppに実装
扱う数字の大きさを抑える方法が分からなかったのでChat GPTに相談
combinationの第二引数には可能な限り小さい数値を渡すためにminを用いる
→たまたまLeetCodeのテストケースで通っただけのような気がする

行単位もしくは列単位でパターン数を記録することで空間計算量をO(m) もしくはO(n)に抑えることができる
ただ、コード面接でこれは思いつけそうにない
https://github.com/fhiyo/leetcode/pull/34
step4.cppに実装(写経)

## Discordなど

## 多倍長整数クラス
64bitより長い数値を扱う計算全般を広義の多倍長(multiple precision)計算

https://na-inet.jp/weblog2/2018/03/22/%E3%81%9D%E3%82%82%E3%81%9D%E3%82%82%E3%80%8C%E5%A4%9A%E5%80%8D%E9%95%B7%E3%80%8D%E3%81%A3%E3%81%A6%E3%81%A9%E3%81%86%E3%81%84%E3%81%86%E6%84%8F%E5%91%B3%EF%BC%9F/

https://zenn.dev/herumi/articles/bitint-01-cpp

Boost
https://ja.wikipedia.org/wiki/Boost_C%2B%2B%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA
cpp_int.hpp
https://github.com/boostorg/multiprecision/blob/develop/include/boost/multiprecision/cpp_int.hpp

実装は難しかったので一周してから戻ってくる