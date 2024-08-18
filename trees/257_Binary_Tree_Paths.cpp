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
//-------------- Approach 1 -------------//

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


//-------------- Approach 2 ----------------//

class Solution {
public:
    void findPaths(TreeNode* root, vector<string> &paths, string path){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            path += to_string(root->val);
            paths.push_back(path);
        }else{
            path += to_string(root->val) + "->";
            findPaths(root->left, paths, path);
            findPaths(root->right, paths, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        findPaths(root, paths, path);
        return paths;
    }
};
