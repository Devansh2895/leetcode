class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Defining a pair type to represent (processing time, task index)
        typedef pair<int, int> pd;

        // Priority queue to process tasks with the shortest processing time first
        // The greater comparator ensures the smallest element (by processing time) is at the top
        priority_queue<pd, vector<pd>, greater<pd>> pq;

        int n = tasks.size();  // Number of tasks

        // Create a vector of tuples to store tasks as (start_time, processing_time, task_index)
        vector<tuple<int, int, int>> taskList;
        for (int i = 0; i < n; i++) {
            taskList.emplace_back(tasks[i][0], tasks[i][1], i);  // Task format: (start_time, processing_time, index)
        }

        // Sort tasks by start time (ascending order)
        sort(taskList.begin(), taskList.end());

        vector<int> res;  // Result vector to store the order of task indices
        auto it = taskList.begin();  // Iterator for traversing sorted tasks
        int tt = get<0>(*it);  // Initial time to the start time of the first task

        // Process the tasks
        while (it != taskList.end()) {
            // Push all tasks that are available (i.e., start time <= current time)
            while (it != taskList.end() && get<0>(*it) <= tt) {
                pq.push({get<1>(*it), get<2>(*it)});  // Add task with (processing_time, task_index) to the queue
                it++;  // Move to the next task in the list
            }

            // If the priority queue is empty, move to the next task's start time
            if (pq.empty()) {
                tt = get<0>(*it);  // Update the current time to the start time of the next task
                continue;  // Continue the loop to process the next task
            }

            // Pop the task with the shortest processing time from the queue
            auto task = pq.top();  // Get the task with the shortest processing time
            pq.pop();  // Remove it from the priority queue

            // Add the task index to the result vector
            res.push_back(task.second);

            // Increment the current time by the processing time of the task
            tt += task.first;
        }

        // After all tasks are processed, process any remaining tasks in the priority queue
        while (!pq.empty()) {
            res.push_back(pq.top().second);  // Add the remaining tasks' indices to the result
            pq.pop();  // Remove the task from the priority queue
        }

        return res;  // Return the result vector with the order of task indices
    }
};
