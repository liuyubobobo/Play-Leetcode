/// Source : https://leetcode.com/problems/sort-characters-by-frequency/
/// Author : liuyubobobo
/// Time   : 2017-01-17

#include <iostream>

using namespace std;

/// Using Counting Sort
/// Time Complexity: O(n)
/// Space Complexity: O(256)
class Solution {
public:
    string frequencySort(string s) {

        pair<int, char> freq[256];
        for(int i = 0 ; i < 256 ; i ++){
            freq[i].first = 0;
            freq[i].second = i;
        }

        for(int i = 0 ; i < s.size() ; i ++)
            freq[s[i]].first ++;

        sort(freq, freq + 256, greater<pair<int, char>>());

        int index = 0;
        for(int i = 0 ; i < s.size() ; i ++){
            while(!freq[index].first)
                index ++;
            s[i] = freq[index].second;
            freq[index].first --;
        }

        return s;
    }
};


int main() {

    cout << Solution().frequencySort("tree") << endl;
    cout << Solution().frequencySort("cccaaa") << endl;
    cout << Solution().frequencySort("Aabb") << endl;

    return 0;
}