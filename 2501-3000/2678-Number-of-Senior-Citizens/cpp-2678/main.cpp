/// Source : https://leetcode.com/problems/number-of-senior-citizens/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countSeniors(vector<string>& details) {

        int res = 0;
        for(const string& s: details){
            int age = stoi(s.substr(11, 2));
            res += age > 60;
        }
        return res;
    }
};


int main() {

    return 0;
}
