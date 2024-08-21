## ステップ1
深さと値をセットで保存しておけば解けそう

level_to_values[depth].emplace_back(node->val);の部分を
返却用のvector<vector<int>>で行いたかったが
vectorに対してサイズ確定前のインデックスにアクセスするとエラーとなる
なのでmapを挟む形にした。15分ほど

時間計算量
O(n log n)
空間計算量
O(n)

## ステップ2
・queueに入れてから、nodeが有効なのか判断する方に変更
  短くかける
  下記を参考に変更
  https://github.com/shining-ai/leetcode/pull/26/commits/c90e9ee927b79c6002701924828b3eefcb3281bc

・データの持ち方変更
  whileループの中でさらにループを作りvectorを作りその中に同じ階層のvalueを突っ込んで
  内側のループ後にvector<vector<int>>に突っ込めばmapに変形する必要がなくなる
  登場人物が減るので読み易い
  また、階層情報と値を対でもつつようがなくなる

  queueのサイズをforループの宣言内で定義していてハマった。
  ループ内でqueueに突っ込んでいくので想定外の動きとなる

・変数名変更
  vector<vector<int>>を格納する変数をvaluesからlevel_to_values
  値(たち)に対する階層

## 他の解法
dfs(再帰)でも解いてみる
下記を参考
https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/3196962/c-bfs-dfs-o-n-explained/

関数化しないで描こうとしたが、BFSとあまり変わらない感じになったのでやめた
queueを使った方が再帰より処理が追い易いと感じる
時間計算量
O(n)
空間計算量
O(n)
