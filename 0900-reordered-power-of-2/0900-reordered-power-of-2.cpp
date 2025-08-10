class Solution {
public:
    bool check(int n){
        int num=pow(2,30);
        return num%n==0;
    }
    
    // bool solve(int i, vector<int> &freq, int cnt, int num, bool first){
    //     if(cnt==i){
    //         cout<<num<<' ';
    //         return check(num);
    //     }
    
    //     bool take=0;
    //     for(int j=0;j<10;j++){
    //         if(freq[j]>0){
    //             if(j==0 && first) continue;
    //             else{
    //                 freq[j]--;
    //                 if(solve(i+1,freq,cnt,num*10+j,false)) return true;
    //                 freq[j]++;
    //             }
    //         }
    //     }
    //     return false;
    // }

    string sortedStr(int n){
        string s=to_string(n);
        sort(s.begin(), s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        if(n==0) return false;
        // vector<int> freq(10);
        // int num=n, cnt=0;
        // while(num){
        //     freq[num%10]++;
        //     num/=10;
        //     cnt++;
        // }
        // return solve(0,freq,cnt,0,true);

        string s=sortedStr(n);

        for(int i=0;i<30;i++){
            if(s == sortedStr(1<<i)) return true;
        }
        return false;
    }
};