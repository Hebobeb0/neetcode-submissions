class Solution {
public:
    bool isValid(string s) {
        map<char,char> l = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};
        
        stack<char> stk;
        int i =0;
        while(i<s.length()){
            char c = s[i];
            if (c == '(' || c == '{' || c == '['){
                    stk.push(c);
                }
            else if(not stk.empty()){
                char t = stk.top();
                if(l[t] == c) stk.pop();
                else {return false;}
            }
            else return false;
            i++;
            
        }
        if(stk.empty()) return true;
        else {return false;}
        
    }
};
