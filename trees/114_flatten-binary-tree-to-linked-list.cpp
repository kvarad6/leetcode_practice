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
 //--------------- Approach 1 ----------------//
 //Recursive Solution
 //rearranging existing nodes | Reverse Post Order
 //breaking left links and joining them to right
 //TC: O(N)
 //SC: O(N)

class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        
        TreeNode* node = root;
        if(root==NULL){
            return;
        }
        flatten(node->right);
        flatten(node->left);
        node->right = prev;
        node->left = NULL;
        prev = node; 
    }
};

//--------------- Approach 2 ----------------//
 //Iterative Solution
 //using stack 
 //TC: O(N)
 //SC: O(N)
 
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL){
            return;
        }
        //push root to stack
        st.push(root);
        while(!st.empty()){
            TreeNode* currentNode = st.top();
            st.pop();
            //if right exists, push it into the stack
            if(currentNode->right){
                st.push(currentNode->right);
            }
            if(currentNode->left){
                st.push(currentNode->left);
            }
            //if stack is not empty, make top node as current's right
            if(!st.empty()){
                currentNode->right = st.top();
            }
            currentNode->left = NULL;
        }
    }
};

//------------- Approach 3 -------------//
//optimised approach | Morris Traversal
//SC: O(1)
//TC: O(N)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        TreeNode* currentNode = root;
        TreeNode* prevNode = NULL;
        while(currentNode!=NULL){
            if(currentNode->left!=NULL){
                prevNode = currentNode->left;
                while(prevNode->right!=NULL){
                    prevNode = prevNode->right;
                }
                prevNode->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = NULL;
            }
            currentNode = currentNode->right;
        }
    }
};


