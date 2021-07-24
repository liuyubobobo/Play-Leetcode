#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    bool areOccurrencesEqual(string s) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        set<int> set;
        for(int e: f) if(e) set.insert(e);
        return set.size() == 1;
    }
};

int main() {

    return 0;
}
