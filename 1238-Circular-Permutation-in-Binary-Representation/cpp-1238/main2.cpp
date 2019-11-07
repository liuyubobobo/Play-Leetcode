/// Source : https://leetcode.com/problems/circular-permutation-in-binary-representation/
/// Author : liuyubobobo
/// Time   : 2019-10-26

#include <iostream>
#include <vector>

using namespace std;


/// Get all gray code first and then find the start
/// Just using reverse to get the result in place
/// Time Complexity: O(2^n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {

        vector<int> ret = gray(n);

        for(int i = 0; i < ret.size(); i ++)
            if(ret[i] == start){
                reverse(ret.begin(), ret.begin() + (i + 1));
                reverse(ret.begin() + (i + 1), ret.end());
                break;
            }
        return ret;
    }

private:
    vector<int> gray(int n){

        if(n == 1) return {0, 1};

        vector<int> res = gray(n - 1);
        for(int i = res.size() - 1; i >= 0; i --)
            res.push_back(res[i] + (1 << (n - 1)));
        return res;
    }
};


void print_vec(const vector<int>& res){

    for(int e: res) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().circularPermutation(2,3));
    // 3 2 0 1

    print_vec(Solution().circularPermutation(3,2));

    return 0;
}