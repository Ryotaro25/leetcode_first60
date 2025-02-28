## ステップ1
最大の重量から1ずつサイズを上げて、daysを満たすことが出来るのか愚直に見ていう方法をまず思いついた。これだとTLEになる。
次にバイナリーサーチを用いる方法を思いついた。これは類似問題を解いていたため解法を思いついた。

1.問題のモデル化
1番重いパッケージの重量から各パッケージの重量の合計までの範囲を
capacity_of_the_ship = [max_weight, . . . , sum_weight]とする。

days以内に運ぶことが出来る場合はtrue、できない場合はfalseとする。
 weights = [1,2,3,1,1], days = 4
capacity_of_the_ship = [3, 4, 5, 6, 7, 8], days = 4　を用いると
capacity_of_the_ship = [false, true, true, true]と表すことができる。
この中で一番左のtrueの位置を探す。

2.探索空間の定義
~~半開区間として探索を行う。~~
leftを探索範囲の最小index、rightを探索範囲の最大indexとして
閉区間として考える

3.初期値の設定
leftをmax_weight、rightをsum_weightとする。

4.ループ不変条件の設定
~~left < right、[left, right)に解が含まれている。~~
閉区間 [left, right] にdays以内に運ぶことが出来る最小のキャパシティが含まれる

5.探索ロジックの設計
leftとrightの真ん中をmiddleと置く。
capacity_of_the_ship[middle]がdays以内に運ぶことができない場合、
middleおよびその左側にdays以内に運ぶことのできる船の容量は、
存在しないためleftをmiddle + 1に更新する。

capacity_of_the_ship[middle]がdays以内に運ぶことが出来る場合、
middleを区間内に含めるため、right = mid とし区間を狭める。

6.検証
・daysがcapacity_of_the_shipのいずれよりも小さい場合
  そのため、leftは初期位置のままrightが狭まり、1番重いパッケージの重量が解となる。

・daysがweightsの合計sum_weightよりも大きい場合
  rightはleftに近づきこちらもleftは初期位置のままrightが狭まり、1番重いパッケージの重量が解となる。

・daysに該当するsum_weightが複数存在する場合
  今回の問題だとあり得ない

・daysに対応するcapacity_of_the_shipのいずれかの値で実現可能な場合
  二分探索により最小の容量を返却する

7.実行
leet codeにて動作確認

## ステップ2
・変数名を変更
  left, right をmin_capacity,max_capacityへ変更。
  max_weight(最大重量)〜total_weight(総重量)を使っている方もいる。
  個人的には最小積載量~最大積載量の方が分かりやすいと思った。

・weightsのsumの取り方をforループからaccumulateに変更。
  https://en.cppreference.com/w/cpp/algorithm/accumulate

.最大のweightをの取り方をmax_elementに変更。
  https://en.cppreference.com/w/cpp/algorithm/max_element
  https://github.com/goto-untrapped/Arai60/pull/41/commits/20413f45f793526ba10aa45640103848bf595a09

・IsLoadableの引数weightsにconstを追加

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

# ステップ4
  mainディレクトリ内に宣言と実体を分ける練習
  下記を参考
  https://qiita.com/yagiyuki/items/ff343d381d9477e89f3b
  https://itandcfd.com/makefile/1844/
  https://qiita.com/harinez2/items/0d25eabdc6dae66e7bee

## 他の方の解法
https://github.com/Mike0121/LeetCode/pull/46/commits/6f804346956fd635818721dc65bbee82d5af85a8
https://github.com/Yoshiki-Iwasa/Arai60/pull/37/commits/cb17d4e930e3e6593807f97432f02edbe77e82a8
int maxWeight = Arrays.stream(weights).max();
int totalWeight = Arrays.stream(weights).sum();
->この書き方C++でできないか探ってみる
https://github.com/goto-untrapped/Arai60/pull/41/commits/20413f45f793526ba10aa45640103848bf595a09
https://github.com/fhiyo/leetcode/pull/45

## Discordなど

