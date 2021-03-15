/*
    Notes:
    Straightforward. Trick is just use modulo for wrapping around of indicies.
    Indicies alwasy move rightwards so is easier than circular array (where we must worry about -1 index wrapping).
    Only hard part is handling empty at start as indicies are on top of each other.
    Use a bool member and update the enQueue() and dequeue methods to adjust it.
    
    


*/

class MyCircularQueue {
    
private:
    std::vector<int> q;
    int front;
    int back;
    bool empty;
    int max_size;
    
public:
    MyCircularQueue(int k) : q(std::vector<int>(k)), front(0), back(0), empty(true), max_size(k) {}
    
    
    bool enQueue(int value) {
        if(isEmpty()) {
            q[back] = value;
            empty = false;
            return true;
        }
        if(!isFull()) {
            back = (back + 1) % max_size;
            q[back] = value;
            return true;
        }
        return false;
        
    }
    
    bool deQueue() {
        if(!isEmpty()) {
            if(front == back) {
                empty = true;
            }    
            else {
                front = (front + 1) % max_size;
            }
                        
            return true;
        }
        
        return false;
    }
    
    int Front() {
        if(!isEmpty()) return q[front];
        
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()) return q[back];
        
        return -1;
    }
    
    bool isEmpty() {
        return empty;
    }
    
    bool isFull() {
        return ((back + 1) % max_size) == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
