/// Source : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(max_days))
/// Space Complexity: O(1)
class Solution {

public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(m * k > bloomDay.size()) return -1;

        int maxday = *max_element(bloomDay.begin(), bloomDay.end());
        if(m * k == bloomDay.size())
            return maxday;

        int l = 1, r = maxday;
        while(l < r){
            int mid = (l + r) / 2;
            if(flowers(bloomDay, k, mid) >= m) r = mid;
            else l = mid + 1;
        }
        return l >= m ? l : -1;
    }

private:
    int flowers(const vector<int>& days, int k, int d){

        int res = 0;
        int i = 0;
        while(i < days.size()){
            int j;
            for(j = i; j < i + k && j < days.size(); j ++)
                if(days[j] > d) break;

            if(j == i + k) res ++, i += k;
            else i = j + 1;
        }
        return res;
    }
};


int main() {

    vector<int> days0 = {1,10,2};
    cout << Solution().minDays(days0, 2, 1) << endl;
    // 2

    vector<int> days1 = {1,10,3,10,2};
    cout << Solution().minDays(days1, 3, 1) << endl;
    // 3

    vector<int> days2 = {1,10,3,10,2};
    cout << Solution().minDays(days1, 3, 2) << endl;
    // -1

    vector<int> days3 = {7,7,7,7,12,7,7};
    cout << Solution().minDays(days3, 2, 3) << endl;
    // 12

    vector<int> days4 = {1000000000,1000000000};
    cout << Solution().minDays(days4, 1, 1) << endl;
    // 1000000000

    vector<int> days5 = {1,10,2,9,3,8,4,7,5,6};
    cout << Solution().minDays(days5, 4, 2) << endl;
    // 9

    return 0;
}
