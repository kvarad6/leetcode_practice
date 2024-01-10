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

 /*
    Datastructures used:

    Queue: {root, {vertical, level}} | queue<pair<TreeNode*, pair<int, int>>> q;
    Map: {vertical, multiset({level, nodes})} | map<int, map<int, multiset<int>>> mpp;

    Transversal:
    If moving to left -> the vertical will change by -1 and the level will change by +1
    If moving to right -> the vertical will change by +1 and the level will change by +1 

    Insert in map:
    {vertical} --> {level} --> {node value}

    TC: O(N * logN) | logn -> multiset
    SC: O(N) (storing all the nodes) + O(N) for queue

 */

class Solution {
public:
    map<int, map<int, multiset<int>>> mpp;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        q.push({root, {0,0}});
        while(q.size()){
            auto it = q.front();
            TreeNode* node = it.first;
            q.pop();
            int val = it.first->val;
            int vertical = it.second.first;
            int level = it.second.second;

            mpp[vertical][level].insert(val);

            if(node->left){
                q.push({node->left, {vertical-1, level+1}});
            }
            if(node->right){
                q.push({node->right, {vertical+1, level+1}});
            }

            //transverse map and put element in resultant vector
        } 
            //it.first: vertical | int
            //it.second: map of <int, multiset<int>>
        for(auto i: mpp){
                vector<int> v;
                for(auto j: i.second){
                    for (auto g: j.second)
                    v.push_back(g);
                }
                   ans.push_back(v);
                }
                return ans;
    }
};
