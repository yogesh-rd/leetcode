class Solution {
public:
  bool evaluateTree(TreeNode *root) {
    if (root->val <= 1)
      return root->val;

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    return root->val == 2 ? left || right : left & right;
  }
};