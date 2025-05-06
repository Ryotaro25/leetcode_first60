## ステップ1
O(n)で実装する必要があるためvectorを2回見ていく方法は使えない
全てを掛け合わせた数字を出してから、nums[i]を割っていいく方法が思いついたが
割り算も制約上使えない

問題をもう一度読み直す
>The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
わざわざprefixとsuffixが記載があるということをヒントに
iの位置までの合計とiより後ろの合計を管理するvectorを二つ用意して

最終的に掛け合わせると回答できそう
時間計算量O(n)
空間計算量O(n)

acceptまで30分

## ステップ2
nums[i]を掛ける順序とタイミングを考えれば、
iの位置までの合計とiより後ろの合計を管理するvectorを使う必要がなくなる。

prefix_productとsuffix_productを使ってそれぞれ左側と右側の積を保持する。
products_except_self[i]に掛けた後に、
prefix_productとsuffix_productをnums[i]で更新することで、
各ステップではnums[i]を除いた積だけが使われるようになっている
=>いきなりこの解法に辿り着くのは難しそう

vector<int>の初期化について
https://stackoverflow.com/questions/42743604/default-values-when-creating-a-vector-c
いつも忘れるので気になったら都度読む癖をつける

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
prefixやsuffixを単体で使うよりprefix_〇〇というように何が入っているのかわかるような名前がいいと感じた
resやlengthに関しても何が入っているのか分かるような変数名をつけたい
https://github.com/t-ooka/leetcode/pull/5

indexの管理方法を考えることで左側の積と右側の積を一度に計算することができる
https://discord.com/channels/1084280443945353267/1200089668901937312/1200403156073455646
## Discorなど

# PRに対するコメント
partial_sumとtransformを使っても解答可能
=>いずれの関数も知らなかったので普段使っている物以外にも足を伸ばす姿勢を意識。

partial_sum
https://cpprefjp.github.io/reference/numeric/partial_sum.html
https://en.cppreference.com/w/cpp/algorithm/partial_sum

multiplies
https://cpprefjp.github.io/reference/functional/multiplies.html
https://en.cppreference.com/w/cpp/utility/functional/multiplies

transform
https://cpprefjp.github.io/reference/algorithm/transform.html
https://en.cppreference.com/w/cpp/algorithm/transform
