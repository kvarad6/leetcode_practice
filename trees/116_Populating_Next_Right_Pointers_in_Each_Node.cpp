/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//------------ Approach 1 ------------//

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }

        Node* current = root;

        while(current->left!=NULL){

            Node* temp = current;
            //tranversing the level
            while(current!=NULL){
                current->left->next = current->right;
                if(current->next==NULL){
                    current->right->next=NULL;
                }
                else{
                    current->right->next = current->next->left;
                }
                current=current->next;
            }
            current = temp->left;
        }
        return root;
    }
};


//------------ Approach 2 ------------//
//Recursive solution

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }

        //connecting nodes | same level | same parent
        if(root->left!=NULL){
            root->left->next = root->right;
        }

        //connecting nodes | same level | next parent
        //connecting root's rightmost to the next root's leftmost
        if(root->right!=NULL && root->next!=NULL){
            root->right->next = root->next->left;
        }

        //continue for rest left and right subtree
        connect(root->left);
        connect(root->right);

        return root;
    }
};


//------------ Approach 3 ------------//
//Iterative solution | pending

class Solution {
public:
    Node* connect(Node* root) {
        
    }
};


