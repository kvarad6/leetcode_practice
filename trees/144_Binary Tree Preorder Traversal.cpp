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
 //TC: O(N)
 //SC: O(N)

class Solution {
public:

    void fill(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        fill(root->left, ans);
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
//TC: O(N)
 //SC: O(N)

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root!=NULL){
                st.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return ans;
    }
};

//-------------- Approach 3 -------------//
//Morris Alg
//TC: O(N)
//SC: O(1)

