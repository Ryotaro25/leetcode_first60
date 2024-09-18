# points
There is no need using the advanced algorism, like fast-and-slow.
It would be better to come up with more straight way. Here are steps.
1. prepare the place for memorizing node while visiting each node
2. start visiting from the top
3. if there is a node where I stand, it meas there is a loop.
   or put node into the momorization.
4. keep visiting the node until the end. If I could reach the end, it means there is no loop

For memorization, there are multiple choices, includes std::set, std::map, std::vector
There are unordered_set and unordered_map in addition to above.
Both unorderd_set and unordered_map are not always faster than set and map

In this case, using set or vrctor, which contains node, is suitable because there's no need to
keep other values like val and index in addition to information about node itself.
I prefer contains method rathere than find method because it focuses on having the
specific data or not.
