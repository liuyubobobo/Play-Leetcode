/// Source : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
class Solution {
public:
    int minPartitions(string n) {

        return *max_element(n.begin(), n.end()) - '0';
    }
};


int main() {

    return 0;
}
