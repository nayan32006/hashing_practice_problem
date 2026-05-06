#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // अगर इनपुट खाली है, तो खाली लिस्ट भेजें
        if (digits.empty()) return {};

        // 2 से 9 तक के नंबर्स का मैप (Index 0 पर '2' का डेटा है)
        vector<string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations;
        
        backtrack(0, digits, "", combinations, phone_map);
        return combinations;
    }
    
private:
    void backtrack(int index, const string& digits, string path, vector<string>& combinations, const vector<string>& phone_map) {
        // Base Case: अगर हमने सारे डिजिट्स प्रोसेस कर लिए हैं
        if (index == digits.size()) {
            combinations.push_back(path);
            return;
        }

        // वर्तमान नंबर के लिए अक्षर निकालें (digits[index] - '2' इंडेक्स एडजस्ट करने के लिए)
        string possible_letters = phone_map[digits[index] - '2'];

        // हर अक्षर के लिए गहराई में जाएं (Explore each letter)
        for (char letter : possible_letters) {
            backtrack(index + 1, digits, path + letter, combinations, phone_map);
        }
    }
};

// VS Code में टेस्ट करने के लिए Main फंक्शन
int main() {
    Solution sol;
    string digits = "23";
    
    vector<string> result = sol.letterCombinations(digits);

    cout << "Combinations for \"" << digits << "\":" << endl;
    cout << "[ ";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"" << (i == result.size() - 1 ? "" : ", ");
    }
    cout << " ]" << endl;

    return 0;
}