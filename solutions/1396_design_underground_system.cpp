#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ST {
    int time;
    string station;
};
struct Average {
    int cnt;
    int total;
};

class UndergroundSystem {
public:
    UndergroundSystem() {    }

    void checkIn(int id, string stationName, int t) {
        time[id] = {t, stationName};
    }

    void checkOut(int id, string stationName, int t) {
        ST prev = time[id];
        auto it = &(average[prev.station + " " + stationName]);
        it->cnt++;
        it->total += (t - prev.time);
    }

    double getAverageTime(string startStation, string endStation) {
        auto it = &(average[startStation + " " + endStation]);
        return double(it->total) / double (it->cnt);
    }

private:
    unordered_map<int, ST> time;
    unordered_map<string, Average> average;
};