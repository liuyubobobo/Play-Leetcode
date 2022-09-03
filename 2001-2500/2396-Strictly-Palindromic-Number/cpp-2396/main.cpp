#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isStrictlyPalindromic(int n) {

        bool ok = true;
        for(int b = 2; b <= n - 2 && ok; b ++){
            vector<int> res = get_base_number(n, b);
            for(int i = 0, j = res.size() - 1; i < j && ok; i ++, j --)
                if(res[i] != res[j]) ok = false;
        }
        return ok;
    }

private:
    vector<int> get_base_number(int n, int b){
        vector<int> res;
        while(n){
            res.push_back(n % b);
            n /= b;
        }
        return res;
    }
};


int main() {

    return 0;
}
