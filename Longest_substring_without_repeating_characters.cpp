class Solution {
public:
    bool check(string str){
        unordered_set<int>s;
        for(int i=0;i<str.length();i++){
            if(s.find(str[i])==s.end()){
                s.insert(str[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
          int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check(s.substr(i,j-i+1))==true){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
//tc o(n^3)
//sc o(n)
//Tle

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
          int n=s.length();
          int ans=0;
          int l=0,r=0;
          unordered_set<int>ss;
          while(l<n&&r<n){
              if(ss.find(s[r])==ss.end()){
                  ss.insert(s[r]);
                  ans=max(ans,r-l+1);
                  r++;
              }
              else{
                  auto itr=ss.find(s[l]);
                  ss.erase(*itr);
                  l++;
              }
          }
        
        return ans;
    }
};
//tc o(2*n)
//sc o(n)
//accepted

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
          int n=s.length();
          int ans=0;
          int l=0,r=0;
          unordered_map<int,int>m;
          while(r<n){
            if(m.find(s[r])!=m.end()){   
                l=max(m[s[r]]+1,l);   //for this case "abba"
            }
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
          }
        
        return ans;
    }
};
//tc o(n)
//sc o(n)
//accepted
