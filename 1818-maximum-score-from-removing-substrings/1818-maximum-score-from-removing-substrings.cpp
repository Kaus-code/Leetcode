class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int p = 0;
        char firstA, firstB;
        int firstScore, secondScore;

        // Prioritize the more valuable pair
        if (x >= y) {
            firstA = 'a'; firstB = 'b';
            firstScore = x; secondScore = y;
        } else {
            firstA = 'b'; firstB = 'a';
            firstScore = y; secondScore = x;
        }

        // First pass: remove higher-value pairs
        stack<char> st;
        string temp;
        for (char c : s) {
            if (!st.empty() && st.top() == firstA && c == firstB) {
                st.pop();
                p += firstScore;
            } else {
                st.push(c);
            }
        }

        // Collect remaining characters
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        // Second pass: remove the lower-value pairs
        for (char c : temp) {
            if (!st.empty() && st.top() == firstB && c == firstA) {
                st.pop();
                p += secondScore;
            } else {
                st.push(c);
            }
        }

        return p;
    }
};
