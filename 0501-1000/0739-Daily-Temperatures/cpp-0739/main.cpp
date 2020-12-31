/// Source : https://leetcode.com/problems/daily-temperatures/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search the higher temperature
/// Time Complexity: O(n*t*logn) where n is the number of data and t is the max temperature
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<vector<int>> records;
        for(int i = 0 ; i <= 100 ; i ++){
            vector<int> empty_vec;
            records.push_back(empty_vec);
        }

        for(int i = 0 ; i < temperatures.size() ; i ++)
            records[temperatures[i]].push_back(i);

        vector<int> res;
        for(int i = 0 ; i < temperatures.size() ; i ++){
            int future = getWarmerDay(temperatures[i], i, records);
            if(future == -1)
                res.push_back(0);
            else
                res.push_back(future - i);
        }

        return res;
    }

private:
    int getWarmerDay(int t, int curDay, const vector<vector<int>>& records){

        int res = INT_MAX;
        for(int i = t + 1 ; i <= 100 ; i ++){
            vector<int>::const_iterator iter = upper_bound(records[i].begin(), records[i].end(), curDay);
            if(iter != records[i].end())
                res = min(res, *iter);
        }

        return res == INT_MAX ? -1 : res;
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