/// Source : https://leetcode.com/problems/maximize-the-minimum-powered-city/description/
/// Author : liuyubobobo
/// Time   : 2023-01-07

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search + Diff Array
/// Time Complexity: O(n * log(max))
/// Space Complexity: O(n)
class Solution {
public:
    long long maxPower(vector<int>& stations, int radius, int k) {

        long long l = 0, r = 1e11;
        while(l < r){
            long long mid = (l + r + 1) / 2;
            if(ok(stations.size(), stations, radius, k, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

private:
    bool ok(int n, const vector<int>& stations, int radius, int k, long long min_power){

        vector<long long> diff_arr(n + 1, 0);
        for(int i = 0; i < n; i ++){
            int l = max(0, i - radius), r = min(n - 1, i + radius);
            diff_arr[l] += stations[i], diff_arr[r + 1] -= stations[i];
        }

        long long cur = 0,  need = 0;
        for(int i = 0; i < n; i ++){
            cur += diff_arr[i];
            if(cur < min_power){
                long long d = min_power - cur, l = i, r = min(i + radius + radius, n - 1);
                diff_arr[l] += d, diff_arr[r + 1] -= d;
                cur = min_power;
                need += d;
            }
        }
        return need <= k;
    }
};


int main() {

    return 0;
}
