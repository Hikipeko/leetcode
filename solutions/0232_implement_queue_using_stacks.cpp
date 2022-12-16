#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        sin.push(x);
    }

    int pop() {
        if (sout.empty()) transfer();
        int res = sout.top();
        sout.pop();
        return res;
    }

    int peek() {
        if (sout.empty()) transfer();
        return sout.top();
    }

    bool empty() {
        return sin.empty() && sout.empty();
    }

private:
    stack<int> sin;
    stack<int> sout;

    void transfer() {
        while (!sin.empty()) {
            sout.push(sin.top());
            sin.pop();
        }
    }
};
