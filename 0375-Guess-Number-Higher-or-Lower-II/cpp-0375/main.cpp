#include <iostream>

using namespace std;

class Solution {

public:
    int getMoneyAmount(int n) {

        int res = 0;
        for(int pick = 1 ; pick <= n ; pick ++)
            res = max(res, solve(n, pick));
        return res;
    }

private:
    int solve(int n, int pick){

    }
};

int main() {

    return 0;
}