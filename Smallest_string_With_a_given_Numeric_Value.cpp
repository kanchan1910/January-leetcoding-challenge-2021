class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n , 'a');
        k -= n;
        if(k == 0)
        {
            return ans;
        }
        int i = n - 1;
        while(k != 0 && i >= 0)
        {
            if(k <= 25)
            {
                ans[i] += k;
                break;
            }
            else
            {
                ans[i] = 'z';
                k += 1;  // removing already added a
                k -= 26;  // adding z
            }
            i--;
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
