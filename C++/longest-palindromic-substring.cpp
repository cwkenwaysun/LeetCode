// Time:  O(n)
// Space: O(n)

// Manacher's Algorithm.
/*class Solution {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        const int n = T.length();
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                ++P[i];
            }

            // If palindrome centered at i expands the past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum element in P.
        int max_i = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > P[max_i]) {
                max_i = i;
            }
        }

        return s.substr((max_i - P[max_i]) / 2, P[max_i]);
    }

private:
    string preProcess(const string& s) {
        if (s.empty()) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < s.length(); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};*/

#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int max_len = 0, l, r;
		string ans = "";
		for (int i = 0; i<s.size();) {
			l = r = i;
			while (r<s.size() - 1 && s[r] == s[r + 1]) r++;
			i = r + 1;
			while (r<s.size() - 1 && l>0 && s[r + 1] == s[l - 1]) {
				r++; l--;
			}
			if (r - l + 1 > max_len) {
				max_len = r - l + 1;
				ans = s.substr(l, r - l + 1);
			}
		}
		return ans;
	}
};
