/// Source : https://leetcode-cn.com/problems/xiao-zhang-shua-ti-ji-hua/solution/xiao-zhang-shua-ti-ji-hua-er-fen-cha-zhao-by-leetc/
/// Author : liuyubobobo
/// Time   : 2020-04-25

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn(sum))
/// Space Complexity: O(1)
class Solution {
public:
    int minTime(vector<int>& time, int m) {

        if(time.size() <= m) return 0;

        int l = 0, r = accumulate(time.begin(), time.end(), 0);
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(time, m, mid)) r = mid;
            else l = mid + 1;
        }
        assert(l != 0);
        return l;
    }

private:
    int ok(const vector<int>& time, int m, int T){

        int sum = 0, maxt = 0, days = 0;
        for(int i = 0; i < time.size();){
            sum += time[i];
            maxt = max(maxt, time[i]);
            if(sum - maxt > T)
                sum = 0, maxt = 0, days ++;
            else i ++;
        }
        if(sum) days ++;
        return days <= m;
    }
};


int main() {

    vector<int> time1 = {1, 2, 3, 3};
    cout << Solution().minTime(time1, 2) << endl;
    // 3

    vector<int> time2 = {999, 999, 999};
    cout << Solution().minTime(time2, 4) << endl;
    // 0

    return 0;
}
