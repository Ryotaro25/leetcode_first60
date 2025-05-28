## ステップ1
重複があれば削除だったのでsetを使って重複を探して、
重複している要素の削除で回答できそうだと考えました。

重複があった場合のheadのポインタを付け替えて要素を削除する方法を思い付けなかった。
ここで回答をみました
更新方法2パターンあって
・setをループで回しながら新たにListNodeを作っていく方法
・headのポインタを付け替える方法

新たにListNodeを作っていく方法は理解できなかった。
headのポインタを付け替える方法はコードを読んで、紙に動きを書くことで分かった。

参照
https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/2221691/easy-c-solution-using-set-runtime-15-ms-faster-than-59-39/

https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/4612581/easy-c-solution-two-pointers-approach/

## ステップ2
確認した他の人の回答とやりとり
https://discord.com/channels/1084280443945353267/1183683738635346001/1183690900791111730
setを使わないで、隣り合うnodeが同じ値を保持しているのか比較する方が
・新たにsetで管理する必要がない
・2つのListNodeを準備してポインタを付け替える必要がない

https://discord.com/channels/1084280443945353267/1195700948786491403/1196701558382018590
命名に関して実際の挙動と紐づいているのか気を付ける
ステップ１で、nodeとprevで管理をしていたが
node => next(現在いるnodeの次のnodeを指しているため)
prev => current_node(現在いるnodeを指しているため)