/// Source : https://leetcode.com/problems/random-flip-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;


/// Using Buckets to find the kth unflipped position
/// Using binary search:)
/// \
/// Time Complexty: O(sqrt(m*n))
/// Space Complexity: O(min(len(call of flip), m*n))
class Solution {

private:
    int m, n;
    int bucket_sz;
    vector<unordered_set<int>> buckets;
    vector<int> start;

public:
    Solution(int n_rows, int n_cols): m(n_rows), n(n_cols) {

        bucket_sz = sqrt(m * n);
        reset();
    }

    vector<int> flip() {

//        Solution::print_vec(start);

        int randNum = rand() % start.back();
        int index = upper_bound(start.begin(), start.end(), randNum) - start.begin();
        index --;
//        cout << "find " << randNum << " in " << index << " bucket." << endl;

        int k = randNum - start[index];
        int ret = -1;
        for(int i = index * bucket_sz; ; i ++)
            if(buckets[index].find(i) == buckets[index].end()){
                if(!k){
                    ret = i;
                    buckets[index].insert(i);
                    break;
                }
                k --;
            }

        for(int i = index + 1; i < start.size(); i ++)
            start[i] --;
        return {ret / n, ret % n};
    }

    void reset() {

        buckets.clear();
        start.clear();

        start.push_back(0);
        for(int i = 0; i < m * n; i += bucket_sz){
            buckets.push_back(unordered_set<int>());
            start.push_back(min(start.back() + bucket_sz, m * n));
        }
    }

    static void print_vec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};


int main() {

    Solution solution(2, 2);
    for(int i = 0; i < 4; i ++)
        Solution::print_vec(solution.flip());

    return 0;
}