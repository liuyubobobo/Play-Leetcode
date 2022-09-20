/// Source : https://leetcode.com/problems/count-days-spent-together/
/// Author : liuyubobobo
/// Time   : 2022-09-17

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {

private:
    const vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int a = get_day_index(arriveAlice);
        int b = get_day_index(leaveAlice);

        int c = get_day_index(arriveBob);
        int d = get_day_index(leaveBob);

        int x = max(a, c), y = min(b, d);
        return max(0, y - x + 1);
    }

private:
    int get_day_index(string date){

        int month = atoi(date.substr(0, 2).c_str());
        int day = atoi(date.substr(3).c_str());

        int res = 0;
        for(int i = 1; i < month ; i ++) res += months[i];
        res += day;
        return res;
    }
};


int main() {

    cout << Solution().countDaysTogether("08-15", "08-18", "08-16", "08-19") << '\n';
    // 3

    cout << Solution().countDaysTogether("10-01", "10-31", "11-01", "12-31") << '\n';
    // 0

    return 0;
}
