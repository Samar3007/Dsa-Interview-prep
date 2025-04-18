class Solution {
public:

    string countAndSay(int n) {
        string st = "1";
        for(int i=1;i<n;i++){
            int ind = 0;
            string temp="";
            while(ind<st.size()){
                char c = st[ind];
                int cnt=0;
                while(ind<st.size() && st[ind]==c){
                    cnt++;
                    ind++;
                }
                temp+=to_string(cnt);
                temp+=c;
            }
            st=temp;
        }
        return st;
    }
};