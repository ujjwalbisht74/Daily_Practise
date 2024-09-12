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
    TreeNode * solve(int  & index, vector<int>& preorder , unordered_map<int,int> & map , int low , int high){
        if(low > high) return nullptr;

        int val = preorder[index++];

        TreeNode * root = new TreeNode (val);

        root->left = solve(index, preorder, map, low, map[val]-1);
        root->right = solve(index, preorder, map,map[val]+1, high);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size= preorder.size();

        unordered_map<int,int>map;

        for(int i = 0 ; i < size; i++){
            map[inorder[i]] = i;
        }

        int index = 0;

        return solve(index , preorder , map, 0 , size-1);
    }
};