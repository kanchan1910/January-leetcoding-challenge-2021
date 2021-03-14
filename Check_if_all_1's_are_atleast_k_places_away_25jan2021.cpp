class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>index;
        for(int i = 0 ; i < n ;i++)
        {
            if(nums[i] == 1)
            {
                index.push_back(i);
            }
        }
        if(index.empty() || index.size() == 1)
        {
            return true;
        }
       
        for(int i = 1 ; i <index.size();i++)
        {
            if((index[i] - index[i - 1] - 1) < k)
            {
                return false;
            }
        }
        
        return true;
    }
};

// OR

class Solution {
public:
	bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int count = k;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 0)
            {
                count++;
            }
            else{
                if(count < k)
                {
                    return false;
                }
                count = 0;
            }
        }
        return true;
	}
};
