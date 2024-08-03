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
//------------- Approach 1 ---------------//
 // Brute force approach..

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        int currentIncluded = height(root->left) + height(root->right);

        return max(currentIncluded, max(leftDiameter, rightDiameter));
    }

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
};

//--------------- Approach 2 ----------------//
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


//---------------- Approach 3 ---------------------//
// Calculating diameter for each node, keeping track of the longest one.
// diameter = height of left tree + height of right tree
/*
    Finding max diameter from 3 possible cases:
    Starting from root,
    1. max diameter can be present in the left subtree
        leftDiameter = diameterOfBinaryTree(root->left)

    2. max diameter can be present in the right subtree
        rightDiameter = diameterOfBinaryTree(root->right)

    3. max diameter can pass through node
        leftHeight = height(root->left)
        rightHeight = height(root->right)
        diameter = leftHeight + rightHeight + 1
*/
//TC: O(N^2) | Not eficient

class Solution {
public:
    int findHeight(TreeNode* node){
        if(node==NULL){
            return 0;
        }
       return 1+max(findHeight(node->left), findHeight(node->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        int rootDiameter = leftHeight + rightHeight;
        return max(rootDiameter, max(leftDiameter, rightDiameter));
    }
};
