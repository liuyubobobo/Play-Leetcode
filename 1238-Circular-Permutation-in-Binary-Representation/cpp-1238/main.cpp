/// Source : https://leetcode.com/problems/circular-permutation-in-binary-representation/
/// Author : liuyubobobo
/// Time   : 2019-10-26

#include <iostream>
#include <vector>

using namespace std;


/// Get all gray code first and then find the start
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {

        vector<int> res = gray(n);

        vector<int> ret;
        for(int i = 0; i < res.size(); i ++)
            if(res[i] == start){
                int index = i, sz = 0;
                while(ret.size() < res.size())
                    ret.push_back(res[index ++ % res.size()]);
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