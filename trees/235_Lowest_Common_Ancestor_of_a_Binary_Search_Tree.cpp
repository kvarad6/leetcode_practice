/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//---------------- Approach 1 --------------------//

/*
Various conditions that to be handled:
lets 'a' and 'b' are two nodes whose lowest common ancessator to be find out
1. if current node is a or b
2. if 'a' is in left subtree and 'b' is in right subtree
3. both 'a' and 'b' is any one subtree
4. None of 'a' and 'b' in any subtree
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //edge case
        if(root==NULL){
            return NULL;
        }
        //if current node/ root is p/q, then it itself a lowest ancestor
        if(root==p || root==q){
            return root;
        }

        //check if you find anything in left subtree
        TreeNode* leftSideNode = lowestCommonAncestor(root->left, p, q);
        //transverse right subtree
        TreeNode* rightSideNode = lowestCommonAncestor(root->right, p, q);

        //if left subtree does not return anything/ p/q not present in left subtree
        if(leftSideNode==NULL){
            return rightSideNode;
        }
        //if right subtree does not return anything/ p/q not present in right subtree
        if(rightSideNode==NULL){
            return leftSideNode;
        }
        //if we found one among p/q in left subtree and other in right subtree, then the current node is lowest common ancestor
        return root;
    }
};




//------------------ Approach 2 ------------------//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        int current = root->val;
        if(p->val<current && q->val<current){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val>current && q->val>current){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
