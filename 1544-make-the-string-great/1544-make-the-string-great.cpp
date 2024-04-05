class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && s[i]-'a'<0){
                char ele=tolower(s[i]);
                if(ele==st.top()){
                    st.pop();
                    continue;
                }
            }
            else if(!st.empty()){
                if(st.top()-'a'<0){
                    char ele=tolower(st.top());
                    if(ele==s[i]){
                        st.pop();
                        continue;
                    }
                }
            }
            st.push(s[i]);
            
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};