class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), isNotAlnum), s.end());
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char currLeft = std::tolower(static_cast<unsigned char>(s[left]));
            char currRight = std::tolower(static_cast<unsigned char>(s[right]));
            cout << currLeft << " " << currRight << "\n";
            if ((currLeft - 'A') != (currRight - 'A')) {
                return 0;
            }
            left++;
            right--;
        }

        return 1;
    }

private:
    static bool isNotAlnum(char c) {
        return isalnum(c) == 0;
    }
};
