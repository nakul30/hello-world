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
class Solution {
public:

    long long totalSum = 0;
    long long answer = 0;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long currSum = root->val + left + right;

        long long product = currSum * (totalSum - currSum);
        answer = max(answer, product);

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);   // first DFS to get total sum
        answer = 0;
        dfs(root);              // second DFS to compute products
        return answer % 1000000007;
    }
};

