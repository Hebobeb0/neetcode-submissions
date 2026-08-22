class Solution {
public:
    int trap(vector<int>& height) {
        int vol=0;
        int L=0,R=1;
        int n = height.size();
        if(n<3) return 0;
        int temp=0;
        while(R<n){
            int l=height[L],r=height[R];
            if(r>=l){
                for(int j = 1;j<=R-L;j++){
                    height[L+j]=max(l,height[L+j]);
                }
                L = R;
                vol +=temp;
                temp=0;

            }
            else{
                temp+=l-r;
            }
            R++;
        }
        for (auto i: height){
            cout<<i<<' ';
        }
        cout<<endl;
        L=n-2;R=n-1;
        temp=0;
        while(L>-1){
            int l=height[L],r=height[R];
            if(l>=r){
                for(int j = 0;j<R-L;j++){
                    height[R-j]=max(r,height[R-j]);
                }
                R=L;
                vol+=temp;
                temp = 0;

            }
            else{
                temp+=r-l;
            }
            L--;
        }
        for (auto i: height){
            cout<<i<<' ';
        }
        return vol;
    }
};
