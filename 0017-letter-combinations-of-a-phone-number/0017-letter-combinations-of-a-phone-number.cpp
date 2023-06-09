class Solution {
private:
    void letterCombinations(string digits, vector<string>& output, string &temp, vector<string>& pad, int index){
        if(index == digits.size()){
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(auto val:value){
            temp.push_back(val);
            letterCombinations(digits, output, temp, pad, index+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        string temp;
        letterCombinations(digits, output, temp, pad, 0);
        return output;
    }
};
