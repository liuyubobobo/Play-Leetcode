/// Source : https://leetcode.com/problems/iterator-for-combination/
/// Author : liuyubobobo
/// Time   : 2021-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Time Complexity: init: O(2^n * n)
///                  next, has_next: O(1)
/// Space Complexity: O(2^n)
class CombinationIterator {

private:
    vector<string> table;
    int cur = 0;

public:
    CombinationIterator(string characters, int combinationLength){

        int n = characters.size();
        for(int state = 1; state < (1 << n); state ++)
            if(__builtin_popcount(state) == combinationLength){
                string s = "";
                for(int i = 0; i < n; i ++)
                    if(state & (1 << i)) s += characters[i];
                table.push_back(s);
            }
        sort(table.begin(), table.end());
    }

    string next() {

        return table[cur ++];
    }

    bool hasNext() {
        return cur < table.size();
    }
};


int main() {

    return 0;
}
