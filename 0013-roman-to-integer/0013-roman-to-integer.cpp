class Solution {
public:
    int romanToInt(string s) {
        int a = 0, c = 0, p = 0;
        for (char i = s.length() - 1; i >= 0; i--) {
            switch (s[i]) {
                case 'M': c = 1000; break;
                case 'D': c = 500; break;
                case 'C': c = 100; break;
                case 'L': c = 50; break;
                case 'X': c = 10; break;
                case 'V': c = 5; break;
                case 'I': c = 1; break;
                default: c = 0;
            }
            (c < p) ? a -= c : a += c;
            p = c;
        }
        return a;
    }
};