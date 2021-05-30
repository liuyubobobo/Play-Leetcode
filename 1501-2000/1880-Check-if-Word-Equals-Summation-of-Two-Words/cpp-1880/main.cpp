/// Source : https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
/// Author : liuyubobobo
/// Time   : 2021-05-29

#include <iostream>

using namespace std;


/// string to int
/// Time Complexity: (|a| + |b| + |c|)
/// Space Complexity: O(1)
class Solution {
public:
    bool isSumEqual(string& firstWord, string& secondWord, string& targetWord) {

        int a = parse(firstWord), b = parse(secondWord), c = parse(targetWord);
        return a + b == c;
    }

private:
    int parse(const string& s){
        int res = 0;
        for(char c: s)
            res = res * 10 + (c - 'a');
        return res;
    }
};

int main() {

    return 0;
}
