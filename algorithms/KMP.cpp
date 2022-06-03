// Given two strings needle and haystack, return the index
// of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> buildNext(const string &needle) {
    auto m = needle.size();
    vector<int> res(m);
    res[0] = -1;
    for (int j = 1; j < m; j++) {
        int t = res[j - 1];
        while (t != -1 && needle[t] != needle[j - 1])
            t = res[t];
        res[j] = t + 1;
    }
    return res;
}

int strStr(string haystack, string needle) {
    vector<int> next = buildNext(needle);
    int n = haystack.length(), m = needle.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (0 > j || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    return j == m ? i - j : -1;
}

int main() {
    cout << strStr("try to buildnext", "buil");
    return 0;
}

