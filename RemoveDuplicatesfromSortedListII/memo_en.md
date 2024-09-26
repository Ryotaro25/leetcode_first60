## points
There are two ways to implement this program.
The first one is using the number of vals appered in the nodes.
If the count is 1, there is a only one node, which has the same value or there's no duplication.
After countign the vals of the nodes, the next step is constructing new nodes using the nodes which appered one time.
the time complexity is O(n)
the space complexity is O(n)

The second way is changing the pointer.
If the node and the next node have the same number, the current node's pointer will be chnaged.
It's easier to come up with, however it is a bit challenging to implement because it requires three nodes.
The fewer objects I have to memorize while reading the code, the easier it is to understand the code.
the time complexity is O(n)
the space complexity is O(1)
There's no need to store every node.

## tips
check if there's need to allocate the heap memory
end with the new line
after if and while statements, the space should be added
it is better to use auto whne the declaration or for loop, which uses map or set structure
