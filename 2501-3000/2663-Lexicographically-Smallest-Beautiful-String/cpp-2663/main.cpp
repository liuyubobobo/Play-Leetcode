/// Source : https://leetcode.com/problems/lexicographically-smallest-beautiful-string/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string smallestBeautifulString(string s, int k) {

        int n = s.size(), pos = n - 1;
        while(add1(n, s, k, pos)){
            int pre = pos;
            pos = check(pos, s);
            if(pos == -1){
                for(int i = pre + 1; i < n; i ++){
                    for(char c = 'a'; c < 'a' + k; c ++){
                        if(i - 1 >= 0 && s[i - 1] == c) continue;
                        if(i - 2 >= 0 && s[i - 2] == c) continue;
                        s[i] = c;
                        break;
                    }
                }
                return s;
            }
        }
        return "";
    }

private:
    int check(int pos, const string& s){

        for(int i = pos; i > 0; i --){
            if(s[i] == s[i - 1]) return i;
            if(i - 2 >= 0 && s[i] == s[i - 2]) return i;
        }
        return -1;
    }

    bool add1(int n, string& s, int k, int pos){
        s[pos] += 1;
        for(int i = pos; i > 0; i --)
            if(s[i] == 'a' + k){
                s[i - 1] += 1;
                s[i] = 'a';
            }
            else break;
        if(s[0] == 'a' + k) return false;

        return true;
    }
};

int main() {

//    cout << Solution().smallestBeautifulString("abcz", 26) << endl;
//    // abda

    cout << Solution().smallestBeautifulString("ponponp", 16) << endl;

    return 0;
}
