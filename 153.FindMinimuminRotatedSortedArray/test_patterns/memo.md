よいと思うので、オプショナルな質問です。

「2で割る処理がありますがこれは切り捨てでも切り上げでも構わないのでしょうか。」
「nums[middle] <= nums[right] とありますが、これは < でもいいですか。」
「nums[right] は、nums.back() でもいいですか。」
「right の初期値は nums.size() でもいいですか。」

これ、それぞれ変更するかしないかで16通りあると思いますが、うち動くのはどれでしょうか。


A 「2で割る処理がありますがこれは切り捨てでも切り上げでも構わないのでしょうか。」
○ middle = left + (right - left) / 2;
× middle = left + (right - left + 1) / 2;

B 「nums[middle] <= nums[right] とありますが、これは < でもいいですか。」
○ nums[middle] <= nums[right]
× nums[middle] < nums[right]

C 「nums[right] は、nums.back() でもいいですか。」
○ nums[right]
× nums.back()

D 「right の初期値は nums.size() でもいいですか。」
○ right = nums.size() - 1
× right = nums.size()

パターン
1   ○ ○ ○ ○  OK
2   ○ ○ ○ ×  NG nums[right]にアクセスする際に範囲外になる場合がある
3   ○ ○ × ○  OK nums.back()は最大値があるべき場所なのでここと比較することで回転しているのか判断できる。
4   ○ ○ × ×  OK right = nums.size()としても、nums[right]ではなくnums.back()で配列の1番右側にアクセスするので範囲外アクセスとならない。nums.back()は最大値があるべき場所なのでここと比較することで回転しているのか判断できる。
5   ○ × ○ ○  OK 
6   ○ × ○ ×  NG rightの初期値をnums.size()としているとnums[right]にアクセスする際に範囲外になる場合がある
7   ○ × × ○  OK 右端に最小値がある場合、nums[middle] < nums.backは常にfalseとなりleftが最小値によるため
8   ○ × × ×  NG 探査範囲を狭める場合に、middleがnumsの最後の要素を指してしまうため。次のループでもleft < rightはtrueとなり範囲外を指してしまう
9   × ○ ○ ○  NG rightがmiddleで更新される際にずっと同じ値になるため。left < rightが常にtrueとなり無限ループとなる
10  × ○ ○ × NG nums[right]にアクセスする際に範囲外になる
11  × ○ × ○ NG rightが更新される際にずっと同じ値になるため。left < rightが常にtrueとなり無限ループとなる
12  × ○ × × NG rightが更新される際にずっと同じ値になるため。
13  × × ○ ○ NG middle < right が成立しないの場合があるため。
14  × × ○ × NG nums[right]にアクセスする際に範囲外になる
15  × × × ○ NG 範囲が狭まらなくなり無限ループとなる
16  × × × ×