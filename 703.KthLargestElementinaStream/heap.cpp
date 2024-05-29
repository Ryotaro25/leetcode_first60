class min_heap {
    public:
        int parent(int i) {
            return (i - 1) / 2;
        }

        int left_child(int i) {
            return 2 * i + 1;
        }

        int right_child(int i) {
            return 2 * i + 2;
        }

        bool has_children(int i) {
            return 2 * i + 1 < v.size();
        }

        int get_smaller_child_index(int i) {
            // if exist right child
            if (2 * i + 2 < v.size() &&
                v[right_child(i)] < v[left_child(i)]) {
                return right_child(i);
            } else {
                return left_child(i);
            }
        }

        void push(int value) {
            int added_index = v.size();
            v.push_back(value);

            while(added_index > 0) {
                int parent_index = parent(added_index);
                if (v[parent_index] < v[added_index]) {
                    break;
                }
                swap(parent_index, added_index);
                added_index = parent_index;
            }
        }

        void pop() {
            v.front() = v.back();
            v.pop_back();
            int added_index = 0;
            while (has_children(added_index)) {
                int smaller_child_index = get_smaller_child_index(added_index);

                if (v[added_index] < v[smaller_child_index]) {
                    break;
                }
                swap(added_index, smaller_child_index);
                added_index = smaller_child_index;
            }
        }

        int top() {
            if (empty()) {
                return 0;
            }
            return v[0];
        }

        int size() {
            return v.size();
        }

        void swap(int index_1, int index_2) {
            int temp = v[index_1];
            v[index_1] = v[index_2];
            v[index_2] = temp;
        }

        bool empty() {
            return v.empty();
        }

        vector<int> v;
};

class KthLargest {  
public:
    min_heap largest_numbers;
    int kth_number;
    KthLargest(int k, vector<int>& nums) {
        kth_number = k;
        for (int i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        largest_numbers.push(val);

        if (largest_numbers.size() > kth_number) {
            largest_numbers.pop();
        }
        return largest_numbers.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
