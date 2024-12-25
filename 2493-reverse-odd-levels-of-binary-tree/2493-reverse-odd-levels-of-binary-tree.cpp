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
    void clearQueue(std::queue<TreeNode*>& q) {
        while (!q.empty()) {
            q.pop(); 
        }

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> partial;
        queue<TreeNode*>pendingNodes;
        pendingNodes.push(root);
        bool odd=true;
        while(!pendingNodes.empty()){
            int size=pendingNodes.size();
            vector<int>arr;
            for(int i=0;i<size;i++){
                TreeNode* front=pendingNodes.front();pendingNodes.pop();
                arr.push_back(front->val);

                if(front->left){
                    pendingNodes.push(front->left);
                }
                if(front->right){
                    pendingNodes.push(front->right);
                }

            }
            if(!odd){
                reverse(arr.begin(),arr.end());
            }
            for(int j=0;j<arr.size();j++){
                partial.push_back(arr[j]);
            }
            odd=!odd;
        }
        int i=0;
        clearQueue(pendingNodes);
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode*front = pendingNodes.front();
            pendingNodes.pop();
            front->val=partial[i++];
            if(front->left){
                pendingNodes.push(front->left);
            }
            if(front->right){
                pendingNodes.push(front->right);
            }
        }
        return root;

    }
};