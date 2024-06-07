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
//leftHeight, rightHeight, recursion
//in case of complete binary tree, if lh==rh, total nodes = 2^height - 1
//TC: O(logn * logn)

class Solution {
public:
    int countLeft(TreeNode* node){
        int leftNodes = 0;
        while(node!=NULL){
            leftNodes++;
            node = node->left;
        }
        return leftNodes;
    }

    int countRight(TreeNode* node){
        int rightNodes = 0;
        while(node!=NULL){
            rightNodes++;
            node = node->right;
        }
        return rightNodes;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int totalNodes = 0;
        int leftHeight = countLeft(root->left);
        int rightHeight = countRight(root->right);

        if(leftHeight == rightHeight){
            totalNodes = pow(2, leftHeight) - 1;
        }

        totalNodes = 1 + countNodes(root->left) + countNodes(root->right);
        return totalNodes;
    }
};


//------- Approach 5 --------//
// Efficient solution | TC less than O(N)
//leftHeight, rightHeight, recursion
//in case of complete binary tree, if lh==rh, total nodes = 2^height - 1
//TC: O(logn * logn)
class Solution {
public:
    double leftHeight = 0;
    double rightHeight = 0;
    void countLeft(TreeNode* node){
        if(node==NULL){
            return;
        }
        leftHeight++;
        countLeft(node->left);
    }

    void countRight(TreeNode* node){
        if(node==NULL){
            return;
        }
        rightHeight++;
        countRight(node->right);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        double totalNodes = 0;
        countLeft(root->left);
        countRight(root->right);

        if(leftHeight == rightHeight){
            totalNodes = pow(2, leftHeight) - 1;
        }

        totalNodes = 1 + countNodes(root->left) + countNodes(root->right);
        return totalNodes;
    }
};
