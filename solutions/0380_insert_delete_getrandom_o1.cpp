#include <vector>
#include <unordered_map>
#include <algorithm>

// map, sliding window

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        auto it = map.find(val);
        if (it != map.end()) return false;
        v.push_back(val);
        map[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        auto it = map.find(val);
        if (it == map.end()) return false;
        int i = map[val];
        map[v.back()] = i;
        swap(v[i], v.back());
        map.erase(val);
        v.pop_back();
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }

private:
    // <value, index in v>
    unordered_map<int, int> map;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */