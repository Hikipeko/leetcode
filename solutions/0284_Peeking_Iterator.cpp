#include <vector>

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool peeked;
    int nextVal;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        peeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!peeked) nextVal = Iterator::next();
        peeked = true;
        return nextVal;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (peeked) {
            peeked = false;
            return nextVal;
        }
        else {
            peeked = false;
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return peeked || Iterator::hasNext();
    }
};

int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
}