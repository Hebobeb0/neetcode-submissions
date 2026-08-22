class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmax=1,curmin=1;
        int res=nums[0];
        for(int num:nums){
            int tmp = curmax*num;
            int tmp2 = curmin*num;
            curmax = max(max(tmp,tmp2),num);
            curmin = min(min(tmp,tmp2),num);
            res= max(curmax, res);
            cout<<curmax<<" "<< curmin<<" "<<res<<endl;
        }
        return res;
    }
};
