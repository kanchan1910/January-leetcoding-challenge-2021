class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>ss;
        
        for(int i = 0 ;i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                ss.push(s[i]);
            }
            else
            {
                if(ss.empty())
                {
                    return false;
                }
                if(ss.top() == '(' && s[i] != ')')
                {
                    return false;
                }
                if(ss.top() == '[' && s[i] != ']')
                {
                    return false;
                }
                if(ss.top() == '{' && s[i] != '}')
                {
                    return false;
                }
                ss.pop();
            }
        }
       if(!ss.empty())
       {
           return false;
       }
        return true;
    }
};

// tc o(n)
// sc o(n)
