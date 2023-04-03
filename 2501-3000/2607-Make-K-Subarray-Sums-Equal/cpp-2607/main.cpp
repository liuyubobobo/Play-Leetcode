/// Source : https://leetcode.com/problems/make-k-subarray-sums-equal/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {

        int n = arr.size();

        vector<bool> visited(n, false);
        long long res = 0;
        for(int i = 0; i < n; i ++){
            if(visited[i]) continue;

            vector<int> v;
            for(int j = i; !visited[j]; j = (j + k) % n)
                v.push_back(arr[j]), visited[j] = true;

            sort(v.begin(), v.end());
            int t = v[v.size() / 2];
            for(int j = 0; j < v.size(); j ++)
                res += abs(v[j] - t);
        }
        return res;
    }
};


int main() {

    return 0;
}
