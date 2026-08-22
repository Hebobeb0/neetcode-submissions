class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        string symbols = "+-*/";
        for (auto i:tokens){
            bool issym = (i.size()==1 && symbols.find(i[0])!=string::npos);
            if (!issym){
                stk.push(stoi(i));
            }
            else{
                int temp;
                int b = stk.top(); stk.pop();int a = stk.top();stk.pop();
                if(i == "+") temp = a+b;
                else if (i == "-") temp = a-b;
                else if (i=="*") temp = a*b;
                else temp = a/b;
                stk.push(temp);
            }
        }
        return stk.top();
    }
};
