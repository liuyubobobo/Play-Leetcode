/// Source : https://leetcode.com/problems/add-to-array-form-of-integer/
/// Author : liuyubobobo
/// Time   : 2019-02-13

#include <iostream>
#include <vector>

using namespace std;


/// Array and number addition
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

        vector<int> res;

        int carry = 0, i = A.size() - 1;
        while(i >= 0 || K){
            int t = K % 10 + carry;
            K /= 10;

            if(i >= 0) t += A[i];

            res.push_back(t % 10);
            carry = t / 10;

            i --;
        }
        if(carry) res.push_back(1);

        reverse(res.begin(), res.end());
        return res;
    }
};


void print_vec(const vector<int>& vec){

    for(int e: vec) cout << e;
    cout << endl;
}

int main() {

    vector<int> A1 = {0};
    int K1 = 0;
    print_vec(Solution().addToArrayForm(A1, K1));

    return 0;
}