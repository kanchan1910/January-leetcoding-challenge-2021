https://youtu.be/LuLCLgMElus

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     next_permutation(nums.begin(),nums.end());
    }
};
// tc o(n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i, j;
        for(i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                break;
            }
        }
        if(i < 0)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
            for(j = n - 1 ;j >= i + 1; j--)
            {
                if(nums[j] > nums[i])
                {
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin() + i + 1 , nums.end());
        }
    }
};
// tc o(n) + o(n) + o(n) = 3o(n) = o(n)
