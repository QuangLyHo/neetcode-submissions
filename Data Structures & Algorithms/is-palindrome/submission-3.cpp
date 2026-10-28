class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1) return true;
        int left = 0;
        int right = s.size()-1;

        while (left < right) {
            while ( left < right && !isAlphaNum(tolower(s[left]))) left++;
            while (left < right && !isAlphaNum(tolower(s[right]))) right--;

            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }

    bool isAlphaNum(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
};
