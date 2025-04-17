## points
The first step is to store every node into tha stack, so that you can pick them out in reverse order.
Time complexity is O(n) because it traverses every node when nodes are stored into stack.
Space complexity is O(n) since the same reason.

# tips
・I should use the same way for conditions, meaning avoid conjuction of multiple ways.
 EX) while (head) and while (head != nullptr) 

・If there's no specific reason to use the heap memory, it should be avoided.
  There's a chance for meamory leak
  Here is a documentation for stack vs heap
https://en.cppreference.com/w/cpp/language/storage_duration

・Allocating heap memory costs more than changing pointer in the stack memory.
・When you use the new, it decrease readability because readers should care the timing when the program free the memory. 

・the object should be allocated on the stack memory as possible as you can for avoiding memory leak problem
>C++ allows you to create scopes on the fly as well. All you have to do is wrap x's lifetime within braces like so: { Object x; x.DoSomething; }. After the final '}', x's destructor will be called freeing any resources it contains. If x, itself, is the memory to be allocated on the heap, I suggest wrapping it in a unique_ptr so that it is cleaned up easily and appropriately. 

According to effective c++, the pointer should be manged by using unique_ptr.