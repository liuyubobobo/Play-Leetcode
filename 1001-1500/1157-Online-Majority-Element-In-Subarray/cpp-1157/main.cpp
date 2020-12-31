/// Source : https://leetcode.com/problems/online-majority-element-in-subarray/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/// Boyer-Moore Voting Algorithm to Vote
/// and Binary Search to check
///
/// for details of BM Voting, see here Approach 6:
/// https://leetcode.com/problems/majority-element/solution/
///
/// Time Complexity: init: O(n)
///                  query: O(n)
/// Space Complexity: O(n)
class MajorityChecker {

private:
    unordered_map<int, vector<int>> indexes;
    vector<int> arr;

public:
    MajorityChecker(vector<int>& arr): arr(arr.begin(), arr.end()){

        for(int i = 0; i < arr.size(); i ++)
            indexes[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {

        int e = vote(left, right);

        const vector<int>& v = indexes[e];
        vector<int>:: const_iterator iter1 = lower_bound(v.begin(), v.end(), left);
        vector<int>:: const_iterator iter2 = upper_bound(v.begin(), v.end(), right);
        if(iter2 - iter1 >= threshold) return e;
        return -1;
    }

private:
    int vote(int left, int right){

        int count = 1, res = arr[left];
        for(int i = left + 1; i <= right; i ++){
            if(count == 0) res = arr[i];
            count += (res == arr[i] ? 1 : -1);
        }
        return res;
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