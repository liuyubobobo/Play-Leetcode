/// Source : https://leetcode.com/problems/insert-delete-getrandom-o1/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Vector to stroe all elements
/// HashMap to restore all maps between elements and index
/// Time Complexity: O(1)
/// Space Complexity: O(n)
class RandomizedSet {

private:
    vector<int> nums;
    unordered_map<int, int> index;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.clear();
        index.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val) == index.end()){
            nums.push_back(val);
            index[val] = nums.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val) != index.end()){
            int i = index[val];
            index.erase(val);

            int num = nums.back();
            nums.pop_back();

            if(num != val){
                nums[i] = num;
                index[num] = i;
            }

            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int rndIndex = rand() % nums.size();
        return nums[rndIndex];
    }

    void printInfo(){
        cout << "nums : ";
        for(int num: nums)
            cout << num << " ";
        cout << endl;

        cout << "index : ";
        for(const pair<int, int>& p: index)
            cout << "( " << p.first << " , " << p.second << " ) ";
        cout << endl;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    RandomizedSet randomSet;
    print_bool(randomSet.insert(0));
    randomSet.printInfo();
    print_bool(randomSet.remove(0));
    randomSet.printInfo();
    print_bool(randomSet.insert(-1));
    randomSet.printInfo();
    print_bool(randomSet.remove(0));
    randomSet.printInfo();

    for(int i = 0 ; i < 10 ; i ++)
        cout << randomSet.getRandom() << " ";
    cout << endl;

    return 0;
}