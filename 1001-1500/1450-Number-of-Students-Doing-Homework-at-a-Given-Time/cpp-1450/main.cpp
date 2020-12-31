/// Source : Number of Students Doing Homework at a Given Time
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {

        int res = 0;
        for(int i = 0; i < startTime.size(); i ++)
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) res ++;
        return res;
    }
};


int main() {

    return 0;
}
