/// Source : https://leetcode.com/problems/perfect-number/
/// Author : liuyubobobo
/// Time   : 2021-12-30

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Scan all the divisors
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(sqrt(n))
class Solution {
public:
    bool checkPerfectNumber(int num) {

        vector<int> d;
        for(int i = 1; i * i <= num; i ++){
            if(num % i == 0){
                if(i != num) d.push_back(i);
                if(i * i != num && i != 1) d.push_back(num / i);
            }
        }

        return accumulate(d.begin(), d.end(), 0) == num;
    }
};


int main() {

    return 0;
}
