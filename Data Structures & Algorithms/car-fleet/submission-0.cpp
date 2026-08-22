class Solution {
public:
    struct car{
        int pos;
        int speed;
    };
    static bool poscmd(const car a, const car b){
        return a.pos>b.pos;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<car> cars;
        for(int i = 0;i<n;++i){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),poscmd);
        int res=0;
        stack<car> stk;
        for(int i=0;i<n;++i){
            if(!stk.empty()){
                float time1 = (float)(target - stk.top().pos)/(float)(stk.top().speed), time2 = (float)(target - cars[i].pos)/(float)(cars[i].speed);
                if (stk.top().speed>=cars[i].speed) stk.push(cars[i]);
                else if(time1<time2) stk.push(cars[i]);
                else continue;
            }
            else stk.push(cars[i]);
        }
        while(!stk.empty()){
            res++;
            stk.pop();
        }
        return res;

    }
    
};
