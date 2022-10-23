/// Source : https://leetcode.com/problems/determine-if-two-events-have-conflict/
/// Author : liuyubobobo
/// Time   : 2022-10-22

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        int s1 = get_time(event1[0]), e1 = get_time(event1[1]);
        int s2 = get_time(event2[0]), e2 = get_time(event2[1]);
        if(s1 > s2) swap(s1, s2), swap(e1, e2);

        return s2 <= e1;
    }

private:
    int get_time(const string& s){
        int h = atoi(s.substr(0, 2).c_str());
        int m = atoi(s.substr(3).c_str());
        return h * 60 + m;
    }
};


int main() {

    return 0;
}
