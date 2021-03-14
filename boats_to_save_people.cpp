class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());
      int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j){
            if((people[i]+people[j])<=limit){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};
//greedy+two pointer
/*If the heaviest person can share a boat with the lightest person, then do so. Otherwise, the heaviest person can't pair with anyone, so they get their own boat.

The reason this works is because if the lightest person can pair with anyone, they might as well pair with the heaviest person.
*/

//tc o(nlogn)
//sc o(1)
