/*
 *  Notes:
 *      - Hard to know what to sort by. If there are two tasks with different enqueueTimes
 *      but different processing times e.g. [7, 32] and [8,2] and we are finishing a task [2, 9] then we will actually
 *      choose the task with the later enquire time [8,2] as it is available .
 *      - Its all about what is available  at the time.
 *      - Could use a priority queue with elements that are the index and the processtime. Ensuring that at each time
 *      point we can add it to the pool of available  tasks and resort the pool.
 *      - We could use a std::map but we only need to get the min element so a heap is better. They do provide similar
 *      services though.
 *      - std::pair actually has a custom comparator function that works perfect for this. It compares first elements
 *      and then second elements. DO need to change to std::greater to get min at top though.
 *      - Must store original indicies as tasks might be in weird order (e.g [32,2], [3,40] meaning its index 1 we will do first
 *      but our sort will put it as index 0).
 *
 *
 *  Approach:
 *      - Sort tasks by enquire time (time they will become available).
 *      - Start at time = 1 and have an index i for the array to look for tasks that become available at that time point.
 *      - Add them to a pool if so.
 *      - When execueting a task just add time in full and then add multiple tasks after if they have become avaialbe.
 *
 *
 *
 */
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        // Append indicies to each task.
        for (int i = 0; i < tasks.size(); ++i) tasks[i].push_back(i);

        std::sort(tasks.begin(), tasks.end(), [](const std::vector<int>& x1, const std::vector<int>& x2){
            return x1[0] < x2[0];
        });


        std::priority_queue<pair<int,int>,vector<pair<int,int>>, std::greater<std::pair<int,int>>>                          available_tasks; // <processing_time, index>

        std::vector<int> result;

        int i = 0;
        long time = tasks[0][0]; // To start at first task.

        while(result.size() != tasks.size()) {

            // Check for new available tasks given new time point.
            while(i < tasks.size() && tasks[i][0] <= time) {

                // Prioritize low process time then low index.
                available_tasks.push({tasks[i][1], tasks[i][2]});
                ++i;
            }

            // If no avaliable tasks then skip to next one.
            if(available_tasks.empty()) {
                time = tasks[i][0];
                continue;
            }

            // Do a task
            auto& task_to_do = available_tasks.top();
            result.push_back(task_to_do.second);
            time += task_to_do.first;
            available_tasks.pop();
        }

        return result;


    }
};