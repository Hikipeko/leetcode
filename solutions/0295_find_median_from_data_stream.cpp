#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>> smaller;
    priority_queue<int, vector<int>, std::greater<>> greater;
public:
    MedianFinder() {}

    void addNum(int num) {
        if (greater.empty()) {
            greater.push(num);
        } else if (smaller.size() == greater.size()) {
            // add it to greater
            if (num > smaller.top()) {
                greater.push(num);
            } else {
                greater.push(smaller.top());
                smaller.pop();
                smaller.push(num);
            }
        } else {
            // add it to smaller
            if (num < greater.top()) {
                smaller.push(num);
            } else {
                smaller.push(greater.top());
                greater.pop();
                greater.push(num);
            }
        }
    }

    double findMedian() {
        if (greater.size() == 0) return 0;
        if (smaller.size() == greater.size()) {
            return double(smaller.top() + greater.top()) / 2;
        } else
            return double(greater.top());
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.findMedian();
    return 0;
}