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
//TC: O(N)
//SC: O(N)

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

//-------------- Approach 3 -------------//
//Morris Alg | Threaded Binary Tree
//TC: O(N)
//SC: O(1)

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                //if left exist, go to the rightmost node of the left subtree
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                //if thread/ link between rightmost and current does not exist, create one
                    if(prev->right==NULL){
                        prev->right = curr;
                        curr = curr->left;
                    }
                //if the thread already exist, break it and push the curr to the array.
                    else{
                        prev->right = NULL;
                        inorder.push_back(curr->val);
                        curr = curr->right;
                    }
                }
        }
        return inorder;
    }
};
