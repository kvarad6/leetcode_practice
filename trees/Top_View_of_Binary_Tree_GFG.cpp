/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> view;
        queue<pair<Node*, int>> q;
        map<int, int>mpp;
        
        if(root==NULL){
            return view;
        }
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            //if the line not present in map/ not visited, add in the same
            if(mpp.find(line)==mpp.end()){
                mpp[line] = node->data;
            }
            
            if(node->left!=NULL){
                q.push({node->left, line-1});
            }
            if(node->right!=NULL){
                q.push({node->right, line+1});
            }
        }
        for(auto it:mpp){
            view.push_back(it.second);
        }
        return view;
    }

};
