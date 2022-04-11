#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 1;
        vector<bool> is_prime(true, n);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (!is_prime[i]) continue;
            for (int j = 2 * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        int res = 0;
        for (auto b : is_prime)
            if (b) res++;
        return res;
    }
};

