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
        fill(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        fill(root, ans);
        return ans;
    }
};

//-------------- Approach 2 ---------------//
//Iterative Traversal

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        stack<TreeNode*> st;
        vector<int> ans;

        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr->left){
                st.push(curr->left);
                curr->left = NULL;
            }
            else{
                if(curr->right){
                    st.push(curr->right);
                    curr->right = NULL;
                }
                else{
                    ans.push_back(curr->val);
                    st.pop();
                }
            }
        }
        return ans;
    }
};


