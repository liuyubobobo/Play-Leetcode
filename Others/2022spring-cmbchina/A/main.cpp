/// Source : https://leetcode-cn.com/contest/cmbchina-2022spring/problems/fWcPGC/
/// Author : liuyubobobo
/// Time   : 2022-04-13

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string deleteText(string article, int index) {

        if(article[index] == ' ') return article;

        article = " " + article + " ";
        index ++;

        int start = -1, end = -1;
        for(start = index; article[start] != ' '; start --);
        for(end = index; article[end] != ' '; end ++);

        article = article.substr(0, start) + " " + article.substr(end + 1);
        while(!article.empty() && article[0] == ' ') article = article.substr(1);
        while(!article.empty() && article.back() == ' ') article.pop_back();
        return article;
    }
};


int main() {

    cout << Solution().deleteText("Singing dancing in the rain", 10) << '\n';

    return 0;
}
