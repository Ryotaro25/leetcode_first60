/*
1.問題のモデル化
ターゲットより大きいのか、以下なのか2つの状態に分類することができるのでtrueとfalseの問題とみなす。
記問題を解くにあたり、対象の位置を含む区間をstartからendとして定義する。

2.探索空間の定義
探索範囲を0からnとして、半開区間とみなし探索を行う。
ターゲットより大きい場合をtrueとして[true)となる箇所を探す。

3.初期値の設定
startを0、endをnums.size()として探索する。

4.ループ不変条件の設定
startとendの真ん中をmiddleとして、ループの普遍条件は
・start <= middle < end
・start <= target < end

5.探索ロジックの設計
nums[middle] < targetがtrueであれば、middleより左側にtargetは存在しないので
startをmiddle + 1に更新

nums[middle] >= targetがtrueであれば、middleを含めmiddle以下のどこかにtargetは存在するので
ループ不変条件を守るように[start, middle)となるように範囲を狭める。

6.検証
・targetがnumsのいずれよりも小さい場合
  nums[middle] < targetが常にfalseとなり、startは最初の位置のままendが狭まりstartの位置が解となる

・targetがnumsのいずれよりも大きい場合
  nums[middle] < targetが常にtrueとなり、startがendに近づく、start <= target < endとなっているので
  startの位置が解となる

・targetが複数存在する場合
  最小のインデックスを返却

7.実行
leet codeにて動作確認

*/
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return SearchInsertIndex(0, nums.size(), nums, target);
  }

private:
  int SearchInsertIndex(int start, int end, vector<int>& nums, int target) {
    if (start == end) {
      return start;
    }
    int middle = start + (end - start) / 2;

    if (nums[middle] < target) {
      return SearchInsertIndex(middle + 1, end, nums, target);
    } else {
      // nums[middle] >= target
      return SearchInsertIndex(start, middle, nums, target);
    }
  }
};
