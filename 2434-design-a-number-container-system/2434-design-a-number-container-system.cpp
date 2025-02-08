class NumberContainers {
public:
    NumberContainers() {
        
    }
    unordered_map<int,int> IndNum;
    unordered_map<int,set<int>> NumInd;
    void change(int index, int number) {
        int num = 0;
        if(IndNum.find(index) != IndNum.end()){
            num = IndNum[index];
            NumInd[num].erase(index);
        }
        IndNum[index] = number;
        NumInd[number].insert(index);
    }
    
    int find(int number) {
        if(NumInd.find(number) == NumInd.end() || NumInd[number].empty()) return -1;
        return *NumInd[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */