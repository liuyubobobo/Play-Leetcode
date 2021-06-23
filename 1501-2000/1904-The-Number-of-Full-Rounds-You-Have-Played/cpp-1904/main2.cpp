/// Source : https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/
/// Author : liuyubobobo
/// Time   : 2021-06-20
/// Updated: 2021-06-23

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {

        int h1, m1, h2, m2;
        get_time(startTime, h1, m1);
        get_time(finishTime, h2, m2);

        if(startTime > finishTime) h2 += 24;

        int a = h1 * 4 + m1 / 15 + !!(m1 % 15);
        int b = h2 * 4 + m2 / 15;
        return max(b - a, 0);
    }

private:
    void get_time(const string& s, int& h, int& m){

        h = atoi(s.substr(0, 2).c_str());
        m = atoi(s.substr(3).c_str());
    }
};


int main() {

    cout << Solution().numberOfRounds("12:01", "12:44") << endl;
    // 1

    cout << Solution().numberOfRounds("20:00", "06:00") << endl;
    // 40

    cout << Solution().numberOfRounds("00:00", "23:59") << endl;
    // 95

    cout << Solution().numberOfRounds("23:55", "00:00") << endl;
    // 0

    cout << Solution().numberOfRounds("00:47", "00:57") << endl;
    // 0

    return 0;
}
