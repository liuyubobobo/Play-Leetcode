/// Source : https://leetcode.com/problems/design-an-atm-machine/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Simulation
/// Time Complexity: O(1) for every operation
/// Space Complexity: O(1)
class ATM {

private:
    const vector<long long> values = {20, 50, 100, 200, 500};
    const int dnum = 5;
    vector<long long> cnt;

public:
    ATM() : cnt(dnum, 0) {}

    void deposit(vector<int> banknotesCount) {

        assert(banknotesCount.size() == dnum);
        for(int i = 0; i < dnum; i ++)
            cnt[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {

        vector<int> res(dnum, 0);
        for(int i = dnum - 1; i >= 0 && amount; i --){
            long long t = min(amount / values[i], cnt[i]);
            cnt[i] -= t;
            res[i] += t;
            amount -= t * values[i];
        }

        if(amount == 0) return res;

        deposit(res);
        return {-1};
    }
};


int main() {

    return 0;
}
