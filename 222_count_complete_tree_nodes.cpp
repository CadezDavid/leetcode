#include <cmath>
#include <iostream>

// Given the root of a complete binary tree, return the number of the nodes in
// the tree.
//
// According to Wikipedia, every level, except possibly the last, is completely
// filled in a complete binary tree, and all nodes in the last level are as far
// left as possible. It can have between 1 and 2h nodes inclusive at the last
// level h.
//
// Design an algorithm that runs in less than O(n) time complexity.
//
//
//
// Example 1:
//
// Input: root = [1,2,3,4,5,6]
// Output: 6
//
// Example 2:
//
// Input: root = []
// Output: 0
//
// Example 3:
//
// Input: root = [1]
// Output: 1
//
//
//
// Constraints:
//
//     The number of nodes in the tree is in the range [0, 5 * 104].
//     0 <= Node.val <= 5 * 104
//     The tree is guaranteed to be complete.

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root) return 0; // Fix 1: Handle empty tree

    int depth = 0;
    TreeNode *curr = root;
    while (curr->left != nullptr) {
      depth++;
      curr = curr->left;
    }

    int left_ptr = 0;
    int right_ptr = (1 << depth); // 2^depth

    while (left_ptr + 1 < right_ptr) {
      int middle = left_ptr + (right_ptr - left_ptr) / 2;
      TreeNode *node = root;
      
      for (int i = 0; i < depth; i++) {
        // Fix 2: Shift from depth-1 down to 0
        if ((middle >> (depth - 1 - i)) & 1) {
          node = node->right;
        } else {
          node = node->left;
        }
        if (!node) break; 
      }

      if (node == nullptr) {
        right_ptr = middle;
      } else {
        left_ptr = middle;
      }
    }

    // Fix 3: Correct mathematical formula
    return (1 << depth) + left_ptr;
  }
};

int main() {
  Solution sol;
  TreeNode *tree =
      new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)),
                   new TreeNode(2, new TreeNode(5), new TreeNode(6)));
  std::cout << sol.countNodes(tree) << std::endl;

  return 0;
}
