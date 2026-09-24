#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string forward = "";
        string backward = "";

        for (char c : s) {
            if (isalpha(c) || isdigit(c)) {
                c = tolower(c);
                forward.push_back(c);
                backward.push_back(c);
            }
        }
        reverse(backward.begin(), backward.end());

        if (forward == backward) {
            return true;
        }        
        else return false;
    }
};
