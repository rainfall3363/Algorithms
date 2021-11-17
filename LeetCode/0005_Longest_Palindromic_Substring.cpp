bool isPalin(string str) {
    int startIdx = 0;
    int backIdx = str.length() - 1;
    
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[startIdx] != str[backIdx]) {
            return false;
        }
        startIdx++;
        backIdx--;
    }
    
    return true;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int longestPalindromeLength = 0;
        string result = "";
        
        for (int i = 0; i < s.length() - 1; i++) {
            for (int j = i; j < s.length(); j++) {
                if (s[i] == s[j] && j - i + 1 > longestPalindromeLength && isPalin(s.substr(i, j - i + 1))) {
                    result = s.substr(i, j - i + 1);
                    longestPalindromeLength = j - i + 1;
                }
            }
        }
        
        if (s.length() == 1) {
            result = s;
        }
        return result;
    }
};
