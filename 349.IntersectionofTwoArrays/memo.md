## ステップ1
unordered_mapを使って重複を削除したnumber1の集合を作ってから
それぞれnumber2に含まれているのか確認すれば求まる

unordered_mapに入れたのはcontains関数を使いたかったため
最終的なvectorで返却する前にもユニークなリストにしておきたかったのでsetに入れて重複させないようにした。

計算量はO(n)
空間計算量もO(n)

## ステップ2
unordered_setのcount関数を使えばより短く書くことができる
一度見つけたら、重複対象リストから削除することで重複なしでvectorに追加することができる
https://leetcode.com/problems/intersection-of-two-arrays/solutions/82001/8ms-concise-c-using-unordered-set/

setにもcontains関数が存在していた
https://cpprefjp.github.io/reference/set/set.html


## 他の解法
両方をsortして前から順番に同じ数字を拾っていく方法
ユニークなリスト内に同じものが存在するか確認していくsetの方がわかりやすかった
https://leetcode.com/problems/intersection-of-two-arrays/solutions/3945663/easiest-two-pointer-approach-with-o-nlogn-c/?source=submission-ac)%E3%80%81%E3%81%9D%E3%82%8C%E3%82%88%E3%82%8A%E3%81%8B%E3%81%AF

Pythonだとintersection関数が存在する
要素数が少ない方でループさせると速くなる
https://github.com/fhiyo/leetcode/pull/16/files/eaa2d65798b4d17384d12bf34a1b7c49346bbbc7#diff-da445a7908289549ad9907a2011d1993fef4106adb748494f1fadc963ad81c84

C++にも存在していた
set_intersection.cppで実装
https://cpprefjp.github.io/reference/algorithm/set_intersection.html

## Discorなど
マージソートみたいな方法
https://discord.com/channels/1084280443945353267/1183683738635346001/1188159345792393397
