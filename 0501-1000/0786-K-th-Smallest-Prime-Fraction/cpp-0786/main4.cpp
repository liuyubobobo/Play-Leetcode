/// Source : https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
/// Author : liuyubobobo
/// Time   : 2018-03-10

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// Heap
/// Optimization from previous solution
///
/// Time Complexity: O(len(A)^2*log(len(A)^2))
/// Space Complexity: O(len(A)^2)
class Solution {

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {

        sort(A.begin(), A.end());

        auto cmp = [&A](const pair<int, int>& p1, const pair<int, int>& p2){
            return A[p1.first] * A[p2.second] > A[p2.first] * A[p1.second];
        };
        priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                decltype(cmp)> pq(cmp);
        for(int i = 1 ; i < A.size() ; i ++)
            pq.push(make_pair(0, i));

        for(int i = 0 ; i < K - 1 ; i ++){
            pair<int, int> cur_smallest = pq.top();
            pq.pop();
            cur_smallest.first ++;
            if(cur_smallest.first < cur_smallest.second)
                pq.push(cur_smallest);
        }

        return {A[pq.top().first], A[pq.top().second]};
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> A1 = {1, 2, 3, 5};
    print_vec(Solution().kthSmallestPrimeFraction(A1, 3));

    vector<int> A2 = {1, 7};
    print_vec(Solution().kthSmallestPrimeFraction(A2, 1));

    return 0;
}