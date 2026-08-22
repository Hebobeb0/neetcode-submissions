class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0,R=n;
        int mid = (L+R)/2;
        while(L<R){
            if (nums[mid]>=target){
                R = mid;
            } else{
                L = mid+1;
            }
            mid = (R+L)/2;
        }
        if(nums[mid] == target) return mid;
        else return -1;

    }
};
