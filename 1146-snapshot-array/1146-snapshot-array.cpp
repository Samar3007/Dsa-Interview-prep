class SnapshotArray {
public:
    vector<map<int,int>> Arr;
    int s_id=0;
    SnapshotArray(int length) {
        Arr.resize(length);
        for(int i=0;i<length;i++){
            Arr[i][0]=0;
        }
        return;
    }
    
    void set(int index, int val) {
        Arr[index][s_id]=val;
        return;
    }
    
    int snap() {
        s_id++; 
        return s_id-1;
    }
    
    int get(int index, int snap_id) {
        auto it = Arr[index].upper_bound(snap_id);
        if(it==Arr[index].begin()){
            return 0;
        }
        it--;
        return it->second;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */