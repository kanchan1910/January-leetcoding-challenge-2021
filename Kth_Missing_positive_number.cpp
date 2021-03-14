class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int ans;
       int num=1;
       int count=0;
       int n=arr.size();
       int f=0;
       for(int i=0;i<n;){
           if(num==arr[i]){
               i++;
           }
           else{
              count++;
              ans=num;
              if(count==k){
                  f=1;
                  break;
              }
           }
           num++;
       }
        if(f==0){
            while(count!=k){
                count++;
                ans=num;
                num++;
            }
            
        }
        return ans;
    
    }
};

//tc o(n)
//sc o(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        int count=0;
        int ans=0;
        for(int i=1;i<=10000;i++){
            if(s.find(i)!=s.end()){//if present in array then continue;
                continue;
            }
            else{//means not present in the given array so is a missing number
                count++;
            }
            if(count==k){//if we found the kth missing positive integer
                ans=i;
                break;
            }
        }
        return ans;
    }
};

//tc o(n)
//sc o(n)
