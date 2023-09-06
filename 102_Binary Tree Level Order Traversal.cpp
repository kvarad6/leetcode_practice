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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Declaring a vector of vector to store the level wise transversal
        vector<vector<int>> ans;

        //Declaring a queue to store the root node and it's childrens
        queue<TreeNode*> q;

        //base case 
        if(root==NULL){
            return ans;
        }
        
        //At start, push root node in the queue
        q.push(root);

        // transversing the list
        while(!q.empty()){
            int size = q.size();

            //Declaring a level vector to store the nodes that belongs to same level/ parent
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                //If left child exists, put it into the queue
                if(node->left!=NULL){
                    q.push(node->left);
                }
                //If right child exists, put it into the queue
                if(node->right!=NULL){
                    q.push(node->right);
                }

                //Put the node / current root node into the level vector
                level.push_back(node->val);
            }
            //Put the current level/ level vector into the ans vector of vector
           ans.push_back(level);
        }
        return ans;
    }
};

//TC: O(N) | As we are transversing all the nodes inside a queue
//SC: O(N) | As, at worst case, queue is gonna store all the nodes
