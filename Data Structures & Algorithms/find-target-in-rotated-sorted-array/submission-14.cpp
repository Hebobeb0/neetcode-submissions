class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0, R = n-1;
        int mid = (L+R)/2;
        int count = 100;
        while(L<R-1){
            count--;
            cout<< L<<" "<<mid<<" "<<R<<endl;
            if(nums[mid] == target) return mid;
            if(nums[L]<nums[R]){
                if(nums[mid]>target) R = mid-1;
                else L = mid+1;
            }
            else{
                if(nums[mid]>nums[L]){
                    if(target>= nums[L] && target<nums[mid]) R = mid-1;
                    else L = mid+1;
                }
                else{
                    if(target> nums[mid] && target<= nums[R]) L = mid+1;
                    else R = mid-1;
                }
            }
            mid = (L+R)/2;
            
        }
        mid = (L+R)/2;
        cout<< L<<" "<<mid<<" "<<R<<endl;
        if(nums[mid] == target) return mid;
        if(R-L == 1 && nums[mid+1]==target) return mid+1;
        else return -1;
    }
};
