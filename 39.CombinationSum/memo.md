## ステップ1
再帰呼び出しごとに、数字を増やしていきその合計がtargetかどうかを確認する
数字の重複OKなので、再帰呼び出し時のindexで少し詰まった

引数が多いきもするが前2問のような考え方で解けた

## ステップ2
・targetの数字から引いていって、残りが0か0を下回るのかで処理するように変更
  こうすればtargetとsumを引数に渡していたのをremainだけに減らすことが可能
  参考 leetcodeの回答
・変数名変更
  all_candidates => all_combinations
  partial_candidate => partial_combination
  候補って確かに曖昧でした。
・現時点でも合計がtarget以上なのかどうかを再帰呼び出しする前に移動
　remainに対して candidates[i] が大きすぎたら、それ以降の候補は試す必要がない

・loop.cppを追加
tuppleを使うよりstructを用いた
CombinationAndTargetAndIndexの中に部分組み合わせと残りの数字とインデックスを保持。
構造名がすごく微妙

 stackの変数名も微妙

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の解法
>問題文や関数にあるものを命名に使うといい感じになる
ループで解いている。再帰の方法を形で覚えてしまっているので、再帰からループへの変換をしたら良さそう
https://github.com/nittoco/leetcode/pull/25

>変化のある方を比較演算子の左側に置く方がわかりやすい
リーダブルコードを読み直そう
https://github.com/Mike0121/LeetCode/pull/1/commits/b2f5e21e45fc088fb86bdc1f66cb3f6cd4611027

DPを使って解くことも可能
>先にcandidatesをsortしておけば、total+candidates[i] > target となったときにi以降の要素を見る必要はないのでサボれる。
なるほど再帰呼び出しの前に、targetと比較することで少し枝かりができるのですね。
https://github.com/fhiyo/leetcode/pull/52
https://github.com/Yoshiki-Iwasa/Arai60/pull/57

## Discorなど

