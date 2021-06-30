/*


    Notes:
        - Need to count the number of votes each team got for each position ranking. e.g. A got 3 votes for 1st, 2 votes for 2nd...
        -



    Approach : Custom lambda
        - Use a HashMap<Character, ArrayList<Integer>> for each team to store votes.
          Index 0 in the array represents number of votes for 1st place etc...

        - Then can iterate through and fill structure.

        - Sort the teams by the rank array using a sort function with a lambda.
        The lambda will compare the rank arrays of two teams, will iterate through until it finds a number that is larger on one.
        If the rank arrays are the same then it will order lexiographically.



    Approach : Similar but using some smart logic.
        - Basically have a 26x26 array to store whole alphabet if needed.
        - Put each team char at end of each array.
        - std::sort() works as you would expect for vectors of vectors. It starts at beginning and compares element by element
        until it finds one greater or lesser. Note that the vectors themselves are unchanged, they are just ordered differenty (think of the rows shifting around).
        - This solution uses that by using a negative count for vote.
        - std::sort() sorts ascneding by defualt and since it starts looking element by element at index 0 between the two vectors, this means that the team with the most negative vote count
        for 1st place will get its whole vector put first.
        - The insertion of each team char at the end of the array is fucking genius and is there to handle the lexiographic case when two teams have the exact same vote counts and the sort will reach the last element for both
        and compare lexiograhically.
        - Last loop just adds the chars to a string.



*/

/*

    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int>(27));
        for (char& c: votes[0])
            count[c - 'A'][26] = c;

        for (string& vote: votes)
            for (int i = 0; i < vote.length(); ++i)
                --count[vote[i] - 'A'][i];
        sort(count.begin(), count.end());
        string res;
        for (int i = 0; i < votes[0].length(); ++i)
            res += count[i][26];
        return res;
    }

*/





class Solution {
public:
    string rankTeams(vector<string>& votes) {
        std::unordered_map<char, int*> vote_counts;
        int num_teams = votes[0].size();

        // Pre-allocate space
        for(int i = 0; i < num_teams; ++i) {
            vote_counts[votes[0][i]] = new int[num_teams]();
        }


        // Fill vote data
        for(int place = 0; place < num_teams; ++place) {
            for(int entry = 0; entry < votes.size(); ++entry) {
                char team = votes[entry][place];
                ++vote_counts[team][place];
            }
        }

        // Take a string with all the teams.
        std::string result = votes[0];


        // Sort with lambda comparing two teams votes with each other.
        std::sort(result.begin(), result.end(), [&vote_counts, num_teams](char ch1, char ch2){
            int* ch1_votes = vote_counts[ch1];
            int* ch2_votes = vote_counts[ch2];

            for(int i = 0; i < num_teams; ++i) {
                if(ch1_votes[i] > ch2_votes[i]) return true;
                if(ch1_votes[i] < ch2_votes[i]) return false;
            }

            return ch1 < ch2;
        });

        return result;
    }
};