class Solution {
public:
    bool dp[1005][1005];
    bool fun(string str){
        int n=str.length();
        int l=0;
        int r=n-1;
        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    //longest palindromic substring
int funnnn(string str,int n){
    int ans=1;
    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }
   for(int i=n-2;i>=0;i--){
       for(int j=i+1;j<n;j++){
           if(str[i]==str[j]){
               if(dp[i+1][j-1]==true||j-i==1){
                   dp[i][j]=true;
                   ans=max(ans,j-i+1);
               }
           }
       }
   }
    return ans;
}
    string longestPalindrome(string s) {
       if(s==""){
           return "";
       } 
        memset(dp,false,sizeof(dp));
        int n=s.length();
        int v= funnnn(s,n);
        string ans="";
        for(int i=0;i<n;i++){
            if(fun(s.substr(i,v))==true){
                 ans=s.substr(i,v);
                  break;
            }
        }
        return ans;
    }
};


// https://youtu.be/Msghl9189X4
