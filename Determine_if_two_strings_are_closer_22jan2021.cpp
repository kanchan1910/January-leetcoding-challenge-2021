class Solution {
public:
    bool closeStrings(string word1, string word2) {
      int n1 = word1.length();
      int n2 = word2.length();
        if(n1 != n2)
        {
            return false;
        }
        unordered_map<char,int>m1,m2;
        for(int i = 0 ;i < n1 ; i++)
        {
            m1[word1[i]]++;
        }
        for(int i = 0; i <n2 ; i++)
        {
            m2[word2[i]]++;
        }
        set<int>s1,s2;
        set<char>ss1,ss2;
        for(auto x : m1)
        {
            ss1.insert(x.first);
            s1.insert(x.second);
        }
        for(auto x : m2)
        {
            ss2.insert(x.first);
            s2.insert(x.second);
        }
       return s1 == s2 && ss1 == ss2;
    }
};
// tc o(nwhere N is the size of the set. insert(): insert a new element. Its time complexity is O(logN) where N is the size of the setlogn) /// set insert operation takes logn time
// sc o(n)

class Solution {
public:
    bool closeStrings(string word1, string word2) {
      int n1 = word1.length();
      int n2 = word2.length();
        if(n1 != n2)
        {
            return false;
        }
        vector<int>v1(26,0),v2(26,0),v3(26,0),v4(26,0);
        for(int i =0 ;i < n1; i++)
        {
            v1[word1[i] - 'a']++;
            v3[word1[i] - 'a'] = 1;
        }
        for(int i = 0 ; i <n2 ; i++)
        {
            v2[word2[i] - 'a']++;
            v4[word2[i] - 'a'] = 1;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return (v1 == v2 && v3 == v4);
    }
};

// tc o(nlogn)
// sc o(n)
// this is more efficient solution
