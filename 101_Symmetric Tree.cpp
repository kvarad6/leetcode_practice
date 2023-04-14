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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        } 
        return isSymmetricHelp(root->left, root->right);

    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        //if left and right node are null
        if(left==NULL && right==NULL){
            return true;
        }
        
        //if one of the nodes (between left and right are null)
        else if(left==NULL || right==NULL){
            return false;
        }

        //if value of left node is not equal to right one,
        if(left->val != right->val){
            return false;
        }

        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    } 
};
