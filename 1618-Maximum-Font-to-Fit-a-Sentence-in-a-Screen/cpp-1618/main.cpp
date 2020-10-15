/// Source : https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(|text| * log(|fonts|))
/// Space Complexity: O(1)

// This is the FontInfo's API interface.
// You should not implement it, or speculate about its implementation
class FontInfo {
  public:
    // Return the width of char ch when fontSize is used.
    int getWidth(int fontSize, char ch);

    // Return Height of any char when fontSize is used.
    int getHeight(int fontSize);
};

class Solution {
public:
    int maxFont(string text, long long w, int h, vector<int>& fonts, FontInfo fontInfo) {

        int l = -1, r = fonts.size() - 1;
        while(l < r){

            int mid = (l + r + 1) / 2;
            int H = fontInfo.getHeight(fonts[mid]);
            long long W = 0ll;
            for(char c: text) W += fontInfo.getWidth(fonts[mid], c);
            if(H <= h && W <= w) l = mid;
            else r = mid - 1;
        }
        return l == -1 ? -1 : fonts[l];
    }
};


int main() {

    return 0;
}
