# fast slow2つのポインターを用いた解法
## ステップ1
繰り上がりがあればそれを考慮した上で、Nodeの次の値と足していく
l1とl2とそれぞれ終点にたどり着くまで上記の足し算をすれば解けると考えました。

先にwhileループ部分を思いついて
以下の部分に関してはエラーテキストを見ながら追加で処理を入れた
・2つのNodeの要素がそれぞれ1つの場合
・1番最後のポインターの対処

時間計算量
l1とl2とそれぞれ終点にたどり着くまでのループなのでO(n)+O(n)でO(n)

空間計算量
入力値の大きさで増減するものはないので、O(1)

## ステップ2
こちらの解法を元に綺麗に修正
https://leetcode.com/problems/add-two-numbers/solutions/3675747/beats-100-c-java-python-beginner-friendly/
・l1とl2をそれぞれ新しくnode1とnode2にいれる必要はない
・whileの条件に繰り上がりが0出ないか判断することで、step1で外だししていた
　一番最後に繰り上がりがある場合の処理を一緒に行える
・nullptrの場合はnode->valのようにアクセスできない

google style guideに三項演算子の記述は無かったが、
どのタイミングで使うのか分からない＋現職では禁止なので使わなかった

## 他に見た回答、discord
https://leetcode.com/problems/add-two-numbers/solutions/1012/recursive-8-line-c-solution/
再帰で解く方法
ベース条件：いずれかがNullの場合に一方を返却
処理の流れは理解できましたがこれを思いつくのは難しいと感じた
普段あまり再帰を使わないから？

時間計算量
l1とl2とそれぞれ終点にたどり着くまでの再帰なのでO(n)+O(n)でO(n)

空間計算量
l1とl2とそれぞれ終点にたどり着くまでスタックに積まれるのでこちらもO(n)

https://github.com/fhiyo/leetcode/pull/5#discussion_r1596979574
初期化されない場合があるので、要件に沿って宣言を行う
今回の場合は、ListNode dummy_node;でもListNode()が呼ばれる。

https://github.com/cheeseNA/leetcode/pull/2#pullrequestreview-1941037516
言語によってintの扱える範囲が異なるのは知らなかった。
Python3のintはPython2のlongに相当し、最大値の上限はなく、メモリの許す限り大きな値を扱うことが可能(ref: https://note.nkmk.me/python-int-max-value/)

c++の場合-2,147,483,648 ～ 2,147,483,647