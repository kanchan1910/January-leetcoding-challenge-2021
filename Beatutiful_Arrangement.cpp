class Solution {
public:
    int ans=0;
    
    void fun(int start,int N,vector<bool>&vis){
        if(start>N){
            
            ans++;
            
        }
        for(int i=1;i<=N;i++){
            
            if(!vis[i]&&(start%i==0||i%start==0)){
                
                vis[i]=true;
                
                fun(start+1,N,vis);
                
                vis[i]=false;
                
            }
        }
    }
    int countArrangement(int n) {
        
        vector<bool>vis(n+1);
        
        fun(1,n,vis);
        
        return ans;
        
    }
    
};

//best leetcode solution video

/*Time complexity : O(k)O(k). kk refers to the number of valid permutations.

Space complexity : O(n)O(n). visitedvisited array of size n is used.*/

/* Brute Force [Time Limit Exceeded]


In the brute force method, we can find out all the arrays that can be formed using the numbers from 1 to N(by creating every possible permutation of the given elements). Then, we iterate over all the elements of every permutation generated and check for the required conditions of divisibility.*/
/*
Time complexity : O(n!)O(n!). A total of n!n! permutations will be generated for an array of length nn.

Space complexity : O(n)O(n). The depth of the recursion tree can go upto nn. numsnums array of size nn is used.

*/
/*Better Brute Force [Accepted]
In the brute force approach, we create the full array for every permutation and then check the array for the given divisibilty conditions. But this method can be optimized to a great extent. To do so, we can keep checking the elements while being added to the permutation array at every step for the divisibility condition and can stop creating it any further as soon as we find out the element just added to the permutation violates the divisiblity condition.
Time complexity : O(k)O(k). kk refers to the number of valid permutations.

Space complexity : O(n)O(n). The depth of recursion tree can go upto nn. 
*/
