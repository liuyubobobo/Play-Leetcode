/// Source : https://leetcode.com/problems/bulb-switcher-iii/
/// Author : liuyubobobo
/// Time   : 2020-03-07

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {

        int res = 0, start = 0, minv = 1, maxv = 0;
        for(int i = 0; i < light.size(); i ++){
            maxv = max(light[i], maxv);
            if(i - start + 1 == maxv - minv + 1)
                res ++, minv = maxv + 1, maxv = 0, start = i + 1;
        }
        return res;
    }
};


int main() {

    vector<int> light1 = {2, 1, 3, 5, 4};
    cout << Solution().numTimesAllBlue(light1) << endl;
    // 3

    vector<int> light2 = {3, 2, 4, 1, 5};
    cout << Solution().numTimesAllBlue(light2) << endl;
    // 2

    vector<int> light3 = {1, 2, 3, 4, 5, 6};
    cout << Solution().numTimesAllBlue(light3) << endl;
    // 6

    vector<int> light4 = {2, 1, 4, 3, 6, 5};
    cout << Solution().numTimesAllBlue(light4) << endl;
    // 3

    vector<int> light5 = {4, 1, 2, 3};
    cout << Solution().numTimesAllBlue(light5) << endl;
    // 1

    vector<int> light6 = {1,2,3,4,5,6,18,8,30,10,11,12,13,14,17,16,15,7,19,20,41,22,23,24,33,26,27,25,29,9,31,32,28,34,35,36,37,38,39,40,21,42};
    cout << Solution().numTimesAllBlue(light6) << endl;
    // 8

    return 0;
}
