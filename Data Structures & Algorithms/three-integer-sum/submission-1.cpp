class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int L = i + 1,R = n-1;
            while(L<R){
                int m = nums[L]+nums[R]+nums[i];
                if(m>0) R--;
                if(m<0) L++;
                if(m==0){
                    res.push_back({nums[L],nums[R],nums[i]});
                    L++;
                    R--;
                    while(L<R && nums[L]==nums[L-1]) L++;
                }
            }
        }
        return res;
    }
};
