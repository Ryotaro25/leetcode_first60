class min_heap {
    vector<int> v;

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

    bool has_parent(int i) {
            return i > 0;
    }

    bool empty() {
            return v.empty();
    }

    int get_smaller_child_index(int i) {
        // if exist right child
        if (2 * i + 2 < v.size() &&
            v[right_child(i)] < v[left_child(i)]) {
            return right_child(i);
        }
        return left_child(i);
   }

    public:
        min_heap(vector<int> input_vector) {
            v = input_vector;

            for (int i = v.size() / 2 - 1; i >= 0; --i) {
                min_heapify(i);
            }
        }

        void min_heapify(int i) {
            int smallest = i;
            int left = left_child(i);
            int right = right_child(i);

            if (left < v.size() && v[left] < v[smallest]) {
                smallest = left;
            }

            if (right < v.size() && v[right] <= v[smallest]) {
                 smallest = right;
            }

            if (smallest != i) {
                swap(i, smallest);
                min_heapify(smallest);
            }
        }

        void push(int value) {
            int added_index = v.size();
            v.push_back(value);

            while(has_parent(added_index) && v[parent(added_index)] >= v[added_index]) {
                int parent_index = parent(added_index);
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

};

class KthLargest {
private:
    min_heap largest_numbers;

public:
    
    int kth_number;
    KthLargest(int k, vector<int>& nums) : largest_numbers(nums) {
        kth_number = k;

        for (int i = 0; i < k - 2; ++i) {
            largest_numbers.pop();
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

