/// Source : https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/
/// Author : liuyubobobo
/// Time   : 2021-06-19
/// Updated: 2021-06-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {

        int h1, m1, h2, m2;
        get_time(startTime, h1, m1);
        get_time(finishTime, h2, m2);

        if(startTime > finishTime) h2 += 24;

        if(m1 > 0 && m1 < 15) m1 = 15;
        else if(m1 > 15 && m1 < 30) m1 = 30;
        else if(m1 > 30 && m1 < 45) m1 = 45;
        else if(m1 > 45){h1 += 1, m1 = 0;}

        if(m2 > 0 && m2 < 15) m2 = 0;
        else if(m2 > 15 && m2 < 30) m2 = 15;
        else if(m2 > 30 && m2 < 45) m2 = 30;
        else if(m2 > 45) m2 = 45;

        int res = 0;
        pair<int, int> p2 = {h2, m2};
        while(true){
            pair<int, int> p1 = {h1, m1};
            if(p1 > p2) break;

            res ++;

            m1 += 15;
            if(m1 == 60) h1 ++, m1 = 0;
        }
        return max(res - 1, 0);
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

    cout << Solution().numberOfRounds("23:95", "00:00") << endl;
    // 0

    return 0;
}
