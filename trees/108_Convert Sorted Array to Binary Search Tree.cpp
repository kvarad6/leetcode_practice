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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }

    TreeNode* buildBST(vector<int>& nums, int left, int right){
        //If the array is empty, return null.
        if(left>right){
            return NULL;
        }
        //Find the middle element of the array and create a new node with its value.
        //Can also be written as: 
        //int middle = left + (right-left)/2;      //As at first, when finding the middle of array, left is 0, right is the last index
        int middle = (left+right)/2;
        TreeNode* root = new TreeNode(nums[middle]);

        //Recursively construct the left subtree using the left half of the array and set the left child as root of left subtree
        root->left = buildBST(nums, left, middle-1);

        //Recursively construct the right subtree using the right half of the array and set the right child as root of right subtree
        root->right = buildBST(nums, middle+1, right);

        //Return the root node.
        return root;
    }
};
