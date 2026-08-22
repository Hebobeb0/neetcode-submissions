class MedianFinder {
public:
    priority_queue<int> smol;
    priority_queue<int, vector<int>, greater<int>> big;
    MedianFinder() {
    }
    void addNum(int num) {
        smol.push(num);
        if(smol.size()>big.size()+1) {big.push(smol.top()); smol.pop();}
        if(!big.empty() && smol.top()>big.top()){
            int p = smol.top(), q = big.top();
            smol.pop();big.pop();
            smol.push(q);big.push(p);
        }
    }
    
    double findMedian() {
        if(smol.size()==big.size()) return ((double)(smol.top()+big.top()))/2;
        else return smol.top();
    }
};
