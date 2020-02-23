#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> closestDivisors(int num) {

        vector<int> v1= getDivisors(num + 1);
//        Solution().print_vec(v1);
        vector<int> v2 = getDivisors(num + 2);
//        Solution().print_vec(v2);

        return v1[1] - v1[0] < v2[1] - v2[0] ? v1 : v2;
    }

private:
    vector<int> getDivisors(int x){

        vector<int> res = {1, x};
        for(int i = 2; i * i <= x; i ++)
            if(x % i == 0)
                res = {i, x / i};
        return res;
    }

public:
    static void print_vec(const vector<int>& vec){
        for(int e: vec) cout << e << " "; cout << endl;
    }
};




int main() {

    Solution().print_vec(Solution().closestDivisors(8));
    // 3 3

    Solution().print_vec(Solution().closestDivisors(123));
    // 5 25

    Solution().print_vec(Solution().closestDivisors(999));
    // 40 25

    Solution().print_vec(Solution().closestDivisors(170967091));
    // 10754 15898

    return 0;
}
