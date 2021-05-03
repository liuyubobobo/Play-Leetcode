/// Source : https://leetcode.com/problems/course-schedule-iii/
/// Author : liuyubobobo
/// Time   : 2021-05-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;
        int t = 0;
        for(vector<int>& course: courses)
            if(t + course[0] <= course[1]){
                t += course[0];
                pq.push(course[0]);
            }
            else if(!pq.empty() && t - pq.top() + course[0] <= course[1] && t - pq.top() + course[0] <= t){
                t -= pq.top();
                t += course[0];
                pq.pop();
                pq.push(course[0]);
            }
        return pq.size();
    }
};


int main() {

    vector<vector<int>> courses1 = {{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
    cout << Solution().scheduleCourse(courses1) << endl;
    // 5

    vector<vector<int>> courses2 = {{2,5},{2,19},{1,8},{1,3}};
    cout << Solution().scheduleCourse(courses2) << endl;
    // 4

    vector<vector<int>> courses3 = {{9,14},{7,12},{1,11},{4,7}};
    cout << Solution().scheduleCourse(courses3) << endl;
    // 3

    vector<vector<int>> courses4 = {{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
    cout << Solution().scheduleCourse(courses4) << endl;
    // 4

    return 0;
}
