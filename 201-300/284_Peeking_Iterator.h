#include <vector>

class Iterator {
public:
	struct Data;
	Data* data;
	Iterator(const std::vector<int>& nums);
	Iterator(const Iterator& iter);
	// Returns the next element in the iteration.
	int next();

    // Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums), useful(false) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!useful){
            temp = next();
            useful = true;
        }
        return temp;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(useful){
            useful = false;
            return temp;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
	    return useful || Iterator::hasNext();
	}

private:
    int temp;
    bool useful;
};