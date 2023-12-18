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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base cases
        //if both trees are null, they are identical
        if(p == NULL && q == NULL){
            return true;
        }

        //if only one of the trees is null, they are not identical 
        if(p == NULL || q == NULL){
            return false;
        }
        //if the root nodes of both the trees are equal, recursively check if the left and right sbtrees are identical

        if(p->val == q->val){
            return isSameTree(p->left, q->left)  && isSameTree(p->right, q->right);
        }
        return false;
    }
};
