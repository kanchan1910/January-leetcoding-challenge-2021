class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ;i < n ; i++)
        {
            vector<int>tmp;
            int x = i;
            int y = 0;
            while(x < n && y < m)
            {
                tmp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tmp.begin(),tmp.end());
            x = i;
            y = 0;
            int k = 0;
            while(x < n && y < m)
            {
                mat[x][y] = tmp[k];
                x++;
                y++;
                k++;
            }
            
        }
        for(int i = 1; i < m ; i++)
        {
            vector<int>tmp;
            int x = 0;
            int y = i;
            while(x < n && y < m)
            {
                tmp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tmp.begin(),tmp.end());
            int k = 0;
            x = 0;
            y = i;
            while(x < n && y < m)
            {
                mat[x][y] = tmp[k];
                x++;
                y++;
                k++;
            }
        }
        return mat;
    }
};
// tc o(n*m*min(n,m)log(min(m,n))) ~ o(n*n*nlogn)
// sc o(1)
