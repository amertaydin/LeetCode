class Solution {
public:
    int romanToInt(string s) {
        map<char, int> codex;
        int size = s.size();
        int total = 0;

        codex['I'] = 1;
        codex['V'] = 5;
        codex['X'] = 10;
        codex['L'] = 50;
        codex['C'] = 100;
        codex['D'] = 500;
        codex['M'] = 1000;

        // Number at the right will always be added.
        // From right to left we can calculate without stepping over boundaries of string.
        total = codex[s[size - 1]];

        for (int i = size - 2; i >=0; i--) {

            if (codex[s[i]] < codex[s[i + 1]]) {
                total -= codex[s[i]];  // I V (-1 + 5)
            }
            else {
                total += codex[s[i]]; // V I (5 + 1)
            }
        }

        return total;

    }
};