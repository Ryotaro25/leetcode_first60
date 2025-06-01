## ステップ1
200Number of Islandsに似ていたので、全体の流れはこちらを使いつつ
各島のサイズの管理方法だけ考えれば解けそう

おそらく前回のようにunion findでも解ける？

入力値を'1'と勘違いしていたので似たようなものでも問題文はよく読まないとと反省

## ステップ2
問題文ではmax sizeではないので変数名をmax_areaに変更
landも出てきているがareaとして色掛けされている
https://github.com/hayashi-ay/leetcode/pull/34

こちら参考にしながらunion findで実装してみた
https://github.com/TORUS0818/leetcode/pull/20
関数を定義するだけでなく、ランク付け用のツリーの高さやxとyのランクに応じて
島の大きさなどを管理する必要があり大変だと感じた

unionは予約後かつ前回指摘受けたように名詞なのでuniteにしてみた
=> Unionの方が一般的

## 他の方の回答など
https://github.com/Yoshiki-Iwasa/Arai60/pull/17
https://github.com/TORUS0818/leetcode/pull/20
