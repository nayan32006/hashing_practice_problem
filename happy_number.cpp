#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        if (n == 1 || n == 7) {
            return true;
        } 
       
        else if (n < 10) {
            return false;
        } 
        else {
            int sum = 0;
            while (n > 0) {
                int temp = n % 10;
                sum += temp * temp;
                n = n / 10;
            }
            
            return isHappy(sum);
        }
    }
};

int main() {
    Solution sol;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // We store the result because 'number' doesn't change in main,
    // but we want to know if it WAS happy.
    if (sol.isHappy(number)) {
        cout << number << " is a happy number." << endl;
    } else {
        cout << number << " is not a happy number." << endl;
    }

    return 0;
}