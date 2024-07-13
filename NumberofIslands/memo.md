## ステップ1
5分考えても分からなかったので答えを確認
DFS/BFSは名前を知っているレベルだったので、
答えを見てもすぐに理解できなかった
「なっとくアルゴリズム」を読んでみた

回答はDFSを使って実装
陸地があれば、自分の実装の場合可能な限り左方向まで進んで陸地の終わりを探す

## ステップ2
BFSやunion findなどの解法が存在する
union findは初耳でした。
https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
それぞれbfs.cppとunio_find.cppに実装

**bfs.cpp**
処理の流れはなっとくアルゴリズムの通りで、探索候補をキューに入れ探索を行う
以前pairやtuppleを使うと中身が分かりにくくなるので原則使わないと教えてもらったので
queueに入れるrowとcolumnを構造体に定義
計算量
rowをm、columnの数をnとするとO(m*n)
空間計算量
O(m*n)

**unio_find.cpp**
アルゴリズムイントロダクションと回答を見ながら実装。
https://leetcode.com/problems/number-of-islands/solutions/5043549/dfs-bfs-union-find-count-components-15ms-beats-99-69

ざっくりとした理解、島を一つのsetとして2つの異なる島が共通部分を持っていれば
Unionをしてカウントを減らす

共通部分の存在は代表同士が同じかどうか
代表の探し方はある地点から再起的に親を見に行く
計算量
union findの部分はO(n)
回答全体としてはO(m*n)

空間計算量
O(m*n)

高速化の技法(小田さん紹介): path compression, splitting,  halving, union by size, union by rank

**・位置に対する変数は？**
i, jをrow, columnもしくはx、yが存在する。好み？
今回はrowとcolumnを使うのが馴染みあるので採用した

**・DFSとBFSの使い分けは？**
https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/
dfs
ソースから離れたところに解がある場合に適している
今回のように島がどこまで続いているのか境界線を探す場合はこちらが適している。
誤っていれば指摘ください。

bfs
与えられたソースに近い頂点を探すのに適している
つまり最短経路を求める場合に適している

**・traverse_islandに引数に参照とそうでないものがあるが違いは？**
試しにstep2.cppのtraverse_island関数を全て参照にして実行
下記エラーが発生
error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
https://www.ibm.com/docs/en/xl-c-and-cpp-aix/13.1.0?topic=initializers-initialization-references-only

constをつけることで再帰呼び出しの中で、
各呼び出しで同じ引数を参照し意図しない上書きを防ぐ

エラーが出ると言うことはc++では禁止されている？と言うこと？
参照に関してもう少し深く理解できる資料あれば教えていただきたいです。

## 見た回答など
https://github.com/rossy0213/leetcode/pull/8
https://github.com/sakupan102/arai60-practice/pull/18

https://discord.com/channels/1084280443945353267/1183683738635346001/1197738650998415500
