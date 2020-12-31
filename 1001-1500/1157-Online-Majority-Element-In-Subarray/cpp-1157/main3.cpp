/// Source : https://leetcode.com/problems/online-majority-element-in-subarray/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/// Random Check
/// Time Complexity: init: O(n)
///                  query: O(1)
/// Space Complexity: O(n)
class MajorityChecker {

private:
    vector<int> arr;
    unordered_map<int, vector<int>> indexes;

public:
    MajorityChecker(vector<int>& arr): arr(arr.begin(), arr.end()) {

        for(int i = 0; i < arr.size(); i ++)
            indexes[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {

        for(int k = 0; k < 20; k ++){
            int e = arr[rand() % (right - left + 1) + left];
            vector<int>& v = indexes[e];
            vector<int>:: iterator iter1 = lower_bound(v.begin(), v.end(), left);
            vector<int>:: iterator iter2 = upper_bound(v.begin(), v.end(), right);
            if(iter2 - iter1 >= threshold) return e;
        }
        return -1;
    }
};


int main() {

    vector<int> arr = {1,1,2,2,1,1};
    MajorityChecker checker(arr);
    cout << checker.query(0, 5, 4) << endl; // 1
    cout << checker.query(0, 3, 3) << endl; // -1
    cout << checker.query(2, 3, 2) << endl; // 2

    return 0;
}