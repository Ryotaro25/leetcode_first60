## ステップ1
色のパターンはkもしくはk-1
>There cannot be three or more consecutive posts with the same color.
なので、同じ色が2色まではkそれ以外はk-1種類
postsの数が0色、1色や2色の場合もあるので考慮する
3色目以降は、1つ前と2つ前の状態を考慮して色を選ぶ必要がある

時間
O(n)

空間
O(1)

## ステップ2
・変数名変更
  waysをつけることで明示的に方法(複数形)があると伝える

・2つ前、1つ前のの情報を保持するのにvectorを使う必要はない
past_two_colors_waysの要素は2つなのでvectorに入れる必要はない

・0の場合の特別処理を削除
  回答に使っているnum_waysを0で初期化しているため

## 他の解法
__・フィボナッチ数列を使うことで時間計算量 O(log n)で解くことができる__
　　参照 ： https://github.com/TORUS0818/leetcode/pull/32/commits/50d9a5f46afbe969f08a116f412232e540ca159d
　　参照 ：https://github.com/goto-untrapped/Arai60/pull/44/commits/b0b76df73f7b0b3c15b5ae4aef0066cfe611eb1b
　　
__・DPに、bottom-upとtop-downの２種類が存在する__
　　アルゴリズムイントロダクション第二巻に乗っているので関連する章を読む(8/30)
　　参照 ： https://github.com/TORUS0818/leetcode/pull/32/commits/50d9a5f46afbe969f08a116f412232e540ca159d
　
  以下アルゴリズムイントロダクション第二巻を読んで追記(8/31)
  *トップダウン式*
  さっくりとした理解
  nこの要素があったとしてn-1、n-2...と範囲を狭めながら再帰的に部分問題を処理する方式
  top_down.cppにて実装。
  ループの中で、直前2つが同じ色をしているものと異なる色を再帰的に呼び出している
  時間
  O(n)

  空間
  O(n)

  *ボトムアップ式*
  ざっくりとした理解
  トップダウンとは反対に0, 1, 2,....nと要素を昇順に処理していく方式
  step1~3がボトムアップ方式となっている(実装後に用語知りました。。。)

__・メモ化しながら再帰で解く方法も存在する__
https://github.com/Yoshiki-Iwasa/Arai60/pull/44/commits/3a55cc495ac31c94e38e1b39f40055ed9d261f18

  単純に再帰で解くと時間計算量がO(2^n)となるので要素数に比例して実行時間が凄くかかる
  このトレードオフとしてメモ化がある(状態を保持しておくためのメモリを要するため)
  メモ化しながら存在するというよりは、メモ化しないと時間計算量が爆発的になる


__・LRUを使っている__
なぜ？
https://github.com/goto-untrapped/Arai60/pull/44/commits/b0b76df73f7b0b3c15b5ae4aef0066cfe611eb1b
https://discord.com/channels/1084280443945353267/1226508154833993788/1253725840114454598
>LRU cacheというのがよく聞かれるのってなんでなんだろう(どういう出題意図なんだろう)
>話の導入がしやすく、助け舟も出しやすく、書けるからですね。

なるほど、つまり常識として(使える選択肢として)理解しておくべきか
キャパシティを設定しておいて、超えた場合は自動で削除する
これによって無駄にリソースを使わない

実装の参考
https://github.com/goto-untrapped/Arai60/pull/44/commits/b0b76df73f7b0b3c15b5ae4aef0066cfe611eb1b
https://github.com/sakupan102/arai60-practice/pull/31
LRU.cppに実装
