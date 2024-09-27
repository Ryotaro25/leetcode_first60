## Points
To implement this program, it needs visiting each nodes while calcurating sum in each loop.
The carry should be used in the next calcuration for sum value.
If one of each node is valid, it needs to keep visiting. 
Not always two nodes have the same number of nodes.

time complexity is O(n)
first and second nodes need n times loop at most, so O(n) + O(n) = O(n) which is used simplified rule.

space complexity is O(1)

## tips
naming should be cared, like weather it is meaningful.
It is not alywas preferable to use abreviation.
If the first letter is big, it seems constant value.
If you use the magic number, it shoud be apparent.

Structure defined by leetcode may not be initialized.
It would be better to check requirements
https://github.com/fhiyo/leetcode/pull/5#discussion_r1596979574

Based on the programing language you use, the size of int may differ.
For example, int of Python 3 is as same size as long of Python 2
https://github.com/cheeseNA/leetcode/pull/2#pullrequestreview-1941037516
