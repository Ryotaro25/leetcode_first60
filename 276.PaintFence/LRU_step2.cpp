class Node {
public:
  int key;
  int value;
  Node* prev;
  Node* next;
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class MyLRUCache {
public:
  MyLRUCache(int size) : limit(size), size(0) {
    sentinel = new Node(-1, -1);
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
  }

  ~MyLRUCache() {
    delete sentinel;
  }

  int Get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;
    }
    Node* node = cache[key];
    int value = node->value;
    Remove(key);
    Put(key, value);
    return value;
  }

  void Put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      Remove(key);
    }
    Node* node = new Node(key, value);
    Node* head = sentinel->next;
    sentinel->next = node;
    node->next = head;
    head->prev = node;
    node->prev = sentinel;
    cache[key] = node;
    size++;
    if (size > limit) {
      Remove(sentinel->prev->key);
    }
  }

private:
  // 今回はhashなので
  unordered_map<int, Node*> cache;
  int limit;
  int size;
  Node* sentinel;

  void Remove(int key) {
    Node* node = cache[key];
    node->prev->next = node->next;
    node->next->prev = node->prev;
    cache.erase(key);
    delete node;
    size--;
  }
};

class Solution {
public:
  int numWays(int num_posts, int num_colors) {
    MyLRUCache cache(1000);
    cache.Put(1, num_colors);
    cache.Put(2, num_colors * num_colors);

    return CountNumWays(num_posts, num_colors, cache);
  }

private:
  int CountNumWays(int num_posts, int num_colors, MyLRUCache& cache) {
    if (num_posts == 1) {
      return num_colors;
    }
    if (num_posts == 2) {
      return num_colors * num_colors;
    }

    int colors_ways = cache.Get(num_posts);
    if (colors_ways != -1) {
      return colors_ways;
    }

    int same_pattern_ways = CountNumWays(num_posts - 2, num_colors, cache);
    int different_pattern_ways = CountNumWays(num_posts - 1, num_colors, cache);
    colors_ways = (num_colors - 1) * (same_pattern_ways + different_pattern_ways);
    cache.Put(num_posts, colors_ways);
    return colors_ways;
  }
};
