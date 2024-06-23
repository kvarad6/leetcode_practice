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

//----------- Approach 1 ----------//
//Using BFS | queue
//Adding the last node in each level to the result
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> view;

        if(root==NULL){
            return view;
        }

        q.push(root);

        while(!q.empty()){
            int queueSize = q.size();
            for(int i=0;i<queueSize;i++){
                TreeNode* node = q.front();
                q.pop();
                
                //pushing last element of each level to the array
                if(i==queueSize-1){
                    view.push_back(node->val);
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
        }
        return view;
    }
};

//-------- Approach 2 ---------/
//Using DFS | Recursion

class Solution {
public:

    void rightView(TreeNode* root, vector<int> &view, int level){

        if(root==NULL){
            return;
        }

        if(view.size()==level){
            view.push_back(root->val);
        }

        rightView(root->right, view, level+1);
        rightView(root->left, view, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<int> view;

        rightView(root, view, level);
        return view;
    }
};
