class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<double,double>>> pq;

        int len=classes.size();

        for(auto it:classes){
            double n=it[0], d=it[1];
            double ratio=((n+1)/(d+1)) - (n/d);
            pq.push({ratio,{d,n}});
        }

        while(extraStudents){
            auto ele=pq.top();
            pq.pop();
            double d=ele.second.first;
            double n=ele.second.second;
            n++;
            d++;
            double ratio=((n+1)/(d+1)) - (n/d);
            pq.push({ratio, {d,n}});
            extraStudents--;
        }
        
        double ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            double d=it.second.first;
            double n=it.second.second;
            pq.pop();
            ans+=(n/d);
        }
        return ans/len;
    }
};