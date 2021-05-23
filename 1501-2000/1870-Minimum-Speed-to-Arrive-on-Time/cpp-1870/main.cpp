/// Source : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
/// Author : liuyubobobo
/// Time   : 2021-05-22

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(n * log(MAX_INT))
/// Space Complexity: O(1)
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int l = 1, r = 1e7 + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(get_time(dist, mid) <= hour) r = mid;
            else l = mid + 1;
        }
        return l == 1e7 + 1 ? -1 : l;
    }

private:
    double get_time(const vector<int>& dist, int speed){

        double h = 0;
        for(int i = 0; i < dist.size(); i ++)
            if(i != dist.size() - 1) h += dist[i] / speed + !!(dist[i] % speed);
            else h += (double)dist[i] / speed;
        return h;
    }
};


int main() {

    vector<int> dist1 = {1, 3, 2};
    cout << Solution().minSpeedOnTime(dist1, 6) << endl;
    // 1

    vector<int> dist2 = {1, 3, 2};
    cout << Solution().minSpeedOnTime(dist2, 2.7) << endl;
    // 3

    vector<int> dist3 = {1, 3, 2};
    cout << Solution().minSpeedOnTime(dist3, 1.9) << endl;
    // -1

    vector<int> dist4 = {1, 1, 100000};
    cout << Solution().minSpeedOnTime(dist4, 2.01) << endl;
    // 10000000

    return 0;
}
