class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxv = 0;
        int n = heights.size();
        int L=0,R=n-1;
        maxv = (R-L)*min(heights[L],heights[R]);
        while(L<R){
            int l = heights[L], r = heights[R];
            if(l<r){
                L++;
            }
            if(l>r){
                R--;
            }
            if(L==R)continue;
            if(l==r){
                L++;
                R--;
            }
            l = heights[L]; r = heights[R];
            maxv=max(maxv, (R-L)*min(l,r));
        
        }
        return maxv;
    }
};
