## ステップ1
queueに追加していって、取り出しながらnodeごとvalueが存在するのか次が存在するのか確認する
引数を変更しようとしたが呼び出され方が決まっている制約あり(見落としていた)
・next()やhasNext()を引数あり関数に変更できない
・コンストラクターの初期化、next()、hasNext()の順番で呼び出される
stackに追加していけば左側の端っこ→右側と取り出せる

エラーを見ながらなんとか解けたけど、
chatgptに聞いてみたが、next() や hasNext()の呼び出されるタイミングがよく分からなかった
chatgpt回答：
  next() や hasNext() の呼び出しはそのオブジェクトに対して行われ、木全体を順番に走査します。

イメージとしては、while(nodes) {next(node->left) や hasNext(node-left)}のように呼び出したい

時間計算量
全て左や右にnodeが紐づいている場合O(n)

空間計算量
同じ状況でO(n)

## ステップ2
下記を読んでみた
https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/

・hasNext関数を変更
  単純にqueueが空かどうかだけ返却

## 他の解法
dfsでも解くことができる
左側優先で探索を行いながらindexと紐付けて、valueを管理用のmap入れる
nextが呼ばれるごとに探索中のindex番号をインクリメントしデータを取り出す
管理用mapのindex範囲外になった時点でhasNext()はnullptrを返却
https://leetcode.com/problems/binary-search-tree-iterator/solutions/965790/c-caching-solution-explained-100-time-96-space/

こちらの解法の方がstep1に比べてしっくりくる
step1はnext()関数内で値の取り出しと右側への追加の2種類の処理を行っているので違和感を感じる
外だしする方法は思いつかなかった

