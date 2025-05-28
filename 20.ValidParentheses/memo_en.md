

## Discordなど
意味のある変数名を持たせる
https://github.com/kzhra/Grind41/pull/2

講師陣はチョムスキー階層、タイプ-2、プッシュダウンオートマトンを連想する
https://discord.com/channels/1084280443945353267/1201211204547383386/1202541275115425822

それぞれ初耳でした。オートマトンに種類があったのですね。
参照：https://ja.wikipedia.org/wiki/%E3%83%81%E3%83%A7%E3%83%A0%E3%82%B9%E3%82%AD%E3%83%BC%E9%9A%8E%E5%B1%A4

https://ja.wikipedia.org/wiki/%E3%83%97%E3%83%83%E3%82%B7%E3%83%A5%E3%83%80%E3%82%A6%E3%83%B3%E3%83%BB%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3

## tips
・In the for loop, using the primitive char type is desire because char is small or 1 byte
but the reference is 4 ~ 8 byte based on the system architecture.

・After checking the parirs are validated, the stack should be checked whether it is empty or not.

・Instead using the Stack, the vector and string can be used to store the brackets status.

・Instead usings[i] == '(', it is more readable to use map for storing the open and close brackets.
  For instance, initializer can be used.

・Conditions in the if statements should be alinged following google guide.
https://google.github.io/styleguide/cppguide.html#Boolean_Expressions

・Instead of using else statement, the early reaturn can be used for a readability.

・In the LeetCode the std:: doesn't need to be used. In the company, it is required to follow team's rule.






