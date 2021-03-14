class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPresent=false;
        unordered_set<string>s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
            if(wordList[i]==endWord){
                isPresent=true;
            }
        }
        if(isPresent==false){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int level=0;
        while(!q.empty()){
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                string cur=q.front();
                q.pop();
                for(int j=0;j<cur.length();j++){
                    string tmp=cur;
                   for(int ch='a';ch<='z';ch++){
                       tmp[j]=ch;
                       
                        if(tmp==cur){
                            continue;
                        }
                        else if(tmp==endWord){
                            return level+1;
                        }
                        else if(s.find(tmp)!=s.end()){
                            s.erase(tmp);
                            q.push(tmp);
                        }
                }
                }
               
            }
        }
        return 0;
    }
};
