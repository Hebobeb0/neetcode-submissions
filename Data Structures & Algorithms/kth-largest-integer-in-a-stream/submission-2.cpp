class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) { 
        K=k;
        for (auto i: nums){
            if(pq.size()>=k){
                if(i>pq.top()){
                    pq.pop();
                    pq.push(i);
                }
            }
            else{
                pq.push(i);
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size()<K) pq.push(val);
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
        
    }
};
