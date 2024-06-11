## ステップ1
単語ごとにsortを使って、sort後に同じ単語を全てarrayに入れる
単語ごとに集める方法が浮かばなかったので下記参照
https://leetcode.com/problems/group-anagrams/solutions/3687735/beats-100-c-java-python-beginner-friendly/

実装を考える際どうしても総当たりで対応しようとしてしまう
紙とペンでならどうする？を考えられていない

時間計算量
O(n)
空間計算量
O(n)

## ステップ2
>ソースコードを読む人のペルソナが、ネイティブアメリカンイングリッシュスピーカーで、かつコンピューターサイエンスに関する学部出身であることを念頭に置き、そういった人たちに対して書くことを意識する
https://github.com/ryoooooory/LeetCode/pull/1
変数に型名を加えると特別なものとして捉えられることがある
https://github.com/sakupan102/arai60-practice/pull/13#discussion_r1574597470


## 他の解法
asciiを使った解法が多い？
Pythonのtupple部分のc++への置き換えはわからなかったのでChatGPTを使用
https://github.com/hayashi-ay/leetcode/pull/19/commits/b6a9f2716a394c4a20d974d178d39060e5d92d43
普段ascii文字を操作することはないので、理解するのに時間がかかった

ascii.cppに実装
時間計算量
O(n * m) 
渡される文字の長さをmとする

空間計算量
O(n)
