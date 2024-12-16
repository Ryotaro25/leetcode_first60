/*
1.問題のモデル化
num[middle] < targetとなる区間をfalse、num[middle] >= targetとなる部分をtrueとすると
問題を2つ以上の相補的な状態に分類することができる。

2.探索空間の定義
今回は閉区間として探索を行う。

3.初期値の設定
startを0、endを配列の最後の要素nums.size() - 1として探索する。
配列の全要素を探索するイメージ。

4.ループ不変条件の設定
>閉区間の探索では、範囲が無効（start > end）になる前に終了するのが基本(chat gpt)
start~endの中に挿入位置が存在すること=閉区間である
start > endを終了条件にすると、探索の範囲が[2, 1]であったり[0, -1]のような状態となり
start~endの中に挿入位置が存在することと矛盾する

5.探索ロジックの設計
nums[mid] < targetがtrueなら、startをmiddle + 1に更新
nums[mid] >= targetがtrueなら、endをmiddleに更新
  endをmiddle - 1に更新してしまうと、start > endが発生しうる

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
    // [2, 4, 4, 4, 6] target = 4の場合
    // 問題が最小のインデックスを探すであれば誤ってしまうので以下の部分は削除
    // if (nums[middle] == target) {
    //   return middle;
    // }

    if (nums[middle] < target) {
      return SearchInsertIndex(middle + 1, end, nums, target);
    } else {
      return SearchInsertIndex(start, middle, nums, target);
    }
  }
};
