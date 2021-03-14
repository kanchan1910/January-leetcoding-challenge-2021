class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        
        if(n == 1){
            
            if(nums[0] == x){
                
                return 1;
                
            }
            else{
                
                return -1;
                
            }
        }
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += nums[i];
            
        }
 
        if(x > sum){
            
            return -1;
            
        }
        
        int need = sum - x;
        
        if(need == 0){
            
            return n;
            
        }

        int longest = INT_MIN;
        
        int l = 0;
        
        int cur_sum = 0;
        
        for(int r = 0; r < n; r++){
            
            if(cur_sum < need){
                
                cur_sum += nums[r];
                
            }
                while(cur_sum >= need){
                    
                    if(cur_sum == need){
                        
                        longest = max(longest, r - l + 1);
                        
                    }
                    
                    cur_sum -= nums[l];
                    
                    l++;
                    
                }
        }
    
        if(longest == INT_MIN){
            
            return -1;
            
        }
        else{
            
            return n - longest;
            
        }
    }
};

//Accepted and easy solution..


class Solution {
public:
int  minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>m;
     int sum=0;
     for(int i=0;i<n;i++){
         sum+=nums[i];
         m[sum]=i;
     }
     m[0]=0;
     if(x>sum){
         return -1;
     }
     sum-=x;
     int s=0;
     int longest_subarray_size=0;
     for(int i=0;i<n;i++){
         s+=nums[i];
         if(m.count(s-sum)){
             if((s-sum)==0){
                 longest_subarray_size=max(longest_subarray_size,i-m[s-sum]+1);
             }
             else{
                 longest_subarray_size=max(longest_subarray_size,i-m[s-sum]);
             }
         }
     }
     if(longest_subarray_size==0){
         if(sum==0){
             return n;
         }
         else{
             return -1;
         }
     }
     else{
         return n-longest_subarray_size;
     }
    }
};
//accepted





class Solution {
public:
   // int dp[1005][1005][1005];
    unordered_map<string,int>m;
    int fun(int l,int r,int x,vector<int>& nums){
        if(nums.size()==1){
        //n==1
            if(nums[l]==x){
                return 1;
            }
            else{
                return -1;
            }
        }
        if(x==0){
            return 0;
        }
        if(x<0||l>r){
            return 1e6;
        }
      /*  if(dp[l][r][x]!=-1){
            return dp[l][r][x];
        }*/
        string key=to_string(l)+"*"+to_string(r)+"*"+to_string(x);
        if(m.count(key)){
            return m[key];
        }
        return m[key]=1+min(fun(l+1,r,x-nums[l],nums),fun(l,r-1,x-nums[r],nums));
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
       // memset(dp,-1,sizeof(dp));
        int ans=fun(0,n-1,x,nums);
        if(ans>=1e6){
            return -1;
        }
        else{
            return ans;
        }
    }
};
//correct but tle

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r){
            if(nums[l]>x&&nums[r]>x){
                ans=-1;
                break;
            }
            else if(nums[l]>x){
                ans++;
                x-=nums[r];
                r--;
            }
            else if(nums[r]>x){
                ans++;
                x-=nums[l];
                l++;
            }
            else if(nums[l]>nums[r]){
                ans++;
                x-=nums[l];
                l++;
            }
            else if(nums[r]>=nums[l]){
                ans++;
                x-=nums[r];
                r--;
            }
            
            if(x==0){
                break;
            }
        }
        if(x!=0){
            return -1;
        }
        return ans;
    }
};
//my first logic but it proved to be wrong in cases like x=10
// 8 16 5 2 3
