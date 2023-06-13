class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        set<int> s;
        for(int x:arr){
            mpp[x]++;
        }
        for(auto m:mpp){
            s.insert(m.second);
        }
        if(s.size()==mpp.size()) return true;
        return false;
    }
};