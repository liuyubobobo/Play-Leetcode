/// Source : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
/// Author : liuyubobobo
/// Time   : 2018-09-11

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Mathematics
/// map digits of D into {0, 1, 2, ...}
/// if there're d digits in D, then it's a d-based number problem
///
/// Time Complexity: (logN)
/// Space Complexity: O(logN)
class Solution {

public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {

        string dset = "";
        for(string d: D)
            dset += d;

        unordered_map<char, int> dmap;
        for(int i = 0; i < dset.size(); i ++)
            dmap[dset[i]] = i + 1;

        string snum = to_string(N);
        for(int i = 0; i < snum.size(); i ++){
            int j;
            for(j = 0; j <= dset.size(); j ++)
                if(j == dset.size() || dset[j] > snum[i]){
                    int k;
                    snum[i] = dset[j - 1];
                    for(k = i; k >= 0 && snum[k] == '0'; k--);
                    if(k >= 0) snum[k] = dmap[snum[k]] - 1 >= 0 ? dset[dmap[snum[k]] - 1] : '0';
                    for(k = k + 1; k < snum.size(); k ++)
                        snum[k] = dset.back();
                    break;
                }
                else if(dset[j] == snum[i])
                    break;
        }

//        cout << "sum:" << snum << endl;
        int res = 0;
        for(char c: snum)
            res = res * dset.size() + dmap[c];
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

    vector<string> D6 = {"7"};
    cout << Solution().atMostNGivenDigitSet(D6, 8) << endl;
    // 1

    vector<string> D7 = {"1", "7"};
    cout << Solution().atMostNGivenDigitSet(D7, 231) << endl;
    // 10

    vector<string> D8 = {"1", "6", "7", "8", "9"};
    cout << Solution().atMostNGivenDigitSet(D8, 433) << endl;
    // 55

    vector<string> D9 = {"5"};
    cout << Solution().atMostNGivenDigitSet(D9, 6122) << endl;
    // 4

    return 0;
}