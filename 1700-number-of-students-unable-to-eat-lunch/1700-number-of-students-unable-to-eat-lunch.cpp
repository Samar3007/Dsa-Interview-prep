class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int l=0;
        for(int i=0;i<n;i++){
            int j=i;
            while(true){
                if(students[j]==sandwiches[l]){
                    l++;
                    students[j]=-1;
                }
                if(l==n) return 0;
                j=(1+j)%n;
                if(j==i) break;
            }
        }
        return n-l;
    }
};