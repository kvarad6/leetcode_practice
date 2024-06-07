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
// Using BFS | level order traversal
// TC: O(N)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int countNodes = 0;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            countNodes++;
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }

            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        return countNodes;
    }
};

//--------- Approach 2 ----------//
// Using DFS | Recursion
// TC: O(N)
// SC: O(height of tree), as it is complete binary tree, height-> log(N)
class Solution {
public:
    void countHelper(TreeNode* root, int &countNodes){
        if(root==NULL){
            return;
        }
        countNodes++;
        countHelper(root->left, countNodes);
        countHelper(root->right, countNodes);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int countNodes = 0;
        countHelper(root, countNodes);
        return countNodes;
    }
};

//--------- Approach 3 ----------//
// Using DFS | Recursion
// TC: O(N)
// SC: O(height of tree), as it is complete binary tree, height-> log(N)
class Solution {
public:
    int totalNodes = 0;
    void countHelper(TreeNode* root){
        //for empty subtree
        if(root==NULL){
            //returning control back to the previous call in the recursion chain.
            return;
        }
        totalNodes++;
        countHelper(root->left);
        countHelper(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        countHelper(root);
        return totalNodes;
    }
};

//------- Approach 4 --------//
// Efficient solution | TC less than O(N)
//pending | leftHeight, rightHeight, recursion
