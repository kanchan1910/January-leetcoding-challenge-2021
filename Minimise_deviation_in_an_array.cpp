class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>s;
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        if(mini % 2 == 0 && maxi % 2 != 0)
        {
            return maxi - mini;
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] % 2 != 0)
            {
                s.insert(nums[i] * 2);
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        int ans = *s.rbegin() - *s.begin();

        while(!s.empty() && *s.rbegin() % 2 == 0)
        {
            int largest = *s.rbegin();
            s.erase(largest);
            s.insert(largest/2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
    }
};
// tc o(nlogn)
// sc o(n)
// rbegin is actually the last element of your container. end is one past the end of the container.
// my mistake of using *s.end() , instead of *s.rbegin()
