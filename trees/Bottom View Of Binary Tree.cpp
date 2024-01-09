/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


#include<map>
vector<int> bottomView(TreeNode<int> * root){
    vector<int> ans;
    map<int, int> mpp;
    queue<pair<TreeNode<int>*, int>> q;

    //add root, line in the queue, considering root at the 0th line
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        //put the node's data and line in the map
        TreeNode<int> * node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        //check if left exists, put the left node and line-1 in queue
        if(node->left!=NULL){
          q.push({node->left, line - 1});
        }

        //check if right exists, put the right node and line+1 in queue
        if(node->right!=NULL){
          q.push({node->right, line + 1});
        }
    }

    //iterate the map and put the values in ans vector
    for (auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;

}
