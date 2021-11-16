#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// tricky use of linked list to keep track of the order and unordered_map for mapping
// O(1) for find value by key and O(1) by adjusting the order

class LRUCache {
    typedef pair<int, int> value; // key, val
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto target = map.find(key);
        if (target == map.end()) return -1;
        l.splice(l.begin(), l, target->second);
        return target->second->second;
    }

    void put(int key, int value) {
        auto target = map.find(key);
        if (target != map.end())
            l.erase(target->second);
        l.push_front(make_pair(key,value));
        map[key] = l.begin();
        if (map.size() > cap) {
            map.erase(l.rbegin()->first);
            l.pop_back();
        }
    }

private:
    int cap;
    list<value> l;
    unordered_map<int, list<value>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */