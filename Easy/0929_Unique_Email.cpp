/*
    Notes:
        Looking for number of unique addresses.



    Approach:
        Iterate through the array of addresses.
            Process the address by eliminating all dots before the ampersand, and all chars after a +. Do the +'s first as we might save on processing.
            Check hashmap for the cleaned string. If it exists dont add to count.











*/



class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        std::unordered_set<std::string> addresses_recieved;

        for(auto& str : emails) {
            clean_address(str);
            if(addresses_recieved.find(str) == addresses_recieved.end()) {
                addresses_recieved.insert(str);
            }
        }
        return addresses_recieved.size();

    }

    void clean_address(std::string& str) {
        // Look for +'s
        int index = 0;
        int plus_index = 0; // Spec says + will never be index 0.
        bool found_plus = false;

        while(str[index] != '@') {
            if(str[index] == '+' && !found_plus) {
                plus_index = index;
                found_plus = true;
            }
            ++index;
        }

        if(plus_index) {
            str.erase(plus_index, index - plus_index);
        }

        index = 0;
        // Look for .'s
        while(str[index] != '@') {
            if(str[index] == '.') {
                str.erase(index, 1);
            }
            ++index;
        }
        std::cout << str << std::endl;
    }
};