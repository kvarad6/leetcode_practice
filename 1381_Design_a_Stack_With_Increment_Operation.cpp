//--------------- Approach 1 --------------//
//Using vector/ array

class CustomStack {
private:
    vector<int> arr;
    int count;
    int maxElements;
public:
    CustomStack(int maxSize) {
        // arr = vector<int>(maxSize);
        arr.reserve(maxSize);
        count = 0;
        maxElements = maxSize;
    }
    
    void push(int x) {
        if(count<maxElements){
            arr[count] = x;
            count++;
        }
        
    }
    
    int pop() { 
        if(count==0){
            return -1;
        }
        // int top = arr.back();
        // arr.pop_back();
        // count--;
        // return top;
        count--;
        return arr[count];
    }
    
    void increment(int k, int val) {
        int limit = min(k, count);
        for(int i=0;i<limit;i++){
            arr[i] += val;
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
