/// Source : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
/// Author : liuyubobobo
/// Time   : 2020-05-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force: Split and Compare
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int index = 1;
        for(int start = 0, i = start + 1; i <= sentence.size(); i ++)
            if(i == sentence.size() || sentence[i] == ' '){
                string word = sentence.substr(start, i - start);
                if(searchWord.size() <= word.size() && word.substr(0, searchWord.size()) == searchWord)
                    return index;
                index ++;

                start = i + 1;
                i = start;
            }
        return -1;
    }
};


int main() {

    cout << Solution().isPrefixOfWord("i love eating burger", "burg") << endl;
    // 4

    cout << Solution().isPrefixOfWord("this problem is an easy problem", "pro") << endl;
    // 2

    cout << Solution().isPrefixOfWord("i am tired", "you") << endl;
    // -1

    cout << Solution().isPrefixOfWord("i use triple pillow", "pill") << endl;
    // 4

    cout << Solution().isPrefixOfWord("hello from the other side", "they") << endl;
    // -1

    return 0;
}
