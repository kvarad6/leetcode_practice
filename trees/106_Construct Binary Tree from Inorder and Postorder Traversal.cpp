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
Steps followed and imp points:


--> Select last node from postorder array which is root 
--> find that node in inorder array (which is used as hashmap), and left nodes of that becomes left subtree and right nodes of that becomed right subtree.

In inorder array, 
numsLeft = inRoot - inStart 
------------------------------------
for root->left : 
inorder traversal:
inStart = inStart
inEnd = inroot - 1
============
postorder traversal:
postStart = postStart
postEnd = postStart + numsLeft - 1

---------------------------------------

for root->right :
inorder traversal:
inStart = inroot + 1
inEnd = inEnd
================
postorder traversal:
postStart: postStart + numsLeft
postEnd = postEnd

*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //we are trying to use inorder vector as a hashmap, and find root, left-right subtree in it.
        //declaring a map and putting all inorder in map
        if(inorder.size()!=postorder.size()){
            return NULL;
        }

        map<int, int> mpp;

        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = construct(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1 ,mpp);
        
            return root;
        
    }

    TreeNode* construct(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int> &mpp){
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        } 

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[postorder[postEnd]];
        int numsLeft = inRoot-inStart;

        root->left = construct(inorder,inStart,inRoot-1, postorder, postStart, postStart+numsLeft-1, mpp);
        root->right = construct(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, mpp);

        return root;

    }
};
