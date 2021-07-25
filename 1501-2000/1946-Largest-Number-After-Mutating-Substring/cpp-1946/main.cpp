/// Source : https://leetcode.com/problems/largest-number-after-mutating-substring/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {

        bool start = false;
        for(char& c: num)
            if(change[c - '0'] > c - '0'){
                start = true;
                c = (char)('0' + change[c - '0']);
            }
            else if(change[c - '0'] == c - '0') continue;
            else if(start) break;
        return num;
    }
};


int main() {

    vector<int> change1 = {9,8,5,0,3,6,4,2,6,8};
    cout << Solution().maximumNumber("132", change1) << endl;
    // 832

    vector<int> change2 = {9,4,3,5,7,2,1,9,0,6};
    cout << Solution().maximumNumber("021", change2) << endl;
    // 934

    vector<int> change3 = {1,4,7,5,3,2,5,6,9,4};
    cout << Solution().maximumNumber("5", change3) << endl;
    // 5

    vector<int> change4 = {0,9,2,3,3,2,5,5,5,5};
    cout << Solution().maximumNumber("334111", change4) << endl;
    // 334999

    return 0;
}
