/// Source : https://leetcode.com/problems/random-flip-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Position redirection
/// Time Complexty: O(1)
/// Space Complexity: O(min(len(call of flip), m*n))
class Solution {

private:
    int m, n;
    int left;
    unordered_map<int, int> redirection;

public:
    Solution(int n_rows, int n_cols): m(n_rows), n(n_cols) {
        reset();
    }

    vector<int> flip() {

        int randNum = rand() % left;
        left --;

        int ret = randNum;
        if(redirection.find(randNum) != redirection.end())
            ret = redirection[randNum];

        if(redirection.find(left) == redirection.end())
            redirection[randNum] = left;
        else
            redirection[randNum] = redirection[left];

        return {ret / n, ret % n};
    }

    void reset() {
        left = m * n;
        redirection.clear();
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    Solution solution(2, 2);
    for(int i = 0; i < 4; i ++)
        print_vec(solution.flip());

    return 0;
}