/*
    Approach:
    e.g trust[2] = [3,4] meaning 3 trusts 4. (index doesnt mean anything).       
    
    1. To satisfy 1, need to find a number in 1 to N that isnt present in any trust[i][0] as they trust no one.
    2. To satisfy 2, need to find a number in 1 to N that every other number 1-N trusts. (trust[i][1])
    3. To satisfy 3, the above can only happen once.
    
    
    Best to check if there is no judge first as if it fails one condition then we can return early.
    
    1. Iterate through 1 to N and look at all trust[i][0] and find the people who dont trust anyone.
    Use a hashmap. If there are more than two people that dont trust anyone then this violates second condition.
    If 1 then good. Check for set size N-1 and then use N(N+1)/2 to find missing number.
    
    2. Iterate through list and again use hashset to find all people that trust this person, must have N-1 elements to be valid.
    
    3. Need to check that there isnt somebody that everybody else all trusts but this is impossible if we find more than one 
    person that satisfies 1.


    Apporach 2: Directed Graph 
    Intuition:
Consider trust as a graph, all pairs are directed edge.
The point with in-degree - out-degree = N - 1 become the judge.

Explanation:
Count the degree, and check at the end.

Time Complexity:
Time O(T + N), space O(N)


C++:

    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N + 1, 0);
        for (auto& t : trust)
            count[t[0]]--, count[t[1]]++;
        for (int i = 1; i <= N; ++i) {
            if (count[i] == N - 1) return i;
        }
        return -1;
    }


*/


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        std::unordered_set<int> trust_set;
        int sum = 0;
        
        // Property 1
        for(const auto& trust_link : trust) {
            if(trust_set.insert(trust_link[0]).second) {
                sum += trust_link[0];
            }
        }
        
        
        if(trust_set.size() != N - 1) return -1;
        
        int one_to_N = ((N*(N+1)) / 2);
        int judge =  one_to_N - sum; 
    
        // Property 2
        trust_set.clear();
        
        for(const auto& trust_link : trust) {
            if(trust_link[1] == judge) {
                trust_set.insert(trust_link[0]);
            }
        }
        
        if(trust_set.size() == N - 1) return judge;
        
        else return -1;
    }
};