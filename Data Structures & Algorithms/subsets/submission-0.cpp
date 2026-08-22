class Solution {
    
public:
vector<vector<int>> res;int n;
    void add(vector<bool>&visited,vector<int>& nums){
        vector<int> temp;
        for(int i=0;i<n;++i){
            if(visited[i]) temp.push_back(nums[i]);
        }
        res.push_back(temp);
    }
    void dfs(int m, vector<bool>& visited, vector<int>& nums){
        if(m==n) add(visited,nums);
        else{
            dfs(m+1,visited,nums);
            visited[m]=true;
            dfs(m+1,visited,nums);
            visited[m]=false;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<bool>visited(n,false);
        dfs(0,visited, nums);
        return res;
    }
};
