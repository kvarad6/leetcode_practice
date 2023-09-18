/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <map>
#include <queue>
#include <iostream>
#include <utility>

vector<int> getTopView(TreeNode<int> *root)
{
    //Declaring a vector to store the nodes present in top view
    vector<int> ans;

    //to store (line, node->data) uniquely in sorted fashion
    map<int, int> mpp;

    //to store a pair of node and the line 
    queue<pair<TreeNode<int>*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int line = it.second;

        //if line is not present in map
        if(mpp.find(line)==mpp.end()){
            //add the line and corresponding node's data
            mpp[line] = node->data;
        }

        if(node->left!=NULL){
            q.push({node->left, line - 1});
        }
        if(node->right!=NULL){
            q.push({node->right, line + 1});
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;

}
