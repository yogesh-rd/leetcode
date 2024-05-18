struct Counts {
  int nodes;
  int coins;

  Counts(int nodes, int coins) : nodes(nodes), coins(coins) {}
};

class Solution {
private:
  int ret = 0;
  Counts dfs(TreeNode *root) {
    if (!root)
      return Counts(0, 0);

    Counts left = dfs(root->left);
    Counts right = dfs(root->right);

    ret += abs(left.nodes - left.coins);
    ret += abs(right.nodes - right.coins);

    return Counts(left.nodes + right.nodes + 1,
                  left.coins + right.coins + root->val);
  }

public:
  int distributeCoins(TreeNode *root) {
    dfs(root);
    return ret;
  }
};