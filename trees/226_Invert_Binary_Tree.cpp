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
//Using inbuilt swap function
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        //edge cases
        if(root==NULL){
            return NULL;
        }

        //invert left subtree
        invertTree(root->left);

         //invert right subtree
        invertTree(root->right);

        swap(root->left, root->right);

        return root;
    }
};


//----------- Approach 2 -----------//
//Using iterative swapping of nodes
class Solution {

    void invertNode(TreeNode* node){
        //edge cases
        if(node==NULL){
            return;
        }
        //swap the nodes
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        //invert left subtree
        invertNode(node->left);
        invertNode(node->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {

        invertNode(root);
        return root;
    }
};
