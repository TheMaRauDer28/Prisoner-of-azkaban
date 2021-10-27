// Manacher's Algorithm - for LPS (Longest Palindrome Substring) - linear time
// All longest palindrom found by it
// Ex. from Hackerearth

    string convertToNewString(const string &s) {
        string newString = "@";

        for (int i = 0; i < s.size(); i++) {
            newString += "#" + s.substr(i, 1);
        }

        newString += "#$";
        return newString;
    }
    string longestPalindromeSubstring(const string &s) {
        string Q = convertToNewString(s);
        int c = 0, r = 0;                // current center, right limit

        for (int i = 1; i < Q.size() - 1; i++) {
            int iMirror = c - (i - c); // find the corresponding letter in the palidrome subString

            if(r > i) {
                P[i] = min(r - i, P[iMirror]);
            }

            while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){     // expanding around center i
                P[i]++;
            }

            if (i + P[i] > r) {     // Update c,r in case if the palindrome centered at i expands past r,
                c = i;              // next center = i
                r = i + P[i];
            }
        }
        int maxPalindrome = 0;
        int centerIndex = 0;

        for (int i = 1; i < Q.size() - 1; i++) {

            if (P[i] > maxPalindrome) {
                maxPalindrome = P[i];
                centerIndex = i;
            }
        }

        cout << maxPalindrome << "\n";
        return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
    }

// for finding longest prefix pelindrom just compare i==v[i]+1
// https://codeforces.com/problemset/problem/1326/D1
// ref - Hackerearth & GFG
