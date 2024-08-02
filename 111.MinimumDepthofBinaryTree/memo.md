## ステップ1
再帰を使って有効な葉で最も低い深さを求めることが出来そう
単に左右どちらかのminを返却すると常に0となって誤りなので
左のnodeのみが有効な場合、右のnodeのみが有効な場合、どちらのnodeも有効な場合で場合分けをする

時間計算量O(n)

## ステップ2
・node->left != nullptrからnode->right == nullptrに変更
条件式を短くできる
参考
https://github.com/TORUS0818/leetcode/pull/24/commits/160fc18153fd5c9178d80bdd44b823ef0149aef1

・left_depthとright_depthの変数に入れていたが削除
　直接nodeから呼び出し

10^5であることを気を付ける
許容されるデータ量について理解していないので調べてみた
=>スタックメモリが確保されオーバーフローを考慮する必要がある
  スタックのデフォルトサイズは8mb

参考
https://stackoverflow.com/questions/23191320/memory-allocation-for-recursive-functions
https://stackoverflow.com/questions/2630054/does-c-limit-recursion-depth

## 他の解法
bfsでも実装。
nodeとdepthを保持する構造体で管理
処理の一番最後(ループの外側)にreturn 0 を入れないと
error: non-void function does not return a value in all control pathと出る
これの回避方法が今の実装でいいのか疑問です

moveの動きを理解するためにどこかでスクラッチで実装する
https://en.cppreference.com/w/cpp/utility/move
## Discordなど

https://github.com/TORUS0818/leetcode/pull/24/commits/160fc18153fd5c9178d80bdd44b823ef0149aef1

