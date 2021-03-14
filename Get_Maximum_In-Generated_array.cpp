class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0){
            return 0;
        }
        vector<int>arr(n + 1);
        arr[0] = 0;
        arr[1] = 1 ;
        for(int i = 1; i <= n/2 ; i++){
            arr[i * 2] = arr[i];
            if(i == n/2 && n % 2 == 0){
                break;
            }
            arr[i * 2 + 1] = arr[i] + arr[i + 1];
        }
        return *max_element(arr.begin(), arr.end());
    }
};

// OR

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0){
            return 0;
        }
        vector<int>arr(n + 1);
        arr[0] = 0;
        arr[1] = 1 ;
        for(int i = 1; i <= n/2 ; i++){
            if(2 * i <= n){
                arr[i * 2] = arr[i];
            }
           if(2 * i + 1 <= n){
                arr[i * 2 + 1] = arr[i] + arr[i + 1];   
           }
            
        }
        return *max_element(arr.begin(), arr.end());
    }
};
