#include "common.h"

class Solution {
public:
#define SUDOKU_SIZE 9	
    bool isValidSudoku(vector<vector<char> > &board) {
		return validSudokuBoard(board) && checkColumns(board) && checkRows(board) && checkSquares(board);
    }

	bool validSudokuBoard(vector<vector<char> > &board){
		if(board.size() != SUDOKU_SIZE){
			return false;
		}
		
		for(vector<vector<char> >::iterator itRow = board.begin();
			itRow != board.end();
			++itRow){
			if (itRow->size() != SUDOKU_SIZE)
				return false;
		}

		return true;
	}

	bool checkColumns(vector<vector<char> > &board){
		for(int i = 0; i < SUDOKU_SIZE; ++i){
			set<char> setNumber;
			for(vector<vector<char> >::iterator itRow = board.begin();
				itRow != board.end();
				++itRow){
				char num = (*itRow)[i];
				if(num != '.' && !setNumber.insert(num).second){
					return false;
				}
			}
		}
		return true;
	}

	bool checkRows(vector<vector<char> > &board){
		for(vector<vector<char> >::iterator itRow = board.begin();
			itRow != board.end();
			++itRow){
			set<char> setNumber;
			for(vector<char>::iterator it = itRow->begin();
				it != itRow->end();
				++it){
				if(*it != '.' && !setNumber.insert(*it).second){
					return false;
				}
			}
		}
		return true;
	}

	bool checkSquares(vector<vector<char> > &board){
		for(int x = 0; x < 3; ++x){
			for(int y = 0; y < 3; ++y){
				set<char> setNumber;
				for(int i = 3*x; i < 3*x + 3; ++i){
					for(int j = 3*y; j < 3*y + 3; ++j){
						char num = board[i][j];
						if(num != '.' && !setNumber.insert(num).second){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
};

int main(int argc, char** argv){
	return 0;
}
