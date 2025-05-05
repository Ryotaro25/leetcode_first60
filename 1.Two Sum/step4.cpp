class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 100mおきの数字のインデックスを記録しつつtargetを超える大きさなのか、
        // target以下なのかの情報とtargetまであと何の数字が必要か書いて渡すと思います。
        map<int, int> numbers_to_index;
        for (int i = 0; i < numbers.size(); i++) {
            int remaining = target - numbers[i];
            numbers_to_index[remaining] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            int target_remaining = numbers[i];
            if (numbers_to_index.contains(target_remaining) && numbers_to_index[target_remaining] != i) {
                return {numbers_to_index[target_remaining], i};
            }
        }
        return {};
    }
};

