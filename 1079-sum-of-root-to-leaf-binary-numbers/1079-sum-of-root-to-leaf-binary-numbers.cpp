class Solution {
public:
    int result = 0;

    int convert(string s) {
        int num = 0;
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
        return num;
    }

    void solve(string s, TreeNode* root) {
        if (root == nullptr) return;

        s += to_string(root->val);

        // leaf node
        if (root->left == nullptr && root->right == nullptr) {
            result += convert(s);
            return;
        }

        solve(s, root->left);
        solve(s, root->right);
    }

    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) return 0;

        string s = to_string(root->val);
        solve(s, root->left);
        solve(s, root->right);
        if(root->left==nullptr && root->right ==nullptr){
            result += convert(s);
        }
        return result;
    }
};