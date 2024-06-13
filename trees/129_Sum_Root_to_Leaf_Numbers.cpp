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
//Recursive Solution | DFS 
class Solution {
public:
    int totalSum = 0;
    void sumNodes(TreeNode* root, int currentSum){
        if(root==NULL){
            return;
        }
        currentSum = currentSum*10 + root->val;
        //when you reached to leaf node 
        if(root->left==NULL && root->right==NULL){
            totalSum += currentSum;
            return;
        }
        //visiting nodes on left subtree
        sumNodes(root->left, currentSum);

        //visiting nodes on right subtree, starting from root again, with currentSum = 0
        sumNodes(root->right, currentSum);
    }

    int sumNumbers(TreeNode* root) {
        int currentSum = 0;
        sumNodes(root, currentSum);

        return totalSum;
    }
};


//---------- Approach 2 ------------//
//DFS | Recursion

class Solution {
public:
    
    int calculateSum(TreeNode* root, int sum){
        if(root==NULL){
            return NULL;
        }

        sum = sum*10 + root->val;

        if(root->left==NULL && root->right==NULL){
            return sum;
        }

        int leftSum = calculateSum(root->left, sum);
        int rightSum = calculateSum(root->right, sum);
        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return calculateSum(root, sum);
    }
};



//----------- Approach 3 -----------//
//Using BFS | Iterative Approach | Queue
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;

        long currentSum = 0;
        long totalSum = 0;
        q.push({root, currentSum});

        while(!q.empty()){
            // auto [node, currentSum] = q.front();
            pair<TreeNode*, int> temp = q.front();
            TreeNode* node = temp.first;
            int currentSum = temp.second;
            q.pop();
            
            currentSum = currentSum*10 + node->val;

            if(node->left==NULL && node->right==NULL){
                totalSum += currentSum;
            }

            
            if(node->left!=NULL){
                q.push({node->left, currentSum});
            }
            if(node->right!=NULL){
                q.push({node->right, currentSum});
            }
            
        }
        return totalSum;
    }
};
