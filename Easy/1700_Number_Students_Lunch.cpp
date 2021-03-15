/*

    Notes:
        j = 0 is front of queue.
        
        To save space and time and save the operation of putting into queues and stacks, we use pointers for front of queue.
        
        i = 0 is top of stack.
    
    Approach:
        Brute force:
        
        
    Appraoch:
        Count how many will eat. then just subtract from students.
        Literally, count 1's and 0's in sandwiches and compare with students.
        
        Trick is that sometimes you get trapped with a 0 sandwich at top of stack and only 1 studnets left so
        these studnets dont eat even if there are 1 sandwiches left as there is no 0 student to remove the 0 sandwich.

*/







class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    
     int count_0 = 0;
     int count_1 = 0;
    
     for(int i = 0; i < students.size(); ++i) {
        if(students[i] == 0) ++count_0;
        else ++count_1;
     } 
        std::cout << count_1 << " " << count_0 << std::endl;
    
     for(int i = 0; i < sandwiches.size(); ++i) {
        if(sandwiches[i] == 0 && count_0) --count_0;
        else if(sandwiches[i] == 1 && count_1) --count_1;
        else {
            break;
        }

         
     }   
        
    return count_0 + count_1;
    
        
    }
        
};
