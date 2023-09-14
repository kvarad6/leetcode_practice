#include <iostream>
#include <vector>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//To check if the node is a leaf node or not
bool isLeafNode(TreeNode<int> * root){
    if(root->left == NULL && root->right==NULL){
        return true;
    }
    return false;
}

//To add the left boundary nodes
void addLeftBoundary(TreeNode<int> * root, vector<int> &res){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isLeafNode(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

//To add all the leaf nodes | whose left and right child is NULL
void addLeafNodes(TreeNode<int> * root, vector<int> &res){
    if(isLeafNode(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left) addLeafNodes(root->left, res);
    if(root->right) addLeafNodes(root->right, res);
}

//To add the right boundary nodes but in the reverse 
void addRightBoundary(TreeNode<int> * root, vector<int> &res){
    TreeNode<int>* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isLeafNode(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }

        for(int i=temp.size()-1;i>=0;--i){
            res.push_back(temp[i]);
        }
    }
}


vector<int> traverseBoundary(TreeNode<int> *root){
	vector<int> res;
    if(!root){
        return res;
    }
    if(!isLeafNode(root)){
        res.push_back(root->data);
    }
    addLeafNodes(root, res);
    addLeafNodes(root, res);
    addRightBoundary(root, res);
    return res;
}
