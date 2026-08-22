class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int L=0,R=n-1;
        int mid = (L+R)/2;
        if(matrix[R][0]<= target) mid = R;
        else{
        while(L<R-1){
                if(matrix[mid][0]>target) R = mid-1;
                else L = mid;
                mid = (R+L)/2; 
        }}
        int m = matrix[0].size();
        int L2 = 0, R2 = m-1;
        int mid2= (L2+R2)/2;
        while(L2<R2){
                if(matrix[mid][mid2]>target) R2 = mid2-1;
                else if (matrix[mid][mid2] < target) L2 = mid2+1;
                else break;
                mid2 = (R2+L2)/2;
        }
        return matrix[mid][mid2]==target;
    }
};
