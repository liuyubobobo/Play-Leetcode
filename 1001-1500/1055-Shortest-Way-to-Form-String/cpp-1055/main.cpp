/// Source : https://leetcode.com/problems/shortest-way-to-form-string/description/
/// Author : liuyubobobo
/// Time   : 2023-03-09

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|s| * |t|)
/// Space Complexity: O(1)
class Solution {
public:
    int shortestWay(string source, string target) {

        int res = 0, start = 0;
        while(start < target.size()) {
            if(ok(source, target, start)) res++;
            else return -1;
        }
        return res;
    }

private:
    bool ok(const string& source, const string& target, int& start) {

        int j = start;
        for(int i = 0; i < source.size() && j < target.size(); i ++)
            if(source[i] == target[j]) j ++;

        if(j == start) return false;
        start = j;
        return true;
    }
};


int main() {

    return 0;
}
