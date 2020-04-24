/// Source : https://leetcode.com/problems/minimize-max-distance-to-gas-station/
/// Author : liuyubobobo
/// Time   : 2020-04-24

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


/// Binary Search
/// Time Complexity: O(n * log(1e14))
/// Space Complexity: O(n)
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {

        vector<double> seg;
        for(int i = 1; i < stations.size(); i ++)
            seg.push_back(stations[i] - stations[i - 1]);

        double l = 0.0, r = 1e8;
        while(r - l >= 1e-6){
            double mid = (l + r) / 2;
            if(ok(seg, K, mid)) r = mid;
            else l = mid;
        }
        return l;
    }

private:
    bool ok(const vector<double>& seg, int K, double gap){

        int x = 0;
        for(double e: seg)
            x += (ceil(e / gap) - 1);
        return x <= K;
    }
};


int main() {

    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << Solution().minmaxGasDist(stations, 9) << endl;

    return 0;
}
