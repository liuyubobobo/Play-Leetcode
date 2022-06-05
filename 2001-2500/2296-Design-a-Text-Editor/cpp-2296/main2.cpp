/// Source : https://leetcode.com/problems/design-a-text-editor/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <list>

using namespace std;


/// Using C++ list
/// Time Complexity: init: O(1)
///                  add: O(|text|)
///                  delete: O(k)
///                  move: O(k)
/// Space Complexity: O(all_characters)
class TextEditor {

private:
    list<char> L;
    list<char>::iterator iter = L.begin();

public:
    TextEditor() {}

    void addText(string text) {
        for(char c: text)
            L.insert(iter, c);
    }

    int deleteText(int k) {

        int del_len = 0;
        while(k -- && iter != L.begin()){
            iter --;
            iter = L.erase(iter);
            del_len ++;
        }
        return del_len;
    }

    string cursorLeft(int k) {

        while(k -- && iter != L.begin()) iter --;

        auto p = iter;
        string ret = "";
        for(int i = 0; i < 10 && p != L.begin(); i ++){
            p --;
            ret += *p;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string cursorRight(int k) {

        while(k -- && iter != L.end()) iter ++;

        auto p = iter;
        string ret = "";
        for(int i = 0; i < 10 && p != L.begin(); i ++){
            p --;
            ret += *p;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main() {

    return 0;
}
