class Solution {
    
public:
    vector<int> maxwidth = vector<int>(1001, 0);
    vector<stack<int>> stacks = vector<stack<int>>(1001);
    void addBlok(int j, int i){
        if(stacks[j].empty() || stacks[j].top()==i-1) stacks[j].push(i);
        else{
            maxwidth[j] = max(maxwidth[j], (int)stacks[j].size());
            while(!stacks[j].empty()) stacks[j].pop();
            stacks[j].push(i);
        }
        maxwidth[j] = max(maxwidth[j], (int)stacks[j].size());
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        for(int i=0;i<n;++i){
            int height = heights[i];
            for(int j=1;j<=height;++j){
                addBlok(j,i);
            }
        }
        int res=0;
        for(int i=1;i<=1000;++i){
            res = max(res, maxwidth[i]*i);
        }
        return res;
    }
};
