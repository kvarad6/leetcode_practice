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
//----------- Approach 1 ------------//
 // zigzag traversal = BFS (level order traversal) + flag for odd level
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }
        bool zigzag = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }

                level.push_back(node->val);

            }
             if(zigzag){
                reverse(level.begin(),level.end());
                zigzag=false;
            }else{
                zigzag=true;
            }
            ans.push_back(level);
        }
        return ans;
    }
};


//----------- Appraoch 2 ------------//

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
//----------- Approach 2 ---------//
//Using BFS | queue
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            if(count%2==0){
                ans.push_back(level);
            }
            else{
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            count++;
        }
        return ans;
    }
};

//----- PENDING : DFS Approach ---------//
