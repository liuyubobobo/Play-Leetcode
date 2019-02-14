/// Source : https://leetcode.com/problems/add-to-array-form-of-integer/
/// Author : liuyubobobo
/// Time   : 2019-02-09

#include <iostream>
#include <vector>

using namespace std;


/// Two array's addition
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

        reverse(A.begin(), A.end());
//        Solution::print_vec(A);

        vector<int> B;
        while(K)
            B.push_back(K % 10), K /= 10;
        if(B.empty()) B.push_back(0);
//        Solution::print_vec(B);


        while(A.size() < B.size()) A.push_back(0);
        while(B.size() < A.size()) B.push_back(0);
//        Solution::print_vec(A);
//        Solution::print_vec(B);

        int carry = 0;
        for(int i = 0; i < A.size(); i ++){
            int t = A[i] + B[i] + carry;
            A[i] = t % 10;
            carry = t / 10;
        }
        if(carry) A.push_back(1);
//        Solution::print_vec(A);

        while(!A.empty() && A.back() == 0) A.pop_back();
        if(A.empty()) A.push_back(0);

        reverse(A.begin(), A.end());
//        Solution::print_vec(A);
        return A;
    }

    static void print_vec(const vector<int>& vec){

        for(int e: vec) cout << e;
        cout << endl;
    }
};


int main() {

    vector<int> A1 = {0};
    int K1 = 0;
    Solution::print_vec(Solution().addToArrayForm(A1, K1));

    return 0;
}