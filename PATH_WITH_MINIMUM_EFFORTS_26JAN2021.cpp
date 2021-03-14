class Solution {
public:
    bool dfs(vector<vector<int>>&h,int n,int m,int i,int j,int mid,bool vis[105][105])
    {
        if(i == n - 1 && j == m - 1)
        {
            return true;
        }
        vis[i][j] = true;
        bool res = false;
        if(i > 0 && vis[i - 1][j] == false && abs(h[i - 1][j] - h[i][j]) <= mid)
        {
            if(dfs(h,n,m,i - 1,j,mid,vis) == true)
            {
                res = true;
            }
        }
        if(i < n - 1 && vis[i + 1][j] == false && abs(h[i + 1][j] - h[i][j]) <= mid)
        {
            if(dfs(h,n,m,i + 1,j,mid,vis) == true)
            {
                res = true;
            }
        }
        if(j > 0 && vis[i][j - 1] == false && abs(h[i][j - 1] - h[i][j]) <= mid)
        {
            if(dfs(h,n,m,i,j - 1,mid,vis) == true)
            {
                res = true;
            }
        }
        if(j < m - 1 && vis[i][j + 1] == false && abs(h[i][j + 1] - h[i][j]) <= mid)
        {
            if(dfs(h,n,m,i,j + 1,mid,vis) == true)
            {
                res = true;
            }
        }
        return res;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int s = 0,e = INT_MAX,ans = INT_MAX;
        while(s <= e)
        {
            int mid = s + (e - s)/2;
            bool vis[105][105];
            memset(vis,false,sizeof(vis));
            if(dfs(heights,n,m,0,0,mid,vis) == true)
            {
                ans = min(ans,mid);
                e = mid -1 ;
            }
            else
            {
                s = mid + 1;
            }
        }
          return ans;  
    }
};
// binary search + dfs
// tc o(n*m*log(INT_MAX))
// sc o(n*m)

//My doubt can't we just simoly do with recursion and memoization
