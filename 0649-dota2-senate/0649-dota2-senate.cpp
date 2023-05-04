class Solution {
public:
    string predictPartyVictory(string senate) {
        int len=senate.length();
        queue<int> rq,dq;
        for(int i=0;i<len;i++){
            (senate[i]=='R') ? rq.push(i) : dq.push(i);
        }
        while(!rq.empty() && !dq.empty()){
            int r_ind=rq.front();
            rq.pop();
            int d_ind=dq.front();
            dq.pop();
            (r_ind < d_ind) ? rq.push(r_ind + len) : dq.push(d_ind + len);  
        }
        return (rq.size() > dq.size()) ? "Radiant" : "Dire";
    }
};