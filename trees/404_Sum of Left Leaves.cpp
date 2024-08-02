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
//----------- Approach 1 -----------//
// DFS | Recursion
class Solution {
public:
    void helper(TreeNode* root, int& sum, bool isLeft){
       
        if(root==NULL){
            return;
        }
        
        if(isLeft==true && root->left==NULL && root->right==NULL){
            sum+= root->val;
        }

        helper(root->left, sum, true);
        helper(root->right, sum, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        bool isLeft = false;
        helper(root, sum, isLeft);
        return sum;
    }
};


//---------- Approach 2 ----------//
// BFS | Using queue

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                    if(node->left->left==NULL && node->left->right==NULL){
                        sum += node->left->val;
                    }
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};
