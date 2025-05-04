template <typename K, typename V>
struct node {
  string color; // red or black
  K key;
  V value;
  node* left = nullptr;
  node* right = nullptr;
  node* parent = nullptr;
};

template <typename K, typename V>
class red_black_tree {
public:
  red_black_tree() {
    nil = new node<K, V>;
    nil->color = "BLACK"; // Sentinel node
    root = nil;
  }

  V& operator[](const K& key) {
        node<K, V>* result = tree_search(root, key); // キーを検索
        if (result == nil) {
            // キーが存在しない場合は新たに挿入
            node<K, V>* new_node = new node<K, V>;
            new_node->key = key;
            new_node->value = V(); // デフォルト値で初期化（仮定）

            rb_insert(root, new_node);
            return new_node->value;
        } else {
            // キーが存在する場合はその値を返す
            return result->value;
        }
    }

  node<K, V>* tree_search(node<K, V>* x, const K& key) {
    if (x == nil || key == x->key) {
      return x;
    }
    if (key < x->key) {
      return tree_search(x->left, key);
    } else {
      return tree_search(x->right, key);
    }
  }

  node<K, V>tree_minimum(node<K, V>* x) {
    while (x->left != nil) {
      x = x->left;
    }
    return x;
  }

  void rb_insert(node<K, V>* t, node<K, V>* z) {
    node<K, V>* x = root;
    node<K, V>* y = nil;

    // 番兵に到達するまでループ
    while (x != nil) {
      y = x;
      if (z->key < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    z->parent = y;
    if (y == nil) {
      root = z;
    } else if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }

    z->left = nil;
    z->right = nil;
    z->color = "RED";
    rb_insert_fixup(t, z);
  }

  void rb_delete(node<K, V>* t, node<K, V>* z) {
    node<K, V>* x;
    node<K, V>* y = z;
    string y_original_color = y->color;

    if (z->left == nil) {
      x = z->right;
      // z を右側の子と入れ替える
      rb_transplant(t, z, z->right);
    } else if (z->right == nil) {
      x = z->left;
      // z を左側の子と入れ替える
      rb_transplant(t, z, z->left);
    } else {
      y = tree_minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y != z->right) {
        rb_transplant(t, y, y->right);
        y->right = z->right;
        y->right->parent = y;
      } else {
        x->parent = y;
      }
      rb_transplant(t, z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }

    if (y_original_color == "BLACK") {
      rb_delete_fixup(t, x);
    }
  }

  class iterator {
    private:
        node<K, V>* current;
        std::stack<node<K, V>*> stack;

    public:
        iterator(node<K, V>* root) {
            initializeStack(root);
        }

        iterator& operator++() {
            if (stack.empty()) {
                current = nullptr;
                return *this;
            }

            current = stack.top();
            stack.pop();
            initializeStack(current->right);
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        pair<const K, V> operator*() const {
          return {current->key, current->value};
        }

    private:
      void initializeStack(node<K, V>* start) {
          while (start != nullptr) {
              stack.push(start);
              start = start->left;
          }
      }
    };

    iterator begin() {
        return iterator(tree_minimum_node(root));
    }

    // endイテレータはnullptrを返す
    iterator end() {
        return iterator(nil);
    }

private:
  node<K, V>* root;
  node<K, V>* nil;

  node<K, V>* tree_minimum_node(node<K, V>* x) {
        while (x->left != nil) {
            x = x->left;
        }
        return x;
    }

  void left_rotate(node<K, V>* t, node<K, V>* x) {
    node<K, V>* y = x->right;
    x->right = y->left; // yの左部分木をxの右部分木に

    // yの左部分木がnilでないのならば、xを値の親とする
    if (y->left != nil) {
      y->left->parent = x;
    }
    y->parent = x->parent;

    // xが根であれば、yは根になる
    if (x->parent == nil) {
      root = y;
    // xが左の子であればyは左の子になる
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      // xが右の子であればyは右の子である
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void right_rotate(node<K, V>* t, node<K, V>* x) {
    node<K, V>* y =  x->left;
    x->left = y->right; // yの右部分木をxの左部分木に

    // yの右部分木がnilでないのならば、xをその親とする
    if (y->right != nil) {
        y->right->parent = x;
    }
    y->parent = x->parent;

    // xが根であれば、yは根になる
    if (x->parent == nil) {
        root = y;
    // xが左の子であればyは左の子になる
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        // xが右の子であればyは右の子になる
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
  }

  void rb_insert_fixup(node<K, V>* t, node<K, V>* z) {
    node<K, V>* y;
 
    while (z->parent->color == "RED") {
      if (z->parent == z->parent->parent->left) {
        // yはzの叔父
        y = z->parent->parent->right;

        // zの叔父がyが赤である場合
        if (y->color == "RED") {
          z->parent->color = "BLACK";
          y->color = "BLACK";
          z->parent->parent->color = "RED";
          z = z->parent->parent;
        } else {
          // zの叔父yが黒で、zが右の子供である場合
          if (z == z->parent->right) {
            z = z->parent;
            left_rotate(t, z);
          }
          // zの叔父yが黒で、zが左の子供である場合
          z->parent->color = "BLACK";
          z->parent->parent->color = "RED";
          right_rotate(t, z->parent->parent);
        }
      } else {
        y = z->parent->parent->left;
        // zの叔父がyが赤である場合
        if (y->color == "RED") {
          z->parent->color = "BLACK";
          y->color = "BLACK";
          z->parent->parent->color = "RED";
          z = z->parent->parent;
        } else {
          // zの叔父yが黒で、zが右の子供である場合
          if (z == z->parent->left) {
            z = z->parent;
            right_rotate(t, z);
          }
          // zの叔父yが黒で、zが左の子供である場合
          z->parent->color = "BLACK";
          z->parent->parent->color = "RED";
          left_rotate(t, z->parent->parent);
        }
      }
    }
    root->color = "BLACK";
  }
  
   void rb_delete_fixup(node<K, V>* t, node<K, V>* x) {
    node<K, V>* w;

    while (x != root && x->color =="BLACK") {
      if (x == x->parent->left) {
        w = x->parent->right;

        // xの兄弟wが赤の場合
        if (w->color == "RED") {
          w->color = "BLACK";
          x->parent->color = "RED";
          left_rotate(t, x->parent);
          w = x->parent->right;
        }

        // xの兄弟wもwの両方の子供も全て黒の場合
        if (w->left->color == "BLACK" && w->right->color =="BLACK") {
          w->color = "RED";
          x = x->parent;
        } else {
          // xの兄弟wは黒、wの左の子は赤、wの右の子は黒の場合
          if (w->right->color == "BLACK") {
            w->left->color = "BLACK";
            w->color = "RED";
            right_rotate(t, w);
            w = x->parent->right;
          }
          // xの兄弟wが黒で、wの右の子が赤の場合
          w->color = x->parent->color;
          x->parent->color = "BLACK";
          w->right->color = "BLACK";
          left_rotate(t, x->parent);
          x = root;
        }
      } else {
        // 左右を入れ替えたVer
        w = x->parent->left;
        // xの兄弟wが赤の場合
        if (w->color == "RED") {
          w->color = "BLACK";
          x->parent->color = "RED";
          right_rotate(t, x->parent);
          w = x->parent->left;
        }

        // xの兄弟wもwの両方の子供も全て黒の場合
        if (w->right->color == "BLACK" && w->left->color == "BLACK") {
          w->color = "RED";
          x = x->parent;
        } else {
          // xの兄弟wは黒、wの左の子は赤、wの右の子は黒の場合
          if (w->left->color == "BLACK") {
            w->right->color = "BLACK";
            w->color = "RED";
            left_rotate(t, w);
            w = x->parent->left;
          }
          // xの兄弟wが黒で、wの右の子が赤の場合
          w->color = x->parent->color;
          x->parent->color = "BLACK";
          w->left->color = "BLACK";
          right_rotate(t, x->parent);
          x = root;
        }
      }
    }
    x->color = "BLACK";
   }


  // 削除の際の部分木の置き換えを行う
  void rb_transplant(node<K, V>* t, node<K, V>* u, node<K, V>* v) {
    if (u->parent == nil) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        red_black_tree<string, vector<string>> sorted_to_group;
        for (auto& str : strs) {
            string anagram = str;
            sort(anagram.begin(), anagram.end());
            sorted_to_group[anagram].push_back(str);
        }

        vector<vector<string>> group_anagrams;
        for (const auto& [key, word_group] : sorted_to_group) {
          group_anagrams.push_back(move(word_group));
        }
        return group_anagrams;
    }
};
