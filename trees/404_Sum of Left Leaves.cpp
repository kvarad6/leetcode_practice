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
int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        sumHelper(root, false);
        return sum;
    }

    void sumHelper(TreeNode* node, bool isLeft){
        if(node==NULL){
            return;
        }
        //if node is a leaf node and a left node
        if(isLeft && node->left == NULL && node->right == NULL){
            sum += node->val;
            return;
        }
        sumHelper(node->left, true);
        sumHelper(node->right, false);
    }
};
