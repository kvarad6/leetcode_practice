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
//------------ Approach 1 ------------//
//Inplace merging | without creating new tree | modifying root1
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1){
            return root2;
        }
        if(!root2){
            return root1;
        }
        if(!root1 && !root2){
            return nullptr;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

//----------- Approach 2 ---------------//
//Creating new tree | using extra space
class Solution {
public:

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL){
            return root2;
        }
        if(root2==NULL){
            return root1;
        }
        TreeNode* newRoot = new TreeNode(root1->val + root2->val);

        newRoot->left = mergeTrees(root1->left, root2->left);
        newRoot->right = mergeTrees(root1->right, root2->right);
        
        return newRoot;
    }
};

//------------ Appraoch 3 ---------------//
//Creating new tree | using extra space
class Solution {
public:

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        if(root1==NULL){
            return root2;
        }
        if(root2==NULL){
            return root1;
        }

        int val1 = root1?root1->val:0;
        int val2 = root2?root2->val:0;
        
        // root1->val += root2->val;
        TreeNode* newRoot = new TreeNode(val1 + val2);
        newRoot->left = mergeTrees(root1?root1->left:NULL, root2?root2->left:NULL);
        newRoot->right = mergeTrees(root1?root1->right:NULL, root2?root2->right:NULL);
        return newRoot;
    }
};
