#include <vector>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer*     // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList_) {
        help(nestedList_);
        cnt = 0;
    }

    void help(const vector<NestedInteger> &nestedList_) {
        for (auto i: nestedList_) {
            if (i.isInteger()) nestedList.push_back(i.getInteger());
            else help(i.getList());

        }
    }

    int next() {
        return nestedList[cnt++];
    }

    bool hasNext() {
        return cnt != nestedList.size();
    }

private:
    vector<int> nestedList;
    int cnt;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */