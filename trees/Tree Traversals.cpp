/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

//-------------------- Approach 1 ----------------------//
//Using seperate recursive functions for inorder, preorder and postorder
//inorder: left root right
//preorder: root left right
//postorder: left right root

vector<int> inorder;
vector<int> preorder;
vector<int> postorder;

void calculateInorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    calculateInorder(root->left);
    inorder.push_back(root->data);
    calculateInorder(root->right);
}

void calculatePreorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    preorder.push_back(root->data);
    calculatePreorder(root->left);
    calculatePreorder(root->right);
}

void calculatePostorder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    calculatePostorder(root->left);
    calculatePostorder(root->right);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){

    vector<vector<int>> ans;
    

    calculateInorder(root);
    calculatePreorder(root);
    calculatePostorder(root);

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}

//-------------------------- Approach 2 -----------------------//
/*
In a single traversal | Using Stack
stack str: {node, number}
whenever start, insert (root, 1) in stack

while taking out an element from stack, 
if num = 1,
add the root's value to preorder, and push that number by incrementing it by 1, 
and if there exist left, go to the left.

if num = 2,
add the root's value to inorder, and push that number by incrementing it by 1,
and there exist right, go to the right.

if num = 3,
add the root's value to postorder

consider the topmost element of stack

*/

vector<vector<int>> getTreeTraversal(TreeNode *root) {
  stack<pair<TreeNode *, int>> st;

  // at start, put {root, 1} in stack
  st.push({root, 1});
  vector<int> preorder, postorder, inorder;
  vector<vector<int>> ans;
  if(root==NULL){
      return ans;
  }

  while(!st.empty()){
      auto it = st.top();
      st.pop();

      if(it.second == 1){
          preorder.push_back(it.first->data);
          it.second++;
          st.push(it);

          //check if left exists, if yes, push the same in stack
          if(it.first->left!=NULL){
            st.push({it.first->left, 1});
          }
      }
      else if(it.second == 2){
          inorder.push_back(it.first->data);
          it.second++;
          st.push(it);

          //check if right exists, if yes, push the same in stack
          if(it.first->right!=NULL){
              st.push({it.first->right, 1});
          }
      }
      //dont push it back again
      else{
          postorder.push_back(it.first->data);
      }
  }

  ans.push_back(inorder);
  ans.push_back(preorder);
  ans.push_back(postorder);

  return ans;
   
}
