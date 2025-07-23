class Solution {
public:
    bool isValid(string s) {
        int i=0, n=s.size();
        vector<char> st;
        
        while(i<n){
            int len = st.size();
            if(s[i]=='c'){
                if(len<2 || st[len-1]!='b' || st[len-2]!='a') return false;
                st.pop_back();
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
            i++;
        }

        if(st.empty()) return true;
        return false;
    }
};