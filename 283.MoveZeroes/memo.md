## ステップ1
といたことがあって解法を覚えていた。
forループのindexでnums全体を探索しながら
non_zero_indexを使って0でない要素を前に詰めていく

## ステップ2
fill_zero.cpp
usatieの解法を参考に実装。イテレータは使わない方法
https://github.com/usatie/leetcode/pull/3/commits/f24aaf1c13c4b2fc1c6d935297d7a318e5b82dda

remove.cpp
Yoshiki-Iwasaの解法を参考に実装。
vectorのeraseではなか、<algorithm>のremoveを使う
前者だとforの中で使うのでO(n^2)となるが、後者だと舐めながら0を消して前に詰めるのでO(n)
removeは削除するのではなく、不要な要素を後ろに寄せているだけなので
詰め終わった箇所からnums.end()までゴミデータ？が残っているのは違和感

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
・イテレータを使っている
  イテレータなんとなく苦手意識がある。使えるメソッドを覚えられていないので馴染みを持てていないからか
・寄せてから0で埋めることもできる。なるほどです。
・c++のテストの書き方やファイルの分け方勉強になります。
https://github.com/usatie/leetcode/pull/3/commits/f24aaf1c13c4b2fc1c6d935297d7a318e5b82dda

・0の場合は削除して配列を前に詰める
  この方法もなるほどです。
  調べたらc++も同じことできそう。
https://github.com/Yoshiki-Iwasa/Arai60/pull/59

・基本の解法は同じか
https://github.com/fhiyo/leetcode/pull/54

>zero_indexにしてしまうと、客観的に(or 後から自分で見た場合)自然言語の直感と反するんですね。
https://github.com/Mike0121/LeetCode/pull/24

>「はじめの0が出てくるまでは、i か i + 1 を指していて、0が出てくると、
>そこで止まり、swap する関係>上、そこから先は常にはじめの0を指している。」
>くらいじゃないですか?だから、and first_zero < len(nums)がなくても動きますよね。
https://github.com/fhiyo/leetcode/pull/18#discussion_r1629642641

ここの変数名めちゃくちゃ迷いました。
>zero_indexだとzeroが入っているindexなのかなと思ってしまいます。多分上のコードを見る感じだとnon_zero_lengthぐらいでしょうか
こう見える人もいるのでよく考えてつけないと。zero_indexでいけそうと一瞬思ってします。
自分はnon_zero_indexにしました。

## Discorなど

