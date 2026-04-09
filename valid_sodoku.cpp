#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>


using namespace std;
class Solution
{
public :
    bool isValidSudoku(vector<vector<char>>& board){
        unordered_set<string> s;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            char val = board[i][j];

            if( val !='.')
            {
                if(
                    !s.insert(string("r") + (char) i + val).second ||
                    !s.insert(string("c") + (char) j + val).second ||   
                    !s.insert(string("g") + (char) (i/3) + (char) (j/3) + val).second    
                ) return false;
            }
        }
    }
    return true;
    }
};
int main()
{
    Solution sol;
vector<vector<char>> board = {

        {'5','3','.','.','7','.','.','.','.'},

        {'6','.','.','1','9','5','.','.','.'},

        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},

        {'4','.','.','8','.','3','.','.','1'},

        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},

        {'.','.','.','4','1','9','.','.','5'},

        {'.','.','.','.','8','.','.','7','9'}

    };



    if (sol.isValidSudoku(board)) {

        cout << "The Sudoku board is valid." << endl;

    } else {

        cout << "The Sudoku board is invalid." << endl;

    }  
    return 0;

}
