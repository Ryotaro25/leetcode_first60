

## ステップ1
vectorかStack (今回からのジャンル)を使って一文字ずつ確認すれば解けそう
submit後のエラーより

2文字以下の場合のエラーハンドリング追加(マジックナンバーは2にしました)
{[]}の場合を考慮
一文字めが)]}のいずれかの場合
問題文を読んで自分の中で整理する前にコードを書き始めている。

時間計算量
forループは入力の大きさに影響されるので最悪O(n)

空間計算量
全て開始ブラケットの場合、最悪O(n)

## ステップ2
stackについてきちんと学んでみた
https://cpprefjp.github.io/reference/stack/stack.html

見た解法（同じくスタックを使う）
https://leetcode.com/problems/valid-parentheses/solutions/3399077/easy-solutions-in-java-python-and-c-look-at-once-with-exaplanation/

条件を整理してまとめるとbrackets.pop();を一度の記載で書くことができる。
"]" 最初にいずれかの開始ブラケットが来てれば、stackは空ではない。
　　空かどうかの判断は1番はじめにしないと、空のスタックに対してPOPしてしまう。
""　最初から空の文字列が渡された場合もエラーで弾く
"[}"　if文で愚直に判断

## 他の解法
やっていることはStackと同じ
https://leetcode.com/problems/valid-parentheses/solutions/9478/no-stack-o-1-space-complexity-o-n-time-complexity-solution-in-c/

## Discordなど
意味のある変数名を持たせる
https://github.com/kzhra/Grind41/pull/2

講師陣はチョムスキー階層、タイプ-2、プッシュダウンオートマトンを連想する
https://discord.com/channels/1084280443945353267/1201211204547383386/1202541275115425822

それぞれ初耳でした。オートマトンに種類があったのですね。
参照：https://ja.wikipedia.org/wiki/%E3%83%81%E3%83%A7%E3%83%A0%E3%82%B9%E3%82%AD%E3%83%BC%E9%9A%8E%E5%B1%A4

https://ja.wikipedia.org/wiki/%E3%83%97%E3%83%83%E3%82%B7%E3%83%A5%E3%83%80%E3%82%A6%E3%83%B3%E3%83%BB%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3
