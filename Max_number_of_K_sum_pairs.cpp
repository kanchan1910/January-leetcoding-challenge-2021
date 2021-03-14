class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n =  nums.size();
        
        sort(nums.begin(), nums.end());
        
        int l = 0 , r = n - 1;
        
        int ans = 0;
        
        while(l < r){
            
            int sum = nums[l] + nums[r];
            
            if(sum == k){
                
                ans++;
                
                l++;
                
                r--;
                
            }
            else if(sum < k){
                
                l++;
                
            }
            else if (sum > k){
                
               r--; 
                
            }
        }
        
        return ans;
        
    }
};
// two-pointer approach
// tc  o(nlogn)
// sc o(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n =  nums.size();
        
        int ans = 0;
        
        unordered_map<int,int>m;
        
        for(int i = 0 ;i< n ; i++){
            
            int target = k  - nums[i];
            
            if(m[target] > 0){
                
                ans ++;
                
                m[target]--;
            }
            else{
                
                m[nums[i]]++;
                
            }
        }

        return ans;
    }
};

// tc o(n)
//sc o(n)


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
        
            m[nums[i]]++;
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
        
            if(m[nums[i]]>0 && m[k-nums[i]]>0){
            
                m[nums[i]]--;
                
                m[k-nums[i]]--;
                
                if(m[k-nums[i]]>=0){
                
                  ans++;   
                  
                }
            }
        }
        
        return ans;
    }
};

// tc o(n)
//sc o(n)
