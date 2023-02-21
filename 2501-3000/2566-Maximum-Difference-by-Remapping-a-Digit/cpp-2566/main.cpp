/// Source : https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/
/// Author : liuyubobobo
/// Time   : 2023-02-19

#include <iostream>
#include <climits>

using namespace std;


/// Brute Force
/// Time Complexity: O(10 * 10 * log(num))
/// Space Complexity: O(log(num))
class Solution {
public:
    int minMaxDifference(int num) {

        int maxv = INT_MIN, minv = INT_MAX;
        for(int from = 0; from <= 9; from ++)
            for(int to = 0; to <= 9; to ++){
                int new_num = replace(num, from, to);
                maxv = max(maxv, new_num);
                minv = min(minv, new_num);
            }
        return maxv - minv;
    }

private:
    int replace(int num, int from, int to) {

        string num_str = to_string(num);
        for(char& c: num_str)
            if(c == (char)(from + '0'))
                c = (char)(to + '0');
        return atoi(num_str.c_str());
    }
};


int main() {

    return 0;
}
