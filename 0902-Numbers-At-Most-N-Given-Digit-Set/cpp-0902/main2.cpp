/// Source : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
/// Author : liuyubobobo
/// Time   : 2018-09-11

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Recursion
/// Second version of codes, more clear :-)
///
/// Time Complexity: (logN)
/// Space Complexity: O(logN)
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {

        string dset = "";
        for(string d: D)
            dset += d;

        int res = 0;
        int dnum = to_string(N).size();
        for(int i = 1; i < dnum; i ++)
            res += (int)pow(dset.size(), i);

        return res + atMostNGivenDigitSet(dset, to_string(N));
    }

private:
    int atMostNGivenDigitSet(const string& dset, const string& snum){

        int dnum = snum.size();
        if(snum.size() == 0)
            return 1;

        int res = 0;
        for(int i = 0; i < dset.size(); i ++)
            if(dset[i] < snum[0])
                res += (int)pow(dset.size(), snum.size() - 1);
            else if(dset[i] == snum[0])
                res += atMostNGivenDigitSet(dset, snum.substr(1));
            else
                break;

        return res;
    }
};


int main() {

    vector<string> D1 = {"1","3","5","7"};
    cout << Solution().atMostNGivenDigitSet(D1, 100) << endl;
    // 20

    vector<string> D2 = {"1", "4", "9"};
    cout << Solution().atMostNGivenDigitSet(D2, 1000000000) << endl;
    // 29523

    vector<string> D3 = {"3", "4", "8"};
    cout << Solution().atMostNGivenDigitSet(D3, 4) << endl;
    // 2

    vector<string> D4 = {"1", "2", "3", "6", "7", "8"};
    cout << Solution().atMostNGivenDigitSet(D4, 211) << endl;
    // 79

    vector<string> D5 = {"1", "5", "7", "8"};
    cout << Solution().atMostNGivenDigitSet(D5, 10212) << endl;
    // 340

    return 0;
}