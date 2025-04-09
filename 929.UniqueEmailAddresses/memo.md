## ステップ1
初見では、メールごとに一文字ずつチェックし削除していく方針でコードが書いた
上記だと扱っているインデックスの管理がうまくいかなかったので
新たに文字列を作成する方針で実装

## ステップ2
関数化とドメイン部分の取得を後ろからに変更
関数名参考
https://en.wikipedia.org/wiki/Canonicalization
https://github.com/hayashi-ay/leetcode/pull/25/commits/5aaab0646d6bcff10dfee447bab66ca2b841d7e7

関数名はcanonicalize_emailからemailを撮ってcanonicalizeとした。
step3で何度もcanonicalize_emailと関数内の変数canonicalized_emailを間違えため。

時間計算量
インプットの数をnメールの長さをmとする
setのinsert部分はO(n log n)
関数部分はO(n * m)
なので合計してO(n log n + n * m)

空間計算量
O(n * m)

## 他の方の解法
チェックの部分を関数化するのとローカルとドメイン部分に分けるのは分かりやすいと思った
実際自分もローカル部分とドメイン部分は分けた（処理の必要がないので）
https://github.com/hayashi-ay/leetcode/pull/25/commits/5aaab0646d6bcff10dfee447bab66ca2b841d7e7

ホスト部分にも＠を使える場合がある
https://en.wikipedia.org/wiki/Email_address
https://github.com/sakupan102/arai60-practice/pull/15

正規表現でも対処できる
https://github.com/nittoco/leetcode/pull/7/commits/16d0e28cdbb5a4584218aa13d040a62c36d4af8f


