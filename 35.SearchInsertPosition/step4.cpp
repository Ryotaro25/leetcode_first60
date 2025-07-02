/*
1.問題のモデル化
numsの各要素をターゲット未満かターゲット以上であるかの2種類に分類する
ターゲット未満であればfalse、ターゲット以上であればtrueと見なす。

例えばnums = [1,3,5,6], target = 5　を用いると
nums = [false, false, true, true]と表すことができる
この中で一番左の true の位置を探す。

2.探索空間の定義
今回は閉区間として探索を行う。

3.初期値の設定
startを0、endを配列の最後の要素nums.size() - 1とする。

4.ループ不変条件の設定
startとendの真ん中をmiddleとして、ループの不変条件は
start < end、start <= middle、middle <= end 

5.探索ロジックの設計
nums[middle] < target の場合、middleおよびその左側にtargetは存在しないので
startをmiddle + 1に更新する。

nums[mid] >= target の場合、 mid の位置に対象がある場合があるため、
区間を狭めつつ mid を区間内に含めるため、end = mid とする。

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
