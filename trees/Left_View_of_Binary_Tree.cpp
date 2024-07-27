
//--------- Appraoch 1 ------------//
//BFS | Level Order Traversal

vector<int> leftView(Node *root)
{
  vector<int> view;
  queue<Node*> q;
   
  if(root==NULL){
      return view;
  }
  q.push(root);
  while(!q.empty()){
      int size = q.size();
      for(int i=0;i<size;i++){
          Node* node = q.front();
          q.pop();
          if(i==0){
              view.push_back(node->data);
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

//----------- Approach 2 -----------//
//DFS | Recursion
void leftSideView(Node* root, vector<int>& view, int level){
    if(root==NULL){
        return;
    }
    if(level==view.size()){
        view.push_back(root->data);
    }
    
    leftSideView(root->left, view, level+1);
    leftSideView(root->right, view, level+1);
}
vector<int> leftView(Node *root)
{
  int level = 0;
  vector<int> view;
  leftSideView(root, view, level);
  return view;
}
