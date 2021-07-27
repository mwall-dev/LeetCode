/*

    Notes:
        - Every t value is strictly larger!!!
        - We really onlyu need to store that 3000 range and it moves up so we can
        delete elements that go out of range.
        e.g. say we are given 1,2,3 and thuen 4000, these 1,2,3 wont contribute to 4000's count
        and since we will always get larger numbers we wont need them.


    Approach : Queue.
        - Store number of elements in queue as you add and subtract.
        - Add time t to queue.
        - Look at front of queue and delete elemenst that arent in range t to t - 3000 while
        editing count. (Note yes you actually do need to store the numbers).
        - Return the queue.size()

    Approach : Cirucular queue using array
        - Slightly faster.



*/



#define SIZE 3001


class CircularQueueFast {

private:

    int items[SIZE] = {0};
    int start = -1;
    int end = -1;
    int msize = 0;

public:
    CircularQueueFast() {}


    int front() {
        if(isEmpty()) return -30001;

        return items[start];
    }
    // Check if the queue is full
    bool isFull() {
        if (start == 0 && end == SIZE - 1) {
            return true;
        }

        if (start == end + 1) {
            return true;
        }

        return false;
    }

    int size() {
        return msize;
    }

    // Check if the queue is empty
    bool isEmpty() {
        if (start == -1) return true;

        return false;
    }


    // Adding an element
    void enQueue(int element) {
        if (isFull()) deQueue();

        if (start == -1) start = 0;
        end = (end + 1) % SIZE;
        items[end] = element;
        ++msize;
    }


    // Removing an element
    int deQueue() {
        int element;

        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return (-1);
        }

        element = items[start];
        if (start == end) {
            start = -1;
            end = -1;
        }

            // Q has only one element,
            // so we reset the queue after deleting it.
        else start = (start + 1) % SIZE;

        --msize;
        return element;
    }

};
class RecentCounter {
private:
    CircularQueueFast times{};


public:
    RecentCounter() {}

    int ping(int t) {
        times.enQueue(t);

        while(times.front() < t - 3000) {
            times.deQueue();
        }

        return times.size();
    }

};
/*

class RecentCounter {

private:
    std::queue<int> times;
public:
    RecentCounter() {}

    int ping(int t) {

        times.push(t);
        while(times.front() < t - 3000) {
            times.pop();
        }

        return times.size();

    }
}; */



/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */