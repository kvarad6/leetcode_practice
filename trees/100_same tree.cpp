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
//Using DFS | Recursion
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //edge cases
        //if both trees are null, they are identical
        if(p==NULL && q==NULL){
            return true;
        }

        //if only one of the trees is null, they are not identical 
        if(p==NULL || q==NULL){
            return false;
        }

        //if the root nodes of both the trees are equal, recursively check if the left and right sbtrees are identical
        if(p->val==q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;   
    }
};


//----------- Approach 2 -----------//
//Using BFS | queue
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //edge cases
        if(p==NULL && q==NULL){
            return true;
        }

        if(p==NULL || q==NULL){
            return false;
        }  

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();

            q1.pop();
            q2.pop();

            if(node1==NULL || node2==NULL){
                if(node1!=node2){
                    return false;
                }
                continue;
            }

            if(node1->val != node2->val){
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);

            q2.push(node2->left);
            q2.push(node2->right);
        }

        return true;
    }
};
