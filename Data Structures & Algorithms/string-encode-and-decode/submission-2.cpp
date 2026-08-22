class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s : strs){
            int n = s.length();
            res.append(to_string(n));res.append("#");res.append(s);
        }
        cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        while (s.length()){
            string slen;
            while(s.front()!='#'){
                slen.insert(slen.end(),s.front());
                s.erase(s.begin());
            }
            s.erase(0,1);
            int len = stoi(slen);
            res.push_back(s.substr(0,len));
            s.erase(s.begin(),s.begin()+len);
        }
        return res;
    }
};
