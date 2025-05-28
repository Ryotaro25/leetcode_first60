## memo
There are two ways to implement this problem using multimap and priority queue.

map can not contain dulicated keys, so use multimap
std::multimap is an associative container that contains a sorted list of key-value pairs, while permitting multiple entries with the same key.
https://en.cppreference.com/w/cpp/container/multimap
It is essential to understand the diffrences begin(), rbegin(), end, and rend().
https://en.cppreference.com/w/cpp/container/multimap/rbegin

If you use the map, which value is vector contiaining pairs of numbers, you can implement program but it is harder to access value.

**multimap uses red black tree**
It means if you deltet the last element, the elements are rearranged internally, whcih costs.
By using top, priority queue returns the smallest element.

