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

//------------ Approach 1 -------------//
// DFS | Recursion 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        } 
        return isSymmetricHelp(root->left, root->right);

    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        //if left and right node are null
        if(left==NULL && right==NULL){
            return true;
        }
        
        //if one of the nodes (between left and right are null)
        else if(left==NULL || right==NULL){
            return false;
        }

        //if value of left node is not equal to right one,
        if(left->val != right->val){
            return false;
        }

        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    } 
};


//----------- Approach 2 ------------//
// BFS | Queues

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        if(root->left==NULL && root->right==NULL){
            return true;
        }

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);

        while(!q1.empty() && !q2.empty()){
            TreeNode* left = q1.front();
            q1.pop();

            TreeNode* right = q2.front();
            q2.pop();

            if(left==NULL && right==NULL){
                continue;
            }

            if(left==NULL || right==NULL){
                return false;
            }

            if(left->val!=right->val){
                return false;
            }

            q1.push(left->left);
            q2.push(right->right);

            q1.push(left->right);
            q2.push(right->left);
            
        }
        return true;
    }
};
