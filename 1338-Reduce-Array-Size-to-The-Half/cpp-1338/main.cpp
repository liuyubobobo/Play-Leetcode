/// Source : https://leetcode.com/problems/reduce-array-size-to-the-half/
/// Author : liuyubobobo
/// Time   : 2019-02-01

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr) {

        map<int, int> freq;
        for(int e: arr) freq[e] ++;

        vector<int> f;
        for(const pair<int, int>& p: freq)
            f.push_back(-p.second);
        sort(f.begin(), f.end());

        int n = arr.size() / 2 + arr.size() % 2, k = 0, res = 0;
        for(int e: f){
            k += - e;
            res ++;
            if(k >= n) return res;
        }
        return res;
    }
};


int main() {

    return 0;
}
