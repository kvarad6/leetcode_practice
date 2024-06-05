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
// Using recursion | target-root->val
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val==targetSum ? true : false;
        }

        bool leftSum = hasPathSum(root->left, targetSum - root->val);
        bool rightSum = hasPathSum(root->right, targetSum - root->val);

        if(leftSum==true || rightSum==true){
            return true;
        }
        return false;
    }
};



//----------- Approach 2 -----------//
// Using recursion | sum += root->val
class Solution {
public:
    bool checkSum(TreeNode* root, int targetSum, int sum){
         if(root==NULL){
            return false;
        }

        if(root->left==NULL && root->right==NULL){
            sum += root->val;
            if(sum==targetSum){
                return true;
            }
        }

        bool leftSum = checkSum(root->left, targetSum, sum + root->val);
        bool rightSum = checkSum(root->right, targetSum, sum + root->val);

        if(leftSum==true || rightSum==true){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       int sum = 0;
       return checkSum(root, targetSum, sum);
    }
};


//-------- Approach 3 ---------//
//Iterative solution
//using stack

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root==NULL){
            return false;
        }
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        while(!st.empty()){
            auto node = st.top();
            TreeNode* currentNode = node.first;
            int currentSum = node.second;
            st.pop();
            if(currentNode->left==NULL && currentNode->right==NULL){
                currentSum += currentNode->val;
                if(currentSum==targetSum){
                    return true;
                }
            }

            if(currentNode->left!=NULL){
                st.push({currentNode->left, currentSum+currentNode->val});
            }
            if(currentNode->right!=NULL){
                st.push({currentNode->right, currentSum+currentNode->val});
            } 
        }
        return false;
    }
};



//-------- Approach 3 ---------//
//Iterative solution
//pending
