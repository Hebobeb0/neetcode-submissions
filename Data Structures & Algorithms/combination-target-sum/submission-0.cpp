class Solution {
public:
    int n;
    vector<vector<int>> res;
    void dfs(int k, int sum, vector<int>& nums, int target, vector<int>& temp){
        if(sum==target){
            res.push_back(temp);
            return;
        }
        if(sum>target|| k==n)return;
        int num = nums[k];
        dfs(k+1,sum,nums,target,temp);
        for(int i = 1;i<= (int)((double)target/(double)num);++i){
            sum+=num;
            temp.push_back(num);
            dfs(k+1,sum,nums,target,temp);
        }
        for(int i=1;i<=(int)((double)target/(double)num);++i){
            temp.pop_back();
            sum-=num;
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> temp;
        vector<bool> visited(n,false);
        dfs(0,0,nums,target,temp);
        return res;
    }
};
