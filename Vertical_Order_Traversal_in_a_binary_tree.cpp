
class Solution {
public:
 

    void fun(TreeNode *root, int level, int dis, map<int, vector<pair<int, int>>>& m) {
      
        if(root == NULL)
        {
          return;   
        }
        m[dis].push_back({level, root->val});
        fun(root->left, level + 1, dis - 1, m);
        fun(root->right, level + 1, dis + 1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, vector<pair<int, int>>> m;
        fun(root, 0, 0, m); 
        vector<vector<int>> ans;
        
        for(auto x:m) //traverse map
        {
            sort(x.second.begin(), x.second.end()); //sorted by level
            // level is the first val of each pair in x.second
            vector<int> temp;
            for(int i=0; i<x.second.size(); i++) 
            {
                temp.push_back(x.second[i].second); //Entering values acc to row
            }
            ans.push_back(temp); //Enter in Result
            temp.clear();
        }
        
        return ans;
    }
};
// nice question
