/// Source : https://leetcode.com/problems/sum-of-even-numbers-after-queries/
/// Author : liuyubobobo
/// Time   : 2019-02-02

#include <iostream>
#include <vector>

using namespace std;


/// Maintain sum
/// Time Complexity: O(n + q)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {

        int sum = 0;
        for(int a: A)
            if(abs(a) % 2 == 0)
                sum += a;

        vector<int> res;
        for(const vector<int>& q: queries){

            int x = A[q[1]];
            if(abs(x) % 2 == 0) sum -= x;
            A[q[1]] += q[0];
            if(abs(A[q[1]]) % 2 == 0)
                sum += A[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};


void print_res(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> A = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    print_res(Solution().sumEvenAfterQueries(A, queries));

    return 0;
}