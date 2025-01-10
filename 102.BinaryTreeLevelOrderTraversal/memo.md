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

## 先延ばしにしていたstd::moveとcopy周りについて調べる
・vectorをスクラッチで定義
49. Group Anagramsでアドバイス頂いている
>練習として、簡単なstd::vectorのようなクラスを自分で作成して、copy/move constructor/assignmentを定義してみたらいいかと思います。
https://github.com/Ryotaro25/leetcode_first60/pull/13

・kazukiiiさんの解説
https://github.com/Ryotaro25/leetcode_first60/pull/13#discussion_r1664897652
・右辺値参照・ムーブセマンティクス
https://cpprefjp.github.io//lang/cpp11/rvalue_ref_and_move_semantics.html
・C++ のムーブを理解する
https://zenn.dev/mafafa/articles/cba24383d46900
・How to implement our own Vector Class in C++?
https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/

**メモ(ポイントなど)**
*束縛とは？*
  下記の例のように、&や&&をつけることで右辺値でのみor左辺値でのみアクセスできるように設定すること
　左辺値参照
  int& lvalue_ref_1 = x;              // OK
  int& lvalue_ref_2 = 0;           // Error 右辺値を左辺値参照で束縛している
  右辺値参照
  int&& rvalue_ref_1 = x;          // Error 左辺値を右辺値参照で束縛している
  int&& rvalue_ref_2 = 0;             // OK

*ムーブされた変数は右辺値となり、それ以降使える保証はなくなる*
  変数がさし示している値を付け替えるイメージだったが
  ex)
  std::string x = "Hello, world!";
  std::string y = std::move(x);
  実際はmoveを通してxを右辺値に変換して、代入が行われる
  上記の後、xを無効化する(これはクラスによる)

  コピーとの違いは、左辺値で受け取るのか右辺値で受け取れるのかの違い
  また、moveの場合は元のオブジェクトを無効化する
