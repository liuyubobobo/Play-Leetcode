/// Source : https://leetcode.com/problems/closest-divisors/
/// Author : liuyubobobo
/// Time   : 2020-02-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(sqrt(num))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> closestDivisors(int num) {

        vector<int> v1= getDivisors(num + 1);
        vector<int> v2 = getDivisors(num + 2);

        return v1[1] - v1[0] < v2[1] - v2[0] ? v1 : v2;
    }

private:
    vector<int> getDivisors(int x){

        vector<int> res = {1, x};
        for(int i = 2; i * i <= x; i ++)
            if(x % i == 0)
                res = {i, x / i};
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().closestDivisors(8));
    // 3 3

    print_vec(Solution().closestDivisors(123));
    // 5 25

    print_vec(Solution().closestDivisors(999));
    // 40 25

    print_vec(Solution().closestDivisors(170967091));
    // 10754 15898

    return 0;
}
