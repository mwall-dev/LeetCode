/*
    Notes:
        - Looks to be just a brute force sort of thing checking each condition though
        there may be some smart optimisations or steps we can skip.
        - We're basically processing the absoulte path and trimming the fat to get the canonical path.
        - We need to get rid of all the:
            .
            ..
            multiple / in a row
            trailing / at end

        - Some potenial stuff ups:
           -  ... is a file name as its more than 2 periods. Though this rule doesn't apply to slashes.
           - We need to keep track of where we are and children/parent relationships, see example 4, we may
            have alot of .. that take us right around.

        - / is a directory.

        - What datastructure is best for just traversing and recording the relationships?
        (How would we do example 4)
        a
        |
        b
        Could use an n-ary tree where each child node has a link to parent.


        or use a stack instead.


    Approach:
        - Skip first char and for loop through characters.



    Optimise:
        Answer is very good and beats 100% runtime and 98% memory. Just dont like the waste of checking each 3 for ./ or ..//
        Maybe check for a . first and add a name if not??? Made a little helper function to achieve this as the if-else logic is a bit shit.




*/
class Solution {
public:

    bool isPrefix(std::string_view prefix, std::string_view full) {
        return prefix == full.substr(0, prefix.size());
    }

    void add_folder(std::string& path, std::string& canonical, int& i) {
        canonical.push_back('/');
        while(path[i] != '/') canonical.push_back(path[i++]);
    }

    string simplifyPath(string path) {
        // So our ./ and ../ matching work.

        path.push_back('/');

        std::string canonical;

        // Skip first '/'
        for(int i = 1; i < path.length(); ++i) {

            // Skip over slash repeats.
            if(path[i] == '/') continue;

            else if(path[i] == '.') {
                // Extract next 3 chars and check for a ./ or ../
                std::string check = path.substr(i, 3);

                if (isPrefix("./", check)) {
                    // No need to do anything here or add to i. Just catch it.
                }

                else if(isPrefix("../", check)) {

                    // Need to add 1 to i or the above if will trigger next loop (only 1 as the loop adds another 1 at end).
                    i += 1;

                    // No parent if its the root directory (could be 0 or 1 due to no slash yet, if its an immediate /../)
                    if(canonical.length() <= 1) continue;


                    // Pop the last name (go to parent).
                    while(canonical.back() != '/') canonical.pop_back();
                    canonical.pop_back(); // Get rid of the slash as we don't want on end.
                }

                else add_folder(path, canonical, i);
            }


                // Going into a new directory, push onto stack.
            else {
                add_folder(path, canonical, i);
            }
        }



        if(canonical.empty()) return "/";

        return canonical;
    }


};


/*
class Solution {
public:

    bool isPrefix(std::string_view prefix, std::string_view full) {
        return prefix == full.substr(0, prefix.size());
    }


    string simplifyPath(string path) {
        // So our ./ and ../ matching work.

        path.push_back('/');

        std::string canonical;

        // Skip first '/'
        for(int i = 1; i < path.length(); ++i) {

            // Skip over slash repeats.
            if(path[i] == '/') continue;

            // Extract next 3 chars and check for a ./ or ../
           std::string check = path.substr(i, 3);

            if (isPrefix("./", check)) {
                // No need to do anything here or add to i. Just catch it.
            }

            else if(isPrefix("../", check)) {

                // Need to add 1 to i or the above if will trigger next loop (only 1 as the loop adds another 1 at end).
                i += 1;

                // No parent if its the root directory (could be 0 or 1 due to no slash yet, if its an immediate /../)
                if(canonical.length() <= 1) continue;


                // Pop the last name (go to parent).
                while(canonical.back() != '/') canonical.pop_back();
                canonical.pop_back(); // Get rid of the slash as we don't want on end.

            }


            // Going into a new directory, push onto stack.
            else {
                canonical.push_back('/');

                while(path[i] != '/') canonical.push_back(path[i++]);
           }
        }



        if(canonical.empty()) return "/";

        return canonical;
    }


}; */

