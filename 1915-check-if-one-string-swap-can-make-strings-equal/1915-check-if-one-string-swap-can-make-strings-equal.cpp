class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), cnt = 0;
        vector<int> freq(26,0);
        if(n1 != n2) return false;
        for(int i=0;i<n1;i++){
            if(s1[i]!=s2[i]) cnt++;
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        if(cnt == 0 || cnt == 2) return true;
        return false;
    }
};