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
//----------- Approach 1 ------------//
//Using DFS | Helper function
class Solution {
public:
    TreeNode* checkNode(TreeNode* root, int val){

        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        if(root->val>val){
            return checkNode(root->left, val);
        }
        else{
            return checkNode(root->right, val);
        }
        return NULL;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        TreeNode* nodeStatus;
        nodeStatus = checkNode(root, val);
        return nodeStatus;
    }
};



//------------ Approach 2 --------------//
//Using DFS | Without any helper function
class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        //Using BST property | Binary Search
        if(root->val>val){
            return searchBST(root->left, val);
        }
        else if(root->val<val){
            return searchBST(root->right, val);
        }
        else{
            return root;
        }
    }
};


//------------ Approach 3 --------------//
//Using BFS | Level order traversal
class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
       if(root==NULL){
        return NULL;
       }
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            if(node->val == val){
                return node;
            }
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
       }
       return NULL;
    }
};
