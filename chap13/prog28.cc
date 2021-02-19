#include <string>

class TreeNode {
 public:
  explicit TreeNode(std::string v = std::string(), TreeNode* l = nullptr,
    TreeNode *r = nullptr) : value(v), count(new int(1)), left(l), right(r) {}
  TreeNode(const TreeNode& tn) : value(tn.value), left(tn.left),
    right(tn.right), count(tn.count) {
    ++*tn.count;
  }
  TreeNode& operator=(const TreeNode& tn) {
    ++*tn.count;
    if (--*count == 0) {
      if (left) {
        delete left;
        left = nullptr;
      }
      if (right) {
        delete right;
        right = nullptr;
      }
      delete count;
    }
    left = tn.left;
    right = tn.right;
    count = tn.count;
    return *this;
  }
  ~TreeNode() {
    if (--*count == 0) {
      if (left) {
        delete left;
        left = nullptr;
      }
      if (right) {
        delete right;
        right = nullptr;
      }
      delete count;
    }
  }

 private:
  std::string value;
  int *count;
  TreeNode *left, *right;
};

class BinStrTree {
 public:
  BinStrTree() : root(new TreeNode()) { }
  BinStrTree(const BinStrTree& bs) : root(new TreeNode(*bs.root)) { }
  BinStrTree& operator=(const BinStrTree &bst) {
    TreeNode* tn = new TreeNode(*bst.root);
    delete root;
    root = tn;
    return *this;
  }
  ~BinStrTree() { delete root; }
 private:
  TreeNode* root;
};

