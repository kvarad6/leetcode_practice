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
//Using BFS | level-order traversal | queue
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            double levelSum=0;
            double average=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }

                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            average = levelSum/size;
            ans.push_back(average);
        }
        return ans;
    }
};
