#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Har place value (units, tens, hundreds, thousands) ke liye lookup tables
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]  = {"","M","MM","MMM"};
        
        // Number ko break karke har hisse ka Roman equivalent concatenate (jod) kar rahe hain
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10]; 
    }
};

int main() {
    Solution sol;
    int number;

    cout << "Ek number enter karein (1-3999): ";
    cin >> number;

    if (number < 1 || number > 3999) {
        cout << "Kripya 1 se 3999 ke beech ka number daalein." << endl;
    } else {
        string roman = sol.intToRoman(number);
        cout << "Roman Numerals mein: " << roman << endl;
    }

    return 0;
}