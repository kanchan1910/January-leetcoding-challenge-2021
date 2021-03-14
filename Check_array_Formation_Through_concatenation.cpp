//jan 1 2021

class Solution {
public:
    
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        unordered_map<int,int>m;
        
        for(int i=0;i<pieces.size();i++){
            
            m[pieces[i][0]]=i;
        }
        
        for(int i=0;i<arr.size();){
            
            if(m.find(arr[i])==m.end()){
                
                return false;
                
            }
            else{
                
                int idx=m[arr[i]];
                
                vector<int>tmp=pieces[idx];
                
                for(int j=0;j<tmp.size();j++,i++){
                    
                    if(arr[i]!=tmp[j]){
                        
                        return false;
                        
                    }
                }
            }
            
        }
        
        return true;
    }
};

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        unordered_map<int,vector<int>> m; 
        
        for(int i=0;i<pieces.size();i++){
            
            m[pieces[i][0]]=pieces[i];
            
        }
        
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++){
            
            if(m.find(arr[i])!=m.end()){
                
                vector<int>tmp=m[arr[i]];
                
                ans.insert(ans.end(),tmp.begin(),tmp.end()); 
                
            }
        
        }
        
        return arr == ans;
    }
};
