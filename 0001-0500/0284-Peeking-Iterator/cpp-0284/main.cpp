/// Source : https://leetcode.com/problems/peeking-iterator/
/// Author : liuyubobobo
/// Time   : 2021-02-08

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1) for every method
/// Space Complexity: O(1)

/// Below is the interface for Iterator, which is already defined for you.
/// **DO NOT** modify the interface for Iterator.
class Iterator {

public:
	struct Data;
	Data* data;

	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {

private:
    int p_value = -1;
    bool p_has_value;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.

        p_has_value = Iterator::hasNext();
        if(p_has_value)
	        p_value = Iterator::next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return p_value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ret = p_value;
        p_has_value = Iterator::hasNext();
        if(p_has_value)
            p_value = Iterator::next();
        return ret;
	}

	bool hasNext() const {
        return p_has_value;
	}
};


int main() {

    return 0;
}
