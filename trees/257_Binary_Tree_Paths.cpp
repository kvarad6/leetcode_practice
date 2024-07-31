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
    void helper(TreeNode* root, vector<string>& paths, string currentStr){
       if(root==NULL){
        return;
       }
        if(root->left!=NULL || root->right!=NULL){
            currentStr += to_string(root->val) + "->";
        }else{
            currentStr += to_string(root->val);
            paths.push_back(currentStr);
        }
        helper(root->left, paths, currentStr);
        helper(root->right, paths, currentStr);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string currentStr = "";
        vector<string> paths;
        helper(root, paths, currentStr);
        return paths;
    }
};
