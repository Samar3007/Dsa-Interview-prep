class CustomStack {
public:
    int *arr;
    int size;
    int top;
    CustomStack(int maxSize) {
        this->size=maxSize;
        top=0;
        arr = new int[size];
    }
    
    void push(int x) {
        if(top<size){
            arr[top]=x;
            top++;
        }
        return;
    }
    
    int pop() {
        if(top>0){
            int temp=arr[top-1];
            top--;
            return temp;
        }
        return -1;
        
    }
    
    void increment(int k, int val) {
        if(size>=k){
            for(int i=0;i<k;i++){
                arr[i]=arr[i]+val;
            }
        }
        else{
            for(int i=0;i<size;i++){
                arr[i]=arr[i]+val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */