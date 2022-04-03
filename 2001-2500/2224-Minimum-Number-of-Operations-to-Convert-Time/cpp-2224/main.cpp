/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(t)
/// Space Complexity: O(1)
class Solution {
public:
    int convertTime(string current, string correct) {

        int a = get_time(current), b = get_time(correct);
        int d = b - a;

        int res = 0;
        while(d >= 60) d -= 60, res ++;
        while(d >= 15) d -= 15, res ++;
        while(d >= 5) d -= 5, res ++;
        res += d;
        return res;
    }

private:
    int get_time(const string& t){

        int h = atoi(t.substr(0, 2).c_str());
        int m = atoi(t.substr(3, 2).c_str());
        return h * 60 + m;
    }
};


int main() {

    return 0;
}
