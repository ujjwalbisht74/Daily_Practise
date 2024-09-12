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
    void rev_inorder(TreeNode * root, int  & sum){
        if(root){
            rev_inorder(root->right , sum);
            sum +=root->val;
            root->val = sum;
            rev_inorder(root->left,sum);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0 ;
        rev_inorder(root,sum);
        return root;
    }
};