/// Source : https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
/// Author : liuyubobobo
/// Time   : 2018-03-10

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// Heap
/// Time Complexity: O(len(A)^2*log(len(A)^2))
/// Space Complexity: O(len(A)^2)
class Solution {

private:
    class ComparePair{
    public:
        bool operator()(const pair<int, int>& p1,
                        const pair<int, int>& p2){
            return p1.first * p2.second < p2.first * p1.second;
        }
    };

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {

        sort(A.begin(), A.end());

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       ComparePair> pq;
        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = i + 1 ; j < A.size() ; j ++)
                if(pq.size() != K)
                    pq.push(make_pair(A[i], A[j]));
                else if(A[i] * pq.top().second < pq.top().first * A[j]){
                    pq.pop();
                    pq.push(make_pair(A[i], A[j]));
                }

        return {pq.top().first, pq.top().second};
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