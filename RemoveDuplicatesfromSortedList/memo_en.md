# points
There are mainly two ways to implement this prgoram.
The first one is to modify the pointer, and the next one is create new node.

step4.cpp is the modified version of step 3.
step5.cpp is using the second way, which I forgot to implement in the past.
Different from the below answer, it is enough to store unique values, which are from the input, node to create new nodes. So, I used the set to store values.
https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/2221691/easy-c-solution-using-set-runtime-15-ms-faster-than-59-39/

If you use the new constructor, It is important to consider how the destructor should be implemented or called. In this case, trivial(default destroctor) will be called.

# advises
variable name should have the meaning that it has. If variable contains some value, the name should be vals or values instead of using the irrevant name, like node.


