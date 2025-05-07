## ステップ1
制約にO(log n)とあったので思いついたのは、~~バイナリーサーチツリー~~を用いた
※指摘があったため訂正(木構造は使っていない)

探索した結果端に辿り着いた場合の処理に時間がかかった
acceptまで34分
制約がなければforループO(n)で実装していた

時間計算量
O (log n)
空間計算量
O(1)

## ステップ2
elseを使った方がスッキリしそう
・forループバージョンでも念の為書いてみた。すごくシンプルに書けるしLeetCode上でもacceptされた
・whileループバージョンでも書いてみた。

命名について
start endが個人的にしっくりきているが、right leftとどっちがいいのだろう
調べていたhighとlowも出てきた。middleを使うならこれが英語的にしっくりきそう。

left < right VS left <= rightはどちらも間違いではない
要素数が偶数の場合、前者は2つの真ん中の左側、後者は右側がmiddleとなる
>From a readability perspective, it might be slightly better (in my opinion) to use the exclusive one in languages with 0-based arrays and either one in languages with 1-based arrays, in order to minimise the number of -1's in the code. An argument could also be made to just stick to a single version in all languages, as to not require that people understand both versions or get confused between the two.
チーム間で決めておくことなのかな。
https://stackoverflow.com/questions/44231413/binary-search-using-start-end-vs-using-start-end

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
自分は再帰で書いたけど、わざわざ再帰を使わずwhileで処理可能
https://github.com/Mike0121/LeetCode/pull/43

>CPU 周りでぱっと目に付いた単語はこんな感じなのですが、
パイプライン
スーパースカラー
マイクロアーキテクチャ
命令セット
マイクロコード
レジスタ
実行ユニット
キャッシュメモリ
アウトオブオーダー
マルチコア
同時マルチスレッディング
スループット
常識の範囲のようなので要チェック
https://github.com/Yoshiki-Iwasa/Arai60/pull/34

>課題の制約でnums contains distinct values sorted in ascending order.とあるので問題ないですが、たとえばnums = [3, 3, 3, 3], target = 3の場合とかの答えが違うくないですか？
middleを使わないforループの探索だとこの左端が回答となってしまう。。。ので今回はたまたまacceptされただけか

>条件を満たすものを1つ探している場合、
>条件を満たすもののうち左端を探している場合、
>条件を満たすところと満たさないところの切れ目を探している場合(上とほぼ同じ)、
>あと、閉区間か、開閉区間か、などがあって、これは、「条件を満たすもののうち左端を探している場合に満たすものを1つ見つかったら中止するコードがついた」
この辺りの目線はなかった。
今回はたまたまnumsがユニークであったので問題が無かったが実際は要件定義必須
https://github.com/fhiyo/leetcode/pull/42
https://github.com/sakupan102/arai60-practice/pull/42

## Discordなど

middleについれleet codeの解説より
>If left + right is greater than the maximum int value 2^31 −1, it overflows to a negative value. In Java, it would trigger an exception of ArrayIndexOutOfBoundsException, and in C++ it causes an illegal write, which leads to memory corruption and unpredictable results.

## step4.cpp
### 閉区間 [start, end]
* 探索空間、初期値の設定
start = 0、end = nums.size() - 1

* ループ終了条件
start == end

* 更新操作
nums[middle] < targetがtrueの場合[middle + 1, end]
nums[middle] < targetがfalseの場合[start, middle]

## 半開区間 [start, end) or (start, end]
[start, end)でstep5.cppに実装
* 探索空間、初期値の設定
start = 0, end = nums.size()

* ループ終了条件
start >= end

* 更新操作
nums[middle] < targetがtrueの場合[middle + 1, end]
nums[middle] < targetがfalseの場合[start, middle]
形で覚えるのではなく、下記の考え方を理解する
https://github.com/Yoshiki-Iwasa/Arai60/pull/35/commits/f279dd98a68111954a02344b20b47512ebffafc4#r1699552857


>二分探索を、 [false, false, false, ..., false, true, true, ture, ..., true] と並んだ配列があったとき、 false と true の境界の位置を求める問題、または一番左の true の位置を求める問題と捉えているか？
>位置を求めるにあたり、答えが含まれる範囲を狭めていく問題と捉えているか？
>範囲を考えるにあたり、閉区間・開区間・半開区間の違いを理解できているか？
>用いた区間の種類に対し、適切な初期値を、理由を理解したうえで、設定できるか？
>用いた区間の種類に対し、適切なループ不変条件を、理由を理解したうえで、設定できるか？
>用いた区間の種類に対し、範囲を狭めるためのロジックを、理由を理解したうえで、適切に記述できるか？
https://discord.com/channels/1084280443945353267/1196498607977799853/1269532028819476562
