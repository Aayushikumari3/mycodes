class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(maxHeight(red, blue), maxHeight(blue, red));
    }

private:
    int maxHeight(int a, int b) {
        int i = 1;
        while (true) {
            if (a <= 0 || a < i) return i-1;
            a -= i;
            i++;
            if (b <= 0 || b < i) return i-1;
            b -= i;
            i++;
        }
    }
};