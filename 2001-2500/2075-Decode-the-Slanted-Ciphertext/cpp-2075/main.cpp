/// Source : https://leetcode.com/problems/decode-the-slanted-ciphertext/
/// Author : liuyubobobo
/// Time   : 2021-11-13

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|s|)
/// Space Complextiy: O(|s|)
class Solution {
public:
    string decodeCiphertext(string encodedText, int R) {

        int n = encodedText.size();
        assert(n % R == 0);
        int C = n / R;

        vector<string> M(R, string(C, ' '));
        for(int i = 0; i < n; i ++)
            M[i / C][i % C] = encodedText[i];

        string res = "";
        for(int c = 0; c < C; c ++)
            for(int r = 0; r < R && c + r < C; r ++)
                res += M[r][c + r];
        while(res.back() == ' ') res.pop_back();
        return res;
    }
};


int main() {

    cout << Solution().decodeCiphertext("ch   ie   pr", 3) << endl;
    // cipher

    cout << Solution().decodeCiphertext("iveo    eed   l te   olc", 4) << endl;
    // i love leetcode

    cout << Solution().decodeCiphertext("coding", 1) << endl;
    // coding

    cout << Solution().decodeCiphertext(" b  ac", 2) << endl;
    // _abc

    return 0;
}
