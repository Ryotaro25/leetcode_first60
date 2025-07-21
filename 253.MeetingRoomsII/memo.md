## ステップ1
時間ごとの鍵の貸し出し数を記録し
同時貸出が最大のものが必要な最小部屋数

時間計算量は O(n log n)
空間計算量は O(n)
intervalsに対しては破壊的変更を行なっている
要件によってはコピーを作るべきか

## ステップ2
・時間ごとの鍵の貸し出し数を記録しているmapに対する変数名が微妙

・priority_queueで部屋の貸し出しを管理する方法もある
  mapでできたら出来そうよね。
  priority_queue.cppに実装
  部屋の貸し出しがあるたびにpriority_queueに現在使用中の部屋の終了時間を突っ込む。
  前の部屋の終了時間が現在の開始時間と被るなら
  部屋の解放はできない。被らないなら部屋の解放を行う(次の組に同じ部屋を貸し出す)
  
・関数型のようか解法もある
  イベント(部屋の使用時間)を時間順に処理しながら 部屋の使用数を累積 して最大値を求める。
  nittocoさんの解放を参照。Pythonのfoldの代わりにc++のaccumulateを用いた
  https://en.cppreference.com/w/cpp/algorithm/accumulate
  accumulate.cppに実装
  vector<pair<int, string>> をstructに置き換えた方がfirst,secondのようなアクセスをしなくていいので
  分かりやすい。今回は自作するよりも、既存のsortを使いたいのでpairで実装

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
heapを並び替える目的で使っている(なるほどです)
取り出した時の時間にstartとendと印をつけ、重複をカウント
重複しない場合は、start => endとなるはず、start startと続いた場合はその分部屋を割り当てる必要がある
https://github.com/nittoco/leetcode/pull/45/files

制約的にOKでも、intervalsが空であるかどうかは判定しないと不安です
開始時間と終了時間を分けて管理し、終了時間より前の開始時間が来たら会議室を増やす方法もある
https://github.com/goto-untrapped/Arai60/pull/61
https://github.com/Yoshiki-Iwasa/Arai60/pull/61/commits/bab0a6d4fcab4b2fd5245a0affed5e034c81d443
直感的なコードでとても読みやすい
https://github.com/Mike0121/LeetCode/pull/28/commits/227faa038a848ef9597ee593b8228999d794d91c
## Discorなど

