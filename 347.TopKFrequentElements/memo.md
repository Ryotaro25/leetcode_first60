## ステップ1
mapとpairを使って、keyに対象の数字、valueに登場回数を入れて
valueの降順で並び変えることで解けそう。
出力用のvectorを最後に用意する。

pairの取り扱い方がうろ覚えだったので、途中で確認した。
時間計算量
O(nlogn)
sort部分が最も重い
https://cpprefjp.github.io/reference/algorithm/sort.html
空間計算量
O(n)
要素が重複しない場合は入力データの大きさに影響を受ける

## ステップ2
自分の変数はcountを使っていたがfrequencyを使う方が伝わりやすそう
https://github.com/hayashi-ay/leetcode/pull/60

PythonだとCounterという便利なサブクラスが存在する
c++には相当するものがなさそうだけどmapにを使えば実装はできる(実際にstep1で使った方法)
https://github.com/t-ooka/leetcode/pull/3/files#diff-e14e39d01f77a7c369b1f688b2e0c521b4640ce25ca0db0a4a17e789cac614f3

各要素のそれぞれの数を計算する段階では順番は関係ないのでunordered_mapを使う
コード量は増えるがfirst、secondが何を表すのか明示した方が処理を理解しやすいと思った

## 他の解法
priority queueを使うもの
https://leetcode.com/problems/top-k-frequent-elements/solutions/3316085/c-easy-approach-unordered-map-priority-queue/
https://cpprefjp.github.io/reference/queue/priority_queue.html

priority_queue.cppで実装
解答例では最後の返却用のvector生成の部分でwhile(k-- && !pq.empty())と書いているが
わかりにくい。kの数までの方が素直と感じた

## Discordや他の人のコードなど
クイックセレクトも常識として知っておく
https://discord.com/channels/1084280443945353267/1183683738635346001/1185972070165782688
https://www.geeksforgeeks.org/quickselect-algorithm/
https://github.com/TORUS0818/leetcode/pull/11/files
https://github.com/shining-ai/leetcode/pull/9/files
皆さんの実装例とQuickSelectに関する解説を見ながらquick_select.cppにて実装
計算量はO(nlogn),O(n),O(n^2)Pivotがランダムであるため

https://github.com/cheeseNA/leetcode/pull/13/files#diff-2c02aa0b895304ea469c858cfd15bbdf92b9bff38c9b6d77d45d344c424bca00
