class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L=1, R = *max_element(piles.begin(),piles.end());
        if(h==piles.size()) return R;
        int mid = (L+R)/2;
        int res = R;
        while(L<R){
            int temp=0;
            for(int pile : piles){
                temp+= ceil(double(pile)/double(mid));
            }
            if (temp<=h){
                res = min(mid,res);
                R=mid-1;
            }
            else L = mid +1;
            cout<<mid<<" "<<temp<<endl;
            mid = (L+R)/2;
        }
                int t=0;
        for(int pile:piles){
            t+= pile/mid + 1;
        }
        if (t<=h) res = min(mid,res);
        return res;
    }
};
