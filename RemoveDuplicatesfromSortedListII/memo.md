## ステップ1
重複をした値を全除外して新たなnodeを作るには
重複した値、重複していない値どちらも必要だと思ったのでmapを使った

存在しないkeyにアクセスするとmapがデフォルトで0を返却するのは知らなかった。
この比較部分で一度、mapの使い方を調べた。

時間計算量
whileループは全ての値を確認し、forループは全て重複なしの場合O(n)となる。

空間計算量
時間計算量と同じで、全て重複なしの場合最悪O(n)となる。

## ステップ2
・mapを使う他の人の解法を確認
url: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/3857725/c-using-hash-table-unordered-map/
valsCntへのデータ挿入時にすでに存在するのかどうかを、あえてチェックする必要がない
後の工程でカウントが１であるかどうかしかみないので

forループの部分は丸覚えしていたので、Range-based for loopについて読んでみた。
mapからpairにキャスト？されるので->は使えなくなる。
https://en.cppreference.com/w/cpp/language/range-for


# 他にどのような方法があるのか調べた
・現在と1つ前の状態をもつポインタを用意する方法
  url: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/
  threePointer.cppで解いてみた
  時間計算量
  whileループは2つ存在しているが、headを最後まで見るだけなのでO(n)
  
  空間計算量
  いずれの変数も常に1つの値を持っているだけなのでO(1)

# 見たdiscordなど
普段の会話のように素直にコードも書く
https://discord.com/channels/1084280443945353267/1195700948786491403/1197102971977211966

https://github.com/TORUS0818/leetcode/pull/6/files/5c5a2db5f787a9ea41fd34c98ff92135e33c42c6

・



