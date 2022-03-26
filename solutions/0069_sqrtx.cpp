class Solution {
public:
    int mySqrt(int x) {
        uint64_t y = uint64_t(x);
        uint64_t i = 1;
        while (i * i <= y) i *= 2;
        i /= 2;
        while (i * i <= y) i += 1;
        return i - 1;
    }
};