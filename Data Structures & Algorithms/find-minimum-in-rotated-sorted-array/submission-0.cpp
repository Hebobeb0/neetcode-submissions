class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int L = 0, R = n-1;
        int mid = (L+R)/2;
        int res;
        if(nums[0]<=nums[R]) return nums[0];
        while(L<R){
            cout<<L<<" "<<mid<<" "<< R<<endl;
            if(nums[L]>nums[mid]) R=mid;
            else if (nums[R]< nums[mid]) L = mid+1;
            else {
                return nums[L];
            }
            mid = (L+R)/2;
        }
                    cout<<L<<" "<<mid<<" "<< R<<endl;
        return nums[mid];
    }
};
