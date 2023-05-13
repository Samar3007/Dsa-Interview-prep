class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
        }
        int count=0;
        while(!st.empty()){
            char top=st.top();
            st.pop();
            if(top!=' '){
                count++;
            }
            else if(count!=0 && top==' ')
                return count;
        }
        return count;
    }
};