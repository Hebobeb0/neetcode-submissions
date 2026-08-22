class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<tuple<int,int>> stk;
        int n = temperatures.size();
        vector<int> res(n,0);
        for(int i = 0;i<n;i++){
            int temp = temperatures[i];
            if(!stk.empty()){
                int c = get<0>(stk.top());
                while(temp>c && !stk.empty()){
                    res[get<1>(stk.top())]=i-get<1>(stk.top());
                    stk.pop();
                    if ( !stk.empty()) c = get<0>(stk.top());
                }
            }
            stk.push(make_tuple(temp, i));
        }
        while(!stk.empty()){
            res[get<1>(stk.top())]= 0;
            stk.pop();
        }
        return res;
    }
};
