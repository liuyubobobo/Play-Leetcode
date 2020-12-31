/// Source : https://leetcode.com/problems/pascals-triangle-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Binomial Coefficients
///
/// Time Complexity: O(rowIndex^2)
/// Space Complexity: O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for(int i = 1; i <= (rowIndex + 1) / 2; i ++)
            res[i] = res[rowIndex - i] = C(rowIndex, i);
        return res;
    }

private:
    int C(int m, int n){
        long long up = 1ll;
        int down1 = n, down2 = m - n;
        for(int i = m; i > 0; i --){
            up *= i;
            if(down1 && up % down1 == 0ll) up /= down1, down1 --;
            if(down2 && up % down2 == 0ll) up /= down2, down2 --;
        }
        return up;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    for(int i = 0 ; i < 10 ; i ++)
        print_vec(Solution().getRow(i));

    return 0;
}