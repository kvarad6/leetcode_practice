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
//--------- Approach 1 ---------//
//DFS | Recursion
//max(leftHeight, rightHeight) + 1(for root level)
//TC: O(n)
//SC: O(1)
class Solution {
public:
    
    void calculateMaxDepth(TreeNode* node, int currentDepth, int &maximumDepth){
        //base case

        if(node==NULL){
            return;
        }
        if(node->left==NULL && node->right==NULL){
            maximumDepth = max(currentDepth, maximumDepth);
        }
        calculateMaxDepth(node->left, currentDepth+1, maximumDepth);
        calculateMaxDepth(node->right, currentDepth+1, maximumDepth);
    }

    int maxDepth(TreeNode* root) {
        //base condition
        if(root==NULL){
            return NULL;
        }
        int maximumDepth = 0;
        int currentDepth = 1;
        calculateMaxDepth(root, currentDepth, maximumDepth);
        return maximumDepth;
    }
};



//--------- Approach 2 ---------//
//DFS | Recursion
//max(leftHeight, rightHeight) + 1(for root level)
//TC: O(n)
//SC: O(1)
class Solution {
public:

    int maxDepth(TreeNode* root) {
        //base condition
        if(root==NULL){
            return NULL;
        }

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
};


//--------- Approach 3 ---------//
//BFS | queue
//TC: O(n)
//SC: O(n)
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        queue<TreeNode* >q;
        q.push(root);
        int depth=0;

        while(!q.empty()){
            
            depth++;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};
