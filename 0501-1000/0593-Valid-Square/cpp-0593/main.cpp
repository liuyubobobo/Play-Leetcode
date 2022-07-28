/// Source : https://leetcode.com/problems/valid-square/
/// Author : liuyubobobo
/// Time   : 2022-07-28

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force + Math
/// Time Complexity: O(4!)
/// Space Complexity: O(1)
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<vector<int>> p ={p1, p2, p3, p4};
        for(int i = 0; i < 4; i ++)
            for(int j = i + 1; j < 4; j ++)
                if(p[i] == p[j]) return false;

        sort(p.begin(), p.end());
        do{
            if(valid_square(p)) return true;
        }while(next_permutation(p.begin(), p.end()));
        return false;
    }

private:
    bool valid_square(const vector<vector<int>>& p){

        int L2 = get_L2(p[0], p[1]);
        for(int i = 1; i < 4; i ++)
            if(get_L2(p[i], p[(i + 1) % 4]) != L2) return false;

        for(int i = 0; i < 4; i ++)
            if(dot_product(p[i], p[(i + 1) % 4], p[(i + 2) % 4])) return false;

        return true;
    }

    int dot_product(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){

        int a1 = p2[0] - p1[0], b1 = p2[1] - p1[1];
        int a2 = p3[0] - p2[0], b2 = p3[1] - p2[1];
        return a1 * b1 + a2 * b2;
    }

    int get_L2(const vector<int>& p1, const vector<int>& p2){
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};


int main() {

    return 0;
}
