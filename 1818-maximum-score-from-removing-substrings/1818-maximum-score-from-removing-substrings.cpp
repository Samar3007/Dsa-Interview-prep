class Solution {
public:
    string trav(string s, string str, int n){
        stack<char> st;
        int i=0;

        while(i<n){
            if(!st.empty() && st.top()==str[0] && s[i]==str[1]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }

        string temp;
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        
        int ans=0, n=s.size();
        
        string maxi = (x>y) ? "ab" : "ba";
        string mini = (x>y) ? "ba" : "ab";
        
        string temp = trav(s, maxi, n);
        int L = temp.size();
        
        int removed = n-L;
        ans+=max(x,y)*(removed/2);

        cout<<maxi<<' '<<mini<<' '<<ans;
        
        string last = trav(temp, mini, L);
        removed = L-last.size();
        ans+=min(x,y)*(removed/2);

        cout<<ans;
        return ans;
    }
};