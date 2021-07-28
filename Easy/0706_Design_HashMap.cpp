/* Optiver fast_hashmap implementation */

#define MAX_SIZE 100000

class MyHashMap {

private:
    std::vector<std::pair<int,int>*> bucket_vector;

public:
    /** Initialize your data structure here. */
    MyHashMap() : bucket_vector(MAX_SIZE + 1, nullptr) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int key_search = search_map(key, true);
        bucket_vector[key_search] = new std::pair<int,int>(key, value);
    }


    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int key_search;
        if((key_search = search_map(key, false)) != -1) {
            return bucket_vector[key_search]->second;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int key_search;
        if((key_search = search_map(key, false)) != -1) {
            delete bucket_vector[key_search];
            bucket_vector[key_search] = nullptr;
        }

    }

    // Searches for key in map. If it exists return the bucket index, else return -1
    // Bad code smell to have the bool param but it does make things concise and the method does only do one thing really.
    int search_map(int key, bool is_insert) {
        int key_search = key % MAX_SIZE;

        while(auto* entry = bucket_vector[key_search]) {
            if(entry->first == key) {
                return key_search;
            }

            else key_search = (key_search + 1) % MAX_SIZE;

        }

        if(is_insert) return key_search; // As key_search represents the spot we can insert into.

        return -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */