class Solution {
public:
vector<vector<int>> res;int n;
    void dfs(vector<int>& nums, vector<bool>& visited, int k, vector<int>& temp){
        if(k == n) res.push_back(temp);
        else{
            for(int i=0;i<n;++i){
                if(!visited[i]){
                    visited[i]= true;
                    temp.push_back(nums[i]);
                    dfs(nums,visited,k+1, temp);
                    temp.pop_back();
                    visited[i]=false;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp;
        dfs(nums,visited,0,temp);
        return res;

    }
};
