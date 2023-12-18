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
    bool isValidBST(TreeNode* root) {
        return help(root, LONG_MIN, LONG_MAX);
    }

    bool help(TreeNode* root, long min, long max){
        // root==NULL is same as !root
        if(root == NULL){
            return true;
        }
        //if value of root is not in the range
        if(root->val>=max || root->val<=min){
            return false;
        }

        return help(root->left, min, root->val) && help(root->right, root->val, max);
    }
};


