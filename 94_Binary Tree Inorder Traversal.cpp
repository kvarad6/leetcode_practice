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


/*
 //Recursive approach 

class Solution {
public:
    vector<int> ans;
    void fill(TreeNode* root){
        if(!root)
            return;
        
        fill(root->left);
        ans.push_back(root->val);  // Inorder
        fill(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        fill(root);
        return ans;
    }
};
*/

//Iterative approach

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorderTraversal;

        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()==true){
                    break;
                }
                node = st.top();
                st.pop();
                inorderTraversal.push_back(node->val);
                node = node->right;
            }
        }
        return inorderTraversal;
        }
};
