class Solution {
public:
    // arr of strings -> string -> arr of strings
    // all 256 ASCII chars allowed
    // o(m) time o(m+n) space

    // thought one - map every char to some sort of a numerical rep
    // with a designated separator:
    // ["Hello", "World"]
    // "12334,54637"
    // issue - only 10 numbers.. should I do a combination after 10
    // like 00, 01.. and so on? or some bit rep instead?
    // but how do I map 256 ASCII chars - I don't even have all on my keyboard..
    // so now this requires smth more dynamic?
    // like - if an unseen char appears -
    // make something for depending on the last recorded one?
    // another thing - 52 chars are the same just diff in casing..
    // wait is there alr a rep for ASCII in numbers?
    // i think so.. turns out they comprise of the full 8 bit byte range (256)
    // of values of which 0-126 are common, 127-255 vary depending
    // on the page content, etc.

    // reminds me of tokenization in LLMs haha
    // stemming, lemmatization, etc.

    // read about unicode and the popular UTF-8 in brief
    // and how they are also rep as code points - numbers + letters,
    // dang, I was close.
    // but to write this algo? sheesh, doesn’t feel like a medium..
    // follow up - can it be generalized for any input?

    string encode(vector<string>& strs) {
        string result;
        for (string& str: strs) {
            result += to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);
            result.push_back(word);

            i = j + 1 + len;
        }

        return result;
    }
};
