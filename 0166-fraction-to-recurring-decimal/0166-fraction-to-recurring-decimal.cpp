class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "Undefined";
        if (numerator == 0) return "0";

        string ans;
        // handle sign
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // integer part
        ans += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return ans;    // no fractional part

        ans += ".";
        unordered_map<long long, int> seen;  // remainder -> index in ans

        while (rem != 0) {
            if (seen.count(rem)) {
                // we have seen this remainder → repeating cycle
                ans.insert(seen[rem], "(");
                ans.push_back(')');
                return ans;
            }
            seen[rem] = ans.size();
            rem *= 10;
            ans.push_back('0' + (rem / den));
            rem %= den;
        }
        return ans;
    }
};