/// Source : https://leetcode.com/problems/reorder-log-files/
/// Author : liuyubobobo
/// Time   : 2018-11-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Sort and custom compare lambda function
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) -> bool{
            int space1 = log1.find(' ');
            string id1 = log1.substr(0, space1), after1 = log1.substr(space1 + 1);

            int space2 = log2.find(' ');
            string id2 = log2.substr(0, space2), after2 = log2.substr(space2 + 1);

            if(isalpha(after1[0]) != isalpha(after2[0]))
                return isalpha(after1[0]);

            return isalpha(after1[0]) &&
                   (after1 == after2 ? id1 < id2 : after1 < after2);
        });
        return logs;
    }
};


int main() {

    return 0;
}