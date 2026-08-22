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
        int i=0, n = s.length();
        while (i<n){
            string slen;
            while(s[i]!='#'){
                slen.insert(slen.end(),s[i]);
                i++;
            }
            i++;
            int len = stoi(slen);
            res.push_back(s.substr(i,len));
            i+=len;
        }
        return res;
    }
};
