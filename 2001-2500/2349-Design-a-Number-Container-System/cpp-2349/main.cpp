/// Source : https://leetcode.com/problems/design-a-number-container-system/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <map>
#include <set>

using namespace std;


/// Using Map
/// Time Complecity: O(logn) for every operation
/// Space Compelxity: O(n)
class NumberContainers {

private:
    map<int, int> data;
    map<int, set<int>> num2indice;

public:
    NumberContainers() {}

    void change(int index, int number) {

        auto iter = data.find(index);
        if(iter == data.end()){
            data[index] = number;
            num2indice[number].insert(index);
            return;
        }

        int old_number = iter->second;
        num2indice[old_number].erase(index);
        if(num2indice[old_number].empty()) num2indice.erase(old_number);

        data[index] = number;
        num2indice[number].insert(index);
    }

    int find(int number) {
        return num2indice[number].empty() ? -1 : *num2indice[number].begin();
    }
};


int main() {

    return 0;
}
