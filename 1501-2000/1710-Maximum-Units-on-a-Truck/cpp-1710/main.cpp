/// Source : https://leetcode.com/problems/maximum-units-on-a-truck/
/// Author : liuyubobobo
/// Time   : 2021-01-02

#include <iostream>
#include <vector>

using namespace std;


/// Greedy and Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });

        int res = 0;
        for(const vector<int>& box: boxTypes){

            int num = min(box[0], truckSize);
            res += num * box[1];
            truckSize -= num;

            if(truckSize == 0) break;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> data1 = {{1, 3}, {2, 2}, {3, 1}};
    cout << Solution().maximumUnits(data1, 4) << endl;
    // 8

    vector<vector<int>> data2 = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << Solution().maximumUnits(data2, 10) << endl;
    // 91

    return 0;
}
