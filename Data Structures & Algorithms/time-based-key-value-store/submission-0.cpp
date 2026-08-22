class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key)== mp.end()) mp[key] = vector<pair<int,string>>(0);
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        int L = 0, R = (int)mp[key].size()-1;
        int res=-1;
        while(L<=R){
            int mid = (L+R)/2;
            if(mp[key][mid].first == timestamp) return mp[key][mid].second;
            if(mp[key][mid].first <= timestamp) {
                res = mid;
                L = mid+1;
            }
            else R = mid-1;
        }
        if(res!=-1) return mp[key][res].second;
        else return "";
    }
};
