/// Source : https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        unordered_map<int, int> freq;
        for(int x: deck)
            freq[x] ++;

        for(int i = 2; i <= deck.size(); i ++){
            bool ok = true;
            for(const pair<int, int>& p: freq)
                if(p.second % i){
                    ok = false;
                    break;
                }
            if(ok)
                return true;
        }

        return false;
    }
};


int main() {

    vector<int> vec = {1,1,1,1,2,2,2,2,2,2};
    cout << Solution().hasGroupsSizeX(vec) << endl;
    // true

    return 0;
}