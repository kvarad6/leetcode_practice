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
    bool isBalanced(TreeNode* root) {
        int ans = findHeight(root);
        if(ans!=-1){
            return true;
        }
        return false;
    }

    int findHeight(TreeNode* node){
        //base case 
        if(node==NULL){
            return 0;
        }
        int leftHeight = findHeight(node->left);
        if(leftHeight == -1){
            return -1;
        }
        int rightHeight = findHeight(node->right);
        if(rightHeight == -1){
            return -1;
        }
        
        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};
