class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n=deck.size();
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int> ans(n);
        sort(deck.begin(),deck.end());
        int i=0;
        while(!q.empty()){
            int ind=q.front();
            ans[ind]=deck[i++];
            q.pop();
            if(!q.empty()){
                int last=q.front();
                q.pop();
                q.push(last);
            }
        }
        return ans;
    }
};