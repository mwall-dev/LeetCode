
/*
 *
 *
 * Notes:
 *  Need to retrieve min in constant time. Pop's make this hard as it means we need to keep track of all mins.
 *  Use a map with frequncy count for storing mins. Constant access to begin().
 *
 *
 * Approach 1:
 *  push - add element onto stack. Check if it is less than min and add to a map with freq count.
 *  pop - subtract from freq count in map. If freq count is 0 for that number than remember to erase entry.
 *  top - top of stack.
 *  getMin() - look at map.begin()
 *
 *  Approach 2:
 *  For each node in stack store a min val which represents the min val below.
 *  Use vector of pairs.
 *
 *  push - Check top of stack. If val to be added is less than min than make this new min in entry and add in stack.
 *  else just add val with the old min. Need to be careful that stack is not empty when we are getting current_min.
 *
 *  pop - just remove
 *  top - simple top.
 *  getMin - simple look at top and get min val.
 *
 *
 *
 *
 *  Optimise:
 *  See Approach 2.
 *
 *
 */


// Approach 2 - Using hint: "Consider each node in stack having a min val".
class MinStack {
private:
    std::vector<std::pair<int, int> > stck;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        int current_min = stck.empty() ? INT_MAX : stck.back().second;

        if(val < current_min) stck.push_back({val, val});

        else stck.push_back({val, current_min});

    }

    void pop() {
        stck.pop_back();
    }

    int top() {
        int res = stck.back().first;
        return res;
    }

    int getMin() {
        int res = stck.back().second;
        return res;
    }
};


/*
// Approach 1
class MinStack {
private:
    std::vector<int> stck;
    std::map<int, int> freq_count;

public:
    MinStack() {}

    void push(int val) {
        stck.push_back(val);
        ++freq_count[val];
    }

    void pop() {
        int val = stck[stck.size() - 1];
        stck.pop_back();
        int count = --freq_count[val];
        // Erase entries with 0 freq.
        if(!count) freq_count.erase(val);
    }

    int top() {
        return stck[stck.size() - 1];
    }

    int getMin() {
        return (*freq_count.begin()).first;
    }
};
*/
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */