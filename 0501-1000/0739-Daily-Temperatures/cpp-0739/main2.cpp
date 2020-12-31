/// Source : https://leetcode.com/problems/daily-temperatures/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>

using namespace std;


/// Reverse Process
/// Time Complexity: O(n*t) where n is the number of data and t is the max temperature
/// Space Complexity: O(t)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> next(101, -1);
        vector<int> res(temperatures.size(), -1);
        for(int i = temperatures.size() - 1; i >= 0 ; i --){
            int ret = INT_MAX;
            for(int j = temperatures[i] + 1; j <= 100; j ++)
                if(next[j] != -1 && next[j] < ret)
                    ret = next[j];
            res[i] = ret == INT_MAX ? 0 : ret - i;
            next[temperatures[i]] = i;
        }

        return res;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> vec = {73, 74, 75, 71, 69, 72, 76, 73};
    printVec(Solution().dailyTemperatures(vec));
    // 1 1 4 2 1 1 0 0

    return 0;
}