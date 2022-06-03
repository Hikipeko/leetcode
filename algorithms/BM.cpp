// Given two strings P and haystack, return the index
// of the first occurrence of P in haystack, or -1 if
// P is not part of haystack.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> buildBC(const string &P) {
    vector<int> res(256, -1);
    for (int i = 0; i < P.size(); i++)
        res[int(P[i])] = i;
    return res;
}

vector<int> buildSS(const string &P) {
    int m = P.length();
    vector<int> ss(m);
    ss[m - 1] = m;
    for (int lo = m - 1, hi = m - 1, j = lo - 1; j >= 0; j--) {
        if ((lo < j) && (ss[m - hi + j - 1] <= j - lo))
            ss[j] = ss[m - hi + j - 1];
        else {
            hi = j;
            lo = min(lo, hi);
            while ((0 <= lo) && (P[lo] == P[m - hi + lo - 1]))
                lo--;
            ss[j] = hi - lo;
        }
    }
    return ss;
}

vector<int> buildGS(const string &P) {
    vector<int> ss = buildSS(P);
    auto m = P.length();
    vector<int> gs(m);
    for (int j = 0; j < m; j++) gs[j] = m;
    for (int i = 0, j = m - 1; j < UINT_MAX; j--) {
        if (j + 1 == ss[j])
            while (i < m - j - 1)
                gs[i++] = m - j - 1;
    }
    for (auto j = 0; j < m - 1; j++)
        gs[m - ss[j] - 1] = m - j - 1;
    return gs;
}

int strStr(string P, string T) {
    vector<int> bc = buildBC(P);
    vector<int> gs = buildGS(P);
    int i = 0;
    while (T.length() >= i + P.length()) {
        int j = P.size() - 1;
        while (P[i] == T[i + j])
            if (0 > --j) break;
        if (0 > j) break; // match
        else i += max(gs[j], j - bc[T[i + j]]);
    }
    return i;
}

int main() {
    cout << strStr("try to buildnext", "buil");
    return 0;
}

