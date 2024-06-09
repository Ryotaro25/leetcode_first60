class Solution {
public:
    // pair・tupple は原則避けることをお勧めいたします。
    // 理由は、中に何が入っているか型から推測できないためです。
    // struct を定義し、 operator< を定義し、 priority_queue や set に入れることをお勧めいたします。
    struct candidates {
        int sum;
        int number1_position;
        int number2_position;

        bool operator<(const candidates& other) const {
            return sum > other.sum;
        }
    };

    struct position {
        int number1_position;
        int number2_position;
        bool operator<(const position& other) const {
            if (number1_position != other.number1_position) {
                return number1_position < other.number1_position;
            }
            return number2_position < other.number2_position;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // すべての情報が来たあとに、ソートをするという方法で、Top K Frequency を出すのではなく、
        // 常に Top K Frequency をモニタリングし続けるというストリーミングアルゴリズムとして解くことも可能ではないかという話です。
        // 具体的にはカウントを大きい順に並べた平衡木を用意しておけば、よさそうです。
        int i = 0, j = 0;
        priority_queue<candidates> sums_and_pairs;
        set<position> visited;
        sums_and_pairs.push(candidates{nums1[i]+nums2[j], i, j});
        visited.insert(position{i, j});

        vector<vector<int>> smallest_pairs;
        while (sums_and_pairs.size() != 0 && k--) {
            auto candidate = sums_and_pairs.top();
            sums_and_pairs.pop();
            i = candidate.number1_position;
            j = candidate.number2_position;
            smallest_pairs.push_back({nums1[i], nums2[j]});

            // sums_and_pairsの中身はsumの小さいもの順序
            if (i + 1 < nums1.size() && !visited.count({i+1, j})) {
                sums_and_pairs.push(candidates{nums1[i+1]+nums2[j], i+1, j});
                visited.insert(position{i+1, j});
            }
            if (j + 1 < nums2.size() && !visited.count({i, j+1})) {
                sums_and_pairs.push(candidates{nums1[i]+nums2[j+1], i, j+1});
                visited.insert(position{i, j+1});
            }
        }
                
        return smallest_pairs;
    }
};
