## ステップ1
思いついたのは愚直にループを回しながら頭からみていく方法と
頭から1歩ずつ進んでいき、地点ごとの最大距離をメモ化する

メモ化のロジックを、形で覚えてしまっている感がある
15分ほどでaccept

時間計算量
O(n^2)

空間計算量
O(n)

## ステップ2
・メモ化のvectorの名前をmemoizationから変更

## 他の解法
binary_searchでも解くことができる
https://github.com/Yoshiki-Iwasa/Arai60/pull/46/commits/56e8cf4d4efc42c5784108191d1e5fc615de9206

こちらも二分探索
他にもBitとセグメント木というものがある(名前を聞いたことがあるようなないような。。。)
ぱっと見「アルゴリズムイントロダクション」に載っていない？
https://github.com/fhiyo/leetcode/pull/32/commits/4ddb934198ff85e6349b064edea5fe312bd27b9c

基本方針はみなさんメモ化かな、二分探索もできた方がいいか
https://github.com/SuperHotDogCat/coding-interview/pull/28/commits/b81e3d1929c84abea2f00ef3b20b5a34b79eec38
https://github.com/sakupan102/arai60-practice/pull/32

マジックナンバーについて
> 入力の制約を守らない入力を入れると、理解できない振る舞いをするんですよね。
> 数年間使うコードならば、そういうことは間違いなく起きますよね。
制約値よりは、std::numeric_limits::min()とstd::numeric_limits::max()を使うか
https://github.com/Exzrgs/LeetCode/pull/18

## 二分探索
binary_search.cppに実装
numsの中の最小値に出会うたびに先頭から入れ替えが走る
入れ替え後から大きな数が現れると要素が後ろに追加される

https://en.cppreference.com/w/cpp/algorithm/lower_bound
時間計算量
O(n log n)
要素数がnでそのループ内のlower_boundがlog n

空間計算量
O(n)

メモ：下記のケースを使うと理解しやすい
{10, 9, 2, 5, 3, 7, 101, 18, 1, 2, 3, 4, 5, 6, 7, 8}


