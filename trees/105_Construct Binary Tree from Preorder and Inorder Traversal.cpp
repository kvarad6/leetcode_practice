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
        //declaring a hashmap and putting the inorder traversal in the hashmap to find the root optimally.
        map<int, int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap){
        //As long as we have some preorder/postorder
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        } 

        //Creating a root
        //Starting element of the preorder will be the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        //Figure out the inroot from map and the no. of left subtree elements..
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        //Use recursion to find left, right subtree roots in order to build the same.
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot-1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot+1, inEnd, inMap);

        return root;
    }

};
