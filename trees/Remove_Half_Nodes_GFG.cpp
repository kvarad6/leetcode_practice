
// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        //edge case
        if(root==NULL){
            return NULL;
        }
        
        //recursive calls
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        //if both left and right are zeros | checking for leaf nodes
        //in that case, return root to call stack
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        
        //checking half node
        
        //if left is null, then create a new root with root->right, delete current root (which is a half root)
        if(root->left==NULL){
            Node* newNode = new Node(NULL);
            newNode = root->right;
            free(root);
            return newNode;
        }
        
        //if right is null, then create a new root with root->left, delete current root (which is a half root)
        if(root->right==NULL){
            Node* newNode = new Node(NULL);
            newNode = root->left;
            free(root);
            return newNode;
        }
        
        return root;
    }
};
