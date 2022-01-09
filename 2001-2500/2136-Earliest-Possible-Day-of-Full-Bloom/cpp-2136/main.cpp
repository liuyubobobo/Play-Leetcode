/// Source : https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        int n = plantTime.size();

        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i ++)
            data[i].first = plantTime[i], data[i].second = growTime[i];

        sort(data.begin(), data.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2){
            if(p1.second != p2.second) return p1.second > p2.second;
            return p1.first + p1.second > p2.first + p2.second;
        });

        int res = 0, cur = 0;
        for(const pair<int, int>& p: data){
            res = max(res, cur + p.first + p.second);
            cur += p.first;
        }
        return res;
    }
};


int main() {

    vector<int> plantTime1 = {1, 4, 3}, growTime1 = {2, 3 , 1};
    cout << Solution().earliestFullBloom(plantTime1, growTime1) << endl;
    // 9

    vector<int> plantTime2 = {1, 2, 3, 2}, growTime2 = {2, 1, 2, 1};
    cout << Solution().earliestFullBloom(plantTime2, growTime2) << endl;
    // 9

    vector<int> plantTime3 = {1}, growTime3 = {1};
    cout << Solution().earliestFullBloom(plantTime3, growTime3) << endl;
    // 2

    return 0;
}
