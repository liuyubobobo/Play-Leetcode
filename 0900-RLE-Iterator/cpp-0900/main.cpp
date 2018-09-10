/// Source : https://leetcode.com/problems/rle-iterator/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: init: O(n)
///                  next: O(n)
/// Space Complexity: O(n)
class RLEIterator {

private:
    vector<int> A;
    int curnum_index = 1, index = 0;

public:
    RLEIterator(vector<int> A) {
        for(int a: A)
            this->A.push_back(a);
    }

    int next(int n) {

        if(curnum_index >= A.size())
            return -1;

        index += n;
        while(curnum_index < A.size() && index > A[curnum_index - 1]){
            index -= A[curnum_index - 1];
            curnum_index += 2;
        }

        if(curnum_index < A.size() && index <= A[curnum_index - 1])
            return A[curnum_index];
        return -1;
    }
};


int main() {

    vector<int> A = {3, 8, 0, 9, 2, 5};
    RLEIterator rleIterator(A);
    cout << rleIterator.next(2) << endl; // 8
    cout << rleIterator.next(1) << endl; // 8
    cout << rleIterator.next(1) << endl; // 5
    cout << rleIterator.next(2) << endl; // -1

    return 0;
}