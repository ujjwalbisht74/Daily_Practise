/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode * solve(ListNode * l ,  ListNode * r){
        if(l == r) return nullptr;

        ListNode * slow = l , * fast = l;

        while(fast != r && fast->next != r ){
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode * root  = new TreeNode (slow->val);

        root->left = solve(l , slow);
        root->right = solve(slow->next ,r);

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head, nullptr); 
    }
};