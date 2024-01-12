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
 //-------------- Approach 1 ---------------//
 //Bruite force

class Solution {
public:

    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight = findHeight(root->left);
        //if at any point, this call returns -1, then return -1 as tree is not balanced
        if(leftHeight==-1){
            return -1;
        }

        int rightHeight = findHeight(root->right);
        //if at any point, this call returns -1, then return -1 as tree is not balanced
        if(rightHeight==-1){
            return -1;
        }

        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        int ans = findHeight(root);
        if(ans!=-1){
            return true;
        }
        return false;
    }
};


//---------------- Approach 2 ----------------//
//optimised

class Solution {
public:

    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        if(abs(leftHeight-rightHeight)>1 || leftHeight==-1 || rightHeight==-1){
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        int ans = findHeight(root);
        if(ans!=-1){
            return true;
        }
        return false;
    }
};
