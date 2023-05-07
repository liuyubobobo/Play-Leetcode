/// Source : https://leetcode.com/problems/frequency-tracker/
/// Author : liuyubobobo
/// Time   : 2023-05-06

#include <iostream>
#include <map>
#include <set>

using namespace std;


/// Using Map and Set
/// Time Complexity: O(logn) for each operation
/// Space Complexity: O(n)
class FrequencyTracker {

private:
    map<int, int> numberToFrequency;
    multiset<int> f;

public:
    FrequencyTracker() {

    }

    void add(int number) {
        numberToFrequency[number] ++;
        int new_f = numberToFrequency[number];
        int old_f = new_f - 1;
        if(old_f) f.erase(f.find(old_f));
        f.insert(new_f);
    }

    void deleteOne(int number) {
        if(numberToFrequency.find(number) == numberToFrequency.end()) return;

        numberToFrequency[number] --;
        int new_f = numberToFrequency[number];
        int old_f = new_f + 1;
        f.erase(f.find(old_f));
        if(new_f) f.insert(new_f);

        if(new_f == 0) numberToFrequency.erase(number);
    }

    bool hasFrequency(int frequency) {
        return f.find(frequency) != f.end();
    }
};


int main() {

//    ["FrequencyTracker","deleteOne","hasFrequency","hasFrequency","deleteOne","hasFrequency","hasFrequency","add","deleteOne","deleteOne"]
//    [[],[5],[1],[1],[3],[1],[1],[7],[7],[7]]

    FrequencyTracker ft;
    ft.deleteOne(5);
    cout << ft.hasFrequency(1) << endl;
    cout << ft.hasFrequency(1) << endl;
    ft.deleteOne(3);
    cout << ft.hasFrequency(1) << endl;
    cout << ft.hasFrequency(1) << endl;
    ft.add(7);
    ft.deleteOne(7);
    ft.deleteOne(7);

    return 0;
}
