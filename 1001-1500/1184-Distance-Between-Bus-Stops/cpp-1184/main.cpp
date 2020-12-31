/// Source : https://leetcode.com/problems/distance-between-bus-stops/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {

        int sum = accumulate(distance.begin(), distance.end(), 0);

        if(start > destination) swap(start, destination);
        int x = 0;
        for(int i = start; i < destination; i ++)
            x += distance[i];
        return min(x, sum - x);
    }
};


int main() {

    vector<int> dis = {1, 2, 3, 4};
    cout << Solution().distanceBetweenBusStops(dis, 0, 1) << endl;
    // 1

    cout << Solution().distanceBetweenBusStops(dis, 0, 2) << endl;
    // 3

    cout << Solution().distanceBetweenBusStops(dis, 0, 3) << endl;
    // 4

    return 0;
}