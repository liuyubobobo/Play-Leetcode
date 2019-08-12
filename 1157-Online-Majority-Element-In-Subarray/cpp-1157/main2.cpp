/// Source : https://leetcode.com/problems/online-majority-element-in-subarray/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/// Using Boyer-Moore Voting Algorithm when interval is short
/// Check popular elements when interval is longer
/// the bound can be set to be sqrt(n)
///
/// Time Complexity: init: O(n)
///                  query: O(sqrt(n)*logn)
/// Space Complexity: O(n)
class MajorityChecker {

private:
    unordered_map<int, vector<int>> indexes;
    vector<int> arr, popular_nums;
    const int LIMIT;

public:
    MajorityChecker(vector<int>& arr): arr(arr.begin(), arr.end()), LIMIT(sqrt(arr.size())){

        for(int i = 0; i < arr.size(); i ++)
            indexes[arr[i]].push_back(i);

        for(const pair<int, vector<int>>& p: indexes)
            if(p.second.size() > LIMIT)
                popular_nums.push_back(p.first);
    }

    int query(int left, int right, int threshold) {

        if(threshold <= LIMIT){
            int e = vote(left, right);
            return get_freq(e, left, right) >= threshold ? e : -1;
        }

        for(int e: popular_nums)
            if(get_freq(e, left, right) >= threshold)
                return e;
        return -1;
    }

private:
    int get_freq(int e, int left, int right){
        const vector<int>& v = indexes[e];
        vector<int>:: const_iterator iter1 = lower_bound(v.begin(), v.end(), left);
        vector<int>:: const_iterator iter2 = upper_bound(v.begin(), v.end(), right);
        return iter2 - iter1;
    }

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