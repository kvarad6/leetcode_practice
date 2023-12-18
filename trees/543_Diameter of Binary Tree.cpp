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

 // Brute force approach..

// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         int leftDiameter = diameterOfBinaryTree(root->left);
//         int rightDiameter = diameterOfBinaryTree(root->right);

//         int currentIncluded = height(root->left) + height(root->right);

//         return max(currentIncluded, max(leftDiameter, rightDiameter));
//     }

//     int height(TreeNode* root){
//         if(root==NULL){
//             return 0;
//         }
//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);

//         return 1 + max(leftHeight, rightHeight);
//     }
// };

//Optimal approach:

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* root, int& diameter){
        if(root==NULL){
            return 0;
        }

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        diameter = max(diameter, leftHeight+rightHeight);
        return 1+max(leftHeight, rightHeight);
    }

   
};
