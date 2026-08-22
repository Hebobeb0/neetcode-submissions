class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int m = s.length();
        unordered_set<string> wrdDict;
        for(string s: wordDict){
            wrdDict.insert(s);
        }
        vector<bool> arr(m+1,false);
        arr[0] = true;
        for(int i=1;i<=m;++i){
            if(wrdDict.find(s.substr(0,i)) != wrdDict.end()){
                arr[i] = true;
                continue;
            }
            for(int j = 0;j<i ;++j){
                if(arr[j]&& wrdDict.find(s.substr(j, i-j))!= wrdDict.end()){
                    arr[i] = true;
                    continue;
                }
            }
        }
        for(auto i:arr){
            cout<<i<<" ";
        }
        return arr[m];
    }
};
