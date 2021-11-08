/// Source : https://leetcode.com/problems/bulls-and-cows/
/// Author : liuyubobobo
/// Time   : 2021-11-07

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {

        int n = secret.size();

        vector<int> a(10, 0), b(10, 0);
        int bull = 0;
        for(int i = 0; i < n; i ++)
            if(secret[i] == guess[i]) bull ++;
            else a[secret[i] - '0'] ++, b[guess[i] - '0'] ++;

        int cow = 0;
        for(int i = 0; i < 10; i ++)
            cow += min(a[i], b[i]);

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};


int main() {

    return 0;
}
