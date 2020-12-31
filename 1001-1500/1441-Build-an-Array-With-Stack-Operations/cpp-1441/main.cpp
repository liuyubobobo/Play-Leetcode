/// Source : https://leetcode.com/problems/build-an-array-with-stack-operations/
/// Author : liuyubobobo
/// Time   : 2020-05-10

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> res;
        int next = 1;
        for(int t: target){
            while(t != next) res.push_back("Push"), res.push_back("Pop"), next ++;
            res.push_back("Push"), next ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
