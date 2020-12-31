/// Source : https://leetcode.com/problems/beautiful-array/
/// Author : liuyubobobo
/// Time   : 2018-10-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Divide and Conquer
/// The key observation is that {odd number, x, even number} satisfies the property forever!
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> beautifulArray(int N) {

        if(N == 0) return {};
        if(N == 1) return {1};
        if(N == 2) return {1, 2};

        vector<int> res;
        int odd = (N + 1) / 2, even = N - odd;

        vector<int> left = beautifulArray(odd);
        for(int e: left)
            res.push_back(2 * e - 1);

        vector<int> right = beautifulArray(even);
        for(int e: right)
            res.push_back(2 * e);


        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    print_vec(Solution().beautifulArray(5));

    return 0;
}