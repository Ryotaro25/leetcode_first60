/*
1.問題のモデル化
ターゲットより大きいのか、以下なのか2つ以上の相補的な状態に分類することができるのでfalseとtrueの問題とみなす。
記問題を解くにあたり、対象の位置を含む区間をstartからendとして定義する。

2.探索空間の定義
今回は閉区間として探索を行う。

3.初期値の設定
startを0、endを配列の最後の要素nums.size() - 1として探索する。
配列の全要素を探索するイメージ。

4.ループ不変条件の設定
startとendの真ん中をmiddleとして、ループの普遍条件は
・start <= middle < end

5.探索ロジックの設計
nums[middle] < targetがtrueであれば、middleより左側にtargetは存在しないので
startをmiddle + 1に更新

nums[mid] >= target の場合、 mid の位置に対象がある場合があるため、
区間を狭めつつ mid を区間内に含めるため、end = mid とする

6.検証
・targetがnumsのいずれよりも小さい場合
  nums[middle] < targetが常にfalseとなり、startは最初の位置のままendが狭まりstartの位置が解となる

・targetがnumsのいずれよりも大きい場合
  nums[middle] < targetが常にtrueとなり、startがendに近づきstart + 1

・targetが複数存在する場合
  最小のインデックスを返却

7.実行
leet codeにて動作確認

*/
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return SearchInsertIndex(0, nums.size() - 1, nums, target);
  }

private:
  int SearchInsertIndex(int start, int end, vector<int>& nums, int target) {
    if (start == end) {
      if (nums[start] >= target) {
        return start;
      } else {
        return start + 1;
      }
    }
    int middle = start + (end - start) / 2;

    if (nums[middle] < target) {
      return SearchInsertIndex(middle + 1, end, nums, target);
    } else {
      return SearchInsertIndex(start, middle, nums, target);
    }
  }
};
