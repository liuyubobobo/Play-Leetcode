/// Source : https://leetcode.com/problems/maximum-sum-circular-subarray/description/
/// Author : liuyubobobo
/// Time   : 2018-10-08

#include <iostream>
#include <vector>
#include <numeric>
#include <deque>

using namespace std;


/// Make an array of A + A
/// The purpose of this problem is to find the largest subarray in A + A,
/// but length less or equal to len(A)
/// Using stack strategy to keep a mono-space
/// Since we need to make the length less or equal to len(A)
/// deque is actually used (to remove element)
///
/// It'snot a quite efficient algorithm compare to main4 or main5
/// But the thinking and implementation is interesting and good to know
/// (Also hard to think)
/// Please complare this implementation to Leetcode 901 and Leetcode 910 :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {

        int n = A.size();

        vector<int> p(2 * n + 1, 0);
        for(int i = 0; i < n; i ++)
            p[i + 1] = p[n + i + 1] = A[i];
        for(int i = 1; i <= 2 * n; i ++)
            p[i] += p[i - 1];

//        for(int e: p)
//            cout << e << " ";
//        cout << endl;

        int res = INT_MIN;

        deque<int> q;
        q.push_back(0);
        for(int i = 1; i <= 2 * n; i ++){
            if(!q.empty() && i - q.front() > n)
                q.pop_front();

            res = max(res, p[i] - p[q.front()]);

            while(!q.empty() && p[i] <= p[q.back()])
                q.pop_back();

            q.push_back(i);
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {1,-2,3,-2};
    cout << Solution().maxSubarraySumCircular(A1) << endl;
    // 3

    vector<int> A2 = {5,-3,5};
    cout << Solution().maxSubarraySumCircular(A2) << endl;
    // 10

    vector<int> A3 = {3,-1,2,-1};
    cout << Solution().maxSubarraySumCircular(A3) << endl;
    // 4

    vector<int> A4 = {3,-2,2,-3};
    cout << Solution().maxSubarraySumCircular(A4) << endl;
    // 3

    vector<int> A5 = {-2,-3,-1};
    cout << Solution().maxSubarraySumCircular(A5) << endl;
    // -1

    vector<int> A6 = {-2,4,-5,4,-5,9,4};
    cout << Solution().maxSubarraySumCircular(A6) << endl;
    // 15

    vector<int> A7 = {-5,4,-6};
    cout << Solution().maxSubarraySumCircular(A7) << endl;
    // 4

    vector<int> A8 = {-5,-2,5,6,-2,-7,0,2,8};
    cout << Solution().maxSubarraySumCircular(A7) << endl;
    // 4

    return 0;
}