/*

    Approach 1: Store all in a vector but sum as you go.
    1: push_back(x)

    2. push_back(last two)

    3. push_back(2 * last one)

    4. pop_back();







*/



class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        vector<int> scores;

        for(const auto& op : ops) {
            if(op == "+") scores.push_back(scores[scores.size()-1] + scores[scores.size() - 2] );
            else if(op == "D") scores.push_back(scores[scores.size()-1] * 2);
            else if(op =="C") scores.pop_back();
            else scores.push_back(std::stoi(op));
        }

        return std::accumulate(scores.begin(), scores.end(), 0);
    }
};