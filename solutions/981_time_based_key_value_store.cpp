#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class TimeMap {
public:
    struct Value {
        int t;
        string v;
    };

    struct Order {
        bool operator()(const Value &l, const Value &r) { return l.t < r.t; }
    };

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m.find(key);
        if (it == m.end()) return "";
        if (timestamp < it->second.front().t) return "";
        Value temp = {timestamp, string("")};
        auto it2 = upper_bound(it->second.begin(), it->second.end(), temp, Order());
        it2--;
        if (it2->t == timestamp) return it2->v;
        return it2->v;
    }

private:
    unordered_map<string, vector<Value>> m;
};


int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    timeMap.get("foo", 1);         // return "bar"
    timeMap.get("foo",
                3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    timeMap.get("foo", 4);         // return "bar2"
    timeMap.get("foo", 5);
}
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */