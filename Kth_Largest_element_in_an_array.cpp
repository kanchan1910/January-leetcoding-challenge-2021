class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin() + k - 1,nums.end(),greater<int>());
        return nums[k - 1];
    }
};
// tc o(n)
// sc o(1)
/*nth_element() is an STL algorithm which rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.

*/
/*void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
                  RandomAccessIterator last);

first: Random-access iterator to the first element in the list.
last: Random-access iterator to the last element in the list.
nth: Random-access iterator pointing to the position in the list, 
which should be sorted.
If it points to end, then this function will do nothing.

Return Value: Since, return type is void, so it doesnot return any value.
*/
/*Time Complexity of std::nth_element(): O(n), with n being the distance between first and the last.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n =  nums.size();
        priority_queue<int>pq(nums.begin(), nums.end()); //o(n)
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};
//tc o(n)+o(klog(n))
//sc o(n)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n =  nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
//tc o(nlogn)

// sc o(1)
