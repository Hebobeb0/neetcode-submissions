class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int L=0; int R=n-1;
        int temp; temp = numbers[L]+numbers[R];
        while(temp != target){
            if (temp< target){
L+=1;
            }
            if (temp> target){
                R-=1;
            }
            temp = numbers[L]+numbers[R];
        
        }
        vector<int> temparr = {L+1,R+1};

        return temparr;
    }
};
