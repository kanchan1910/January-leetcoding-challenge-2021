class Solution {
public:
    int countVowelStrings(int n) {
    
        vector<int>ans(5,1);
        
        for(int i = 2; i <= n ; i++){
        
            ans[0] += ans[1] + ans[2] + ans[3] + ans[4];
            
            ans[1] += ans[2] + ans[3] + ans[4];
            
            ans[2] += ans[3] + ans[4];
            
            ans[3] += ans[4];
            
        }
        
        return ans[0] + ans[1] + ans[2] + ans[3] + ans[4];
        
    }
};
// tc o(n)

// sc o(1)
