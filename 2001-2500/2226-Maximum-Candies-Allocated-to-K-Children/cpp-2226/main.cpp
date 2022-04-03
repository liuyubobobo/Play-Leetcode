/// Source : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Compelxity: O(nlog(sum))
/// Space Complexity: O(1)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int n = candies.size();
        vector<long long> data(n);
        for(int i = 0; i < n; i ++) data[i] = candies[i];

        long long sum = accumulate(data.begin(), data.end(), 0ll);

        long long l = 0, r = sum / k;
        while(l < r){
            long long mid = (l + r + 1) / 2;
            if(ok(n, data, mid, k)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(int n, const vector<long long>& data, long long t, long long k){

        long long num = 0;
        for(long long e: data) num += e / t;
        return num >= k;
    }
};


int main() {

    return 0;
}
