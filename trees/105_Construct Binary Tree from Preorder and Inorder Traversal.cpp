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
class Solution {
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        //declaring a hashmap and putting the inorder traversal in the hashmap to find the root optimally.
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

    TreeNode* construct(vector<int>&preorder, int preStart, int preEnd, vector<int> &inorder,int inStart, int inEnd, map<int,int> &mp){

        //As long as we have some preorder/postorder
        if(preStart>preEnd || inStart>inEnd) return NULL;

        //Creating a root
        //Starting element of the preorder will be the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        //Figure out the inroot from map and the no. of left subtree elements..
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inStart;

        //Use recursion to find left, right subtree roots in order to build the same.
         root->left = construct(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right = construct(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }

};
