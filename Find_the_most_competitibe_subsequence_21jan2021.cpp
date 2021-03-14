class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
    
     int n = nums.size();
     
     vector<int>ans;
     
     for(int i = 0 ; i <n ; i++)
     {
         while(ans.size() > 0 && ans.size() - 1 + n - i >= k && ans.back() > nums[i])
         {
             ans.pop_back();
         }
         if(ans.size() < k)
         {
             ans.push_back(nums[i]);
         }
     }
        return ans;
    }
};

// tc amortized o(n)
// sc o(1)
