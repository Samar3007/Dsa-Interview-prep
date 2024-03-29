class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize= maxHeap.size();
        int rsize= minHeap.size();
        if(lsize==0){
            maxHeap.push(num);
        }
        else if(lsize==rsize){
            if(num>minHeap.top()){
                int temp=minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{
            if(minHeap.size()==0){
                if(num>=maxHeap.top()){
                    minHeap.push(num);
                }
                else{
                    int temp=maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);   
                    minHeap.push(temp);
                }
            }
            else if(num>=minHeap.top()){
                minHeap.push(num);
            }
            else{
                if(num<maxHeap.top()){
                    int temp=maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);   
                    minHeap.push(temp);
                }
                else{
                    minHeap.push(num);
                }
            }
            
        }
    
    }
    
    double findMedian() {
        int lsize= maxHeap.size();
        int rsize= minHeap.size();
        if(lsize > rsize){
            return double (maxHeap.top());
        }
        else{
            return double (maxHeap.top()+minHeap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */