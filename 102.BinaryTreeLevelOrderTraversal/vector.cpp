/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
template <typename T> class MyVector {
public:
  // メンバ初期化子リストで初期化することで、デフォルトコンストラクタ→代入の処理ではなくなる
  // effective c++の4項オブジェクトは、使う前に初期化しようを参照
  MyVector() : arr(new T[1]), capacity(1), current(0) {}

  // newとdeleteの形は合わせておく、未定義を避けるため
  // effective c++の16項を参照
  ~MyVector() {
    delete[] arr;
  }

  // copy コンストラクター
  MyVector(const MyVector& other) : arr(new T[other.capacity]), capacity(other.capacity), current(other.current) {
    for (int i = 0; i < current; i++) {
      arr[i] = other.arr[i];
    }
  }

  // move コンストラクター
  MyVector(MyVector&& r) : arr(r.capacity), capacity(r.capacity), current(r.current) {
    // 元の右辺値を無効化
    r.arr = nullptr;
    r.capacity = 0;
    r.current = 0;
  }

  // copy assignment
  MyVector& operator=(const MyVector& other) {
    if (this != other) {
      delete[] arr;

      arr = new T[other.capacity];
      capacity = other.capacity;
      current = other.current;
      for (int i = 0; i < capacity; i++) {
        arr[i] = other.arr[i];
      }
    }
    return *this;
  }

  // move assignment
  MyVector& operator=(MyVector&& r) noexcept {
    if (this != &r) {
      delete[] arr;

      arr = r.arr;
      capacity = r.capacity;
      current = r.current;

      r.arr = nullptr;
      r.capacity = 0;
      r.current = 0;
    }
    return *this;
  }

  T& operator[] (int index) {
    if (index >= current || index < 0) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }

  void insert(T data, int index) {
    // arr[-3] などは無効
    if (index < 0 || index >= current) {
      throw std::out_of_range("Index out of range");
    }

    if (current >= capacity) {
      resize();
    }

    for (int i = current; i > index; --i) {
      arr[i] = arr[i - 1];
    }

    arr[index] = data;
    current++;
  }

  void push_back(T data) {
    if (current == capacity) {
      resize();
    }

    arr[current] = data;
    current++;
  }

  void resize() {
    T* temp = new T[2 * capacity];
    for (int i = 0; i < capacity; i++) {
      temp[i] = arr[i];
    }

    delete[] arr;
    capacity *= 2;
    arr = temp;
  }

private:
  T* arr;
  int capacity;
  int current;
}

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> level_to_values = {};
    if (!root) {
      return level_to_values;
    }

    vector<TreeNode*> current_level_nodes = {root};
    while (!current_level_nodes.empty()) {
      vector<int> values = {};
      vector<TreeNode*> next_level_nodes = {};

      for (const auto& node : current_level_nodes) {
        values.emplace_back(node->val);
        if (node->left) {
          next_level_nodes.emplace_back(node->left);
        }
        if (node->right) {
          next_level_nodes.emplace_back(node->right);
        }
      }
      level_to_values.emplace_back(values);
      current_level_nodes = next_level_nodes;
    }

    return level_to_values;
  }
};
