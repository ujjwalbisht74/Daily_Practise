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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return {};

        queue<TreeNode  *> q;

        q.push(root);

        while(q.size()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                TreeNode* front = q.front() ; q.pop();
                temp.emplace_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            res.emplace_back(temp);
        }

        return res;
    }
};