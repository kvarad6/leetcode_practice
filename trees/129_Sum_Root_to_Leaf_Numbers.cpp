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
//------------ Approach 1 ------------//
//Recursive Solution | DFS 
class Solution {
public:
    int totalSum = 0;
    void sumNodes(TreeNode* root, int currentSum){
        if(root==NULL){
            return;
        }
        currentSum = currentSum*10 + root->val;
        //when you reached to leaf node 
        if(root->left==NULL && root->right==NULL){
            totalSum += currentSum;
            return;
        }
        //visiting nodes on left subtree
        sumNodes(root->left, currentSum);

        //visiting nodes on right subtree, starting from root again, with currentSum = 0
        sumNodes(root->right, currentSum);
    }

    int sumNumbers(TreeNode* root) {
        int currentSum = 0;
        sumNodes(root, currentSum);

        return totalSum;
    }
};