//------------ Approach 1 ----------//
/*
-> Using inbuilt deque
deque -> can append from any end, can pop from any end
circular deque -> implementation detail that means you won't need to allocate additional memory while using the deque.
*/

class MyCircularDeque {
private:
    deque<int> dq;
    int k;
public:
    //In this initializer list, k(k) means "initialize the member variable k with the value of the parameter k".
    MyCircularDeque(int k) {
        //Assigning the value of the parameter to the member variable inside the constructor body. 
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        //another way to check if deque is full:
        // if(dq.size()==k){
        //     return false;
        // }

        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(dq.empty()){
            return false;
        }
        //another way to check if deque is empty:
        // if(dq.size()==NULL){
        //     return false;
        // }
        dq.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(dq.empty()){
            return false;
        }
        dq.pop_back();
        return true;
    }
    
    int getFront() {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }
    
    int getRear() {
        if(dq.empty()){
            return -1;
        }
        return dq.back();
    }
    
    bool isEmpty() {
        if(dq.size()==NULL){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(dq.size()==k){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */


//----------- Approach 2 -----------//
/*
-> Using array
Consider two pointers front and rear 
-> As datastructure needs to be circular, while incrementing rear or decrementing front, we need to use '%'
Inserting at front -> 
    dq[front] = value
    front = (front-1+k)%k

Inserting at rear ->
    dq[rear] = value
    rear = (rear+1)%k

So, in case of circular:
increment -> (+1)%k
decrement -> (-1+k)%k

*/
class MyCircularDeque {
private:
    int K;
    int front;
    int rear;
    int currentCount;
    vector<int> dq;
    
public:
    MyCircularDeque(int k) {
        K = k;
        front = 0;
        rear = K-1;
        currentCount = 0;
        dq = vector<int>(K, 0);
    }
    
    bool insertFront(int value) {
       if(isFull()){
        return false;
       }
       
       front = (front-1+K)%K;
       dq[front] = value;
       currentCount++;
       return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear+1)%K;
        dq[rear] = value;
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front+1)%K;
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
       if(isEmpty()){
        return false;
       }
       rear = (rear-1+K)%K;
       currentCount--;
       return true;
    }
    
    int getFront() {
       if(isEmpty()){
        return -1;
       }
       return dq[front];
    }
    
    int getRear() {
       if(isEmpty()){
        return -1;
       }
       return dq[rear];
    }
    
    bool isEmpty() {
       return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == K;
    }
};
