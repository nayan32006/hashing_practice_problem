#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Student Class
class Student {
public:
    int RollNo;
    string StudentName;

    // Constructor: Student बनाने के लिए
    Student(int roll, string name) {
        RollNo = roll;
        StudentName = name;
    }
};

// 2. School Class (Hashing Logic)
class School {
public:
    Student** students; // Students के pointers का array
    int size;

    School(int s) {
        size = s;
        students = new Student*[size]; // Array allocate किया
        for (int i = 0; i < size; i++) {
            students[i] = nullptr; // शुरुआत में सब खाली (NULL) हैं
        }
    }

    // Hash Function: Index कैलकुलेट करने के लिए
    int HashFunction(int key) {
        return key % size;
    }

    // Insert Function: Linear Probing के साथ
    void Insert(int key, string data) {
        int hashIndex = HashFunction(key);

        // Linear Probing: अगर जगह भरी है, तो अगली खाली जगह ढूंढो
        while (students[hashIndex] != nullptr) {
            hashIndex = (hashIndex + 1) % size;
        }
        
        // नई Student object बनाकर उस index पर रखो
        students[hashIndex] = new Student(key, data);
    }

    // Display Function
    void Display() {
        for (int i = 0; i < size; i++) {
            if (students[i] != nullptr) {
                cout << "Index " << i << " -> RollNo: " << students[i]->RollNo 
                     << ", StudentName: " << students[i]->StudentName << endl;
            }
        }
    }

    // Destructor: Memory साफ करने के लिए
    ~School() {
        for (int i = 0; i < size; i++) {
            delete students[i];
        }
        delete[] students;
    }
};

// 3. Main Function
int main() {
    int size = 10;
    School pvtSchool(size);

    pvtSchool.Insert(12, "Ram");    // 12 % 10 = Index 2
    pvtSchool.Insert(3, "Ramesh");  // 3 % 10 = Index 3
    pvtSchool.Insert(2, "Suresh");  // Index 2 भरा है, तो Index 4 पर जाएगा
    pvtSchool.Insert(4, "Naresh");  // Index 4 भरा है, तो Index 5 पर जाएगा
    pvtSchool.Insert(5, "Mahesh");  // Index 5 भरा है, तो Index 6 पर जाएगा

    pvtSchool.Display();

    return 0;
}