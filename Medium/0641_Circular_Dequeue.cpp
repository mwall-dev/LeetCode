class MyCircularDeque {
private:
    int front;
    int back;
    int max_size;
    int cnt;
    std::vector<int> vec;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : front(0), back(0), max_size(k), vec(k), cnt(0) {}

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(this->isFull()) return false;
        
        if(cnt == 0) {
            // do nothing
        }
        else front = (front + 1) % max_size;
        
        ++cnt;
        vec[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(this->isFull()) return false;

        if(cnt == 0) {
            // do nothing to the back variable.
        }
        else if(back == 0) back = max_size - 1;
        else --back;
        
        ++cnt;
        vec[back] = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(this->isEmpty()) return false;
        if(back == front) {
            cnt = 0;
            return true;
        }
        if(front == 0) front = max_size - 1;
        else --front;
        
        --cnt;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(this->isEmpty()) return false;
        if(back == front) {
            cnt = 0;
            return true;
        }
        if(back == max_size - 1) back = 0;
        else ++back;
        
        --cnt;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(this->isEmpty()) return -1;
        return vec[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(this->isEmpty()) return -1;
        return vec[back];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == max_size;
    }
};