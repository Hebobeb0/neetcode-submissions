class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> dist;
        auto cmp = [&dist](int a,int b){
            return dist[a]<dist[b];
        };
        int n = points.size();
        for(int i =0;i<n;++i){
            dist.push_back(sqrt( (pow(points[i][0],2)+pow(points[i][1],2))));

        }
        priority_queue<int,vector<int>, decltype(cmp)> pq(cmp);
        for(int i=0;i<n;++i){
            pq.push(i);
            if (pq.size()>k)pq.pop();
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(points[pq.top()]);pq.pop();
        }
        return res;
    }
};
