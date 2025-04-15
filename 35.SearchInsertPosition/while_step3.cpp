/*
1.問題のモデル化
numsの各要素をターゲット未満かターゲット以上であるかの2種類に分類する
ターゲット未満であればfalse、ターゲット以上であればtrueと見なす。

例えばnums = [1,3,5,6], target = 5　を用いると
nums = [false, false, true, true]と表すことができる
この中で一番左の true の位置を探す。

2.探索空間の定義
今回は半開区間として探索を行う。

3.初期値の設定
leftを0、rightを配列の最後の要素nums.size()とする。

4.ループ不変条件の設定
left < right、[left, right)に解が含まれている。

5.探索ロジックの設計
leftとrightの真ん中をmiddleと置く。
nums[middle] < target の場合、middleおよびその左側にtargetは存在しないので
leftをmiddle + 1に更新する。

nums[mid] >= target の場合、 mid の位置に対象がある場合があるため、
区間を狭めつつ mid を区間内に含めるため、right = mid とする。

6.検証
・targetがnumsのいずれよりも小さい場合
  nums[middle] < targetが常にfalseとなり、leftは最初の位置のままrightが狭まりleftの初期位置が解となる

・targetがnumsのいずれよりも大きい場合
  nums[middle] < targetが常にtrueとなり、leftがrightに近づきnumsの外側が挿入位置となる。

・targetに該当するnumが複数存在する場合
  最小のインデックスを返却

7.実行
leet codeにて動作確認

*/
class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      int left = 0;
      // numsの最後の要素の右側が挿入位置になる可能性がある
      int right = nums.size();

      // leftに挿入位置を寄せていく
      while (left < right) {
        int middle = left + (right - left) / 2;
  
        if (nums[middle] < target) {
          left = middle + 1;
        } else {
          right = middle;
        }
      }
  
      return left;
    }
  };
