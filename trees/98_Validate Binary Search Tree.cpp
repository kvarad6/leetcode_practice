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

//can be solved by considering range for each node
//the nodes present in left subtree are in range --> longmin to root
//the nodes present in right subtree are in range --> root to longmax

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return help(root, LONG_MIN, LONG_MAX);
    }

    //Here, we have used long intstead of int as the constraint given is from -2^31 to 2^31-1, and INT_MAX = 2^31-1 and INT_MIN = -2^31.

    bool help(TreeNode* root, long min, long max){
        // root==NULL is same as !root
        if(root == NULL){
            return true;
        }
        //if value of root is not in the range
        if(root->val>=max || root->val<=min){
            return false;
        }

        return help(root->left, min, root->val) && help(root->right, root->val, max);
    }
};


