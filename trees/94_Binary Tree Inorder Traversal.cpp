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

 //--------------- Approach 1 ------------------//
 //Recursive Traversal

class Solution {
public:

    void fill(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        fill(root->left, ans);
        ans.push_back(root->val);
        fill(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        fill(root, ans);
        return ans;
    }
};

//-------------- Approach 2 ---------------//
//Iterative Traversal

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root!=NULL){
                st.push(root);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

//pending: morris alg..
