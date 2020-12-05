/// Source : https://leetcode.com/problems/task-scheduler/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


/// Greedy and Mathematics
/// Time Complexity: O(|task|)
/// Space Coomplexity: O(|task|)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int maxfreq = 0, maxcnt = 0;
        unordered_map<char, int> freq;
        for(char task: tasks){
            freq[task] ++;
            if(freq[task] > maxfreq) maxfreq = freq[task], maxcnt = 1;
            else if(freq[task] == maxfreq) maxcnt ++;
        }

        return max((int)tasks.size(), (maxfreq - 1) * (n + 1) + maxcnt);
    }
};


int main() {

    vector<char> v1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution().leastInterval(v1, 2) << endl;
    // 8

    vector<char> v2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution().leastInterval(v2, 0) << endl;
    // 6

    vector<char> v3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << Solution().leastInterval(v3, 2) << endl;
    // 16

    return 0;
}
