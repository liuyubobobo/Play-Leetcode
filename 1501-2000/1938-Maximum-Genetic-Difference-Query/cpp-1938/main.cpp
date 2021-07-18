#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        int res = 0;
        for(int start = 0, i = 1; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                string word = text.substr(start, i - start);
                if(ok(word, brokenLetters)) res ++;

                start = i + 1;
                i = start;
            }
        return res;
    }

private:
    bool ok(const string& word, const string& broken){

        for(char c: word)
            if(broken.find(c) != string::npos)
                return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
