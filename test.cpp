// this file is for you for testing purposes, it won't be included in evaluation.

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "the4.h"

char getRandomChar(){
	char r = rand() % 5 + 65;
	return r;
}


void randomArray(char**& box1, char**& box2, int nrow, int ncol1, int ncol2)
{
	box1 = new char* [nrow];
	box2 = new char* [nrow];
	std::vector<char> column;
	
	for (int i = 0; i < nrow; i++) {
	   box1[i] = new char [ncol1];
	   box2[i] = new char [ncol2];
	}
	
	for (int i = 0; i < ncol1; i++)
	{
	    int nfull = rand() % nrow + 1;
	    for (int j = 0; j < nfull; j++) {
		    char r = getRandomChar();
		    column.push_back(r);
	    }
	    for (int j = nfull; j < nrow; j++) {
		    column.push_back('-');
	    }
	    std::random_shuffle(column.begin(), column.end());
	    for (int j = 0; j < nrow; j++) 
	        box1[j][i] = column[j];
        column.clear();
	}
	
	for (int i = 0; i < ncol2; i++)
	{
	    int nfull = rand() % nrow + 1;
	    for (int j = 0; j < nfull; j++) {
		    char r = getRandomChar();
		    column.push_back(r);
	    }
	    for (int j = nfull; j < nrow; j++) {
		    column.push_back('-');
	    }
	    std::random_shuffle(column.begin(), column.end());
	    for (int j = 0; j < nrow; j++) 
	        box2[j][i] = column[j];
	}
}


void printArrayInLine(char** arr, int nrow, int ncol){
	std::cout << "[ ";
	for(int i = 0; i < nrow; i++){
	    std::cout << "[";
	    for (int j = 0; j < ncol; j++) {
		    std::cout << arr[i][j];
		    if (j == ncol - 1)
			    std::cout << "]";
		    else
			    std::cout << ", ";
	    }
	    if (i == nrow - 1)
	        std::cout << " ]" << std::endl;
	    else
	        std::cout << ",\n";
	}
}


void printMemInLine(int** arr, int nrow, int ncol){
	std::cout << "[ ";
	for(int i = 0; i < nrow; i++){
	    std::cout << "[";
	    for (int j = 0; j < ncol; j++) {
		    std::cout << arr[i][j];
		    if (j == ncol - 1)
			    std::cout << "]";
		    else
			    std::cout << ", ";
	    }
	    if (i == nrow - 1)
	        std::cout << " ]" << std::endl;
	    else
	        std::cout << ",\n";
	}
}


void fillArray(char**& box1, char**& box2, int nrow, int ncol1, int ncol2)
{
        
	box1 = new char* [nrow];
	box2 = new char* [nrow];
	
	for (int i = 0; i < nrow; i++) {
	   box1[i] = new char [ncol1];
	   box2[i] = new char [ncol2];
	}

    
  
    box1[0][0] = 'A'; box1[0][1] = 'B'; box1[0][2] = 'C'; box1[0][3] = 'A'; box1[0][4] = 'B'; box1[0][5] = 'C';
	box1[1][0] = 'B'; box1[1][1] = 'C'; box1[1][2] = 'C'; box1[1][3] = 'A'; box1[1][4] = '-'; box1[1][5] = 'A';
	
	box2[0][0] = 'A'; box2[0][1] = 'B'; box2[0][2] = 'B'; box2[0][3] = 'A';
	box2[1][0] = 'B'; box2[1][1] = 'A'; box2[1][2] = '-'; box2[1][3] = 'C';
	
}


void test(){
    clock_t begin, end;
    double duration;
    int min_cost_dp;


    int nrow = 2;      // max 100
    int ncol1 = 6;     // max 100
    int ncol2 = 4;     // max 100
    char** box1, ** box2;
	//randomArray(box1, box2, nrow, ncol1, ncol2);
	fillArray(box1, box2, nrow, ncol1, ncol2);
    std::cout << "BOX-1:" << std::endl;
    printArrayInLine(box1, nrow, ncol1);
    std::cout << "\nBOX-2:" << std::endl;
    printArrayInLine(box2, nrow, ncol2);
    std::cout << "\n\n";

    int** mem = new int*[ncol1+1];

    for(int i = 0; i <= ncol1; i++){
	    mem[i] = new int [ncol2+1];
	    for (int j = 0; j <= ncol2; j++)
		    mem[i][j] = -1;
	}



    std::cout << "__________________DYNAMIC PROGRAMMING:______________" << std::endl;

    for(int i = 0; i <= ncol1; i++){
	    for (int j = 0; j <= ncol2; j++)
		    mem[i][j] = -1;
	}


    if ((begin = clock() ) ==-1)
        std::cerr << "clock error" << std::endl;

    min_cost_dp = dp_sln(box1, box2, nrow, ncol1, ncol2, mem);

    if ((end = clock() ) ==-1)
        std::cerr << "clock error" << std::endl;

    duration = ((double) end - begin) / CLOCKS_PER_SEC;
    std::cout << "Duration: " << duration << " seconds." << std::endl;

    std::cout << "Min cost: " << min_cost_dp << std::endl;
    std::cout << "Final mem: " << std::endl;
    printMemInLine(mem, ncol1+1, ncol2+1);

    std::cout << "----------------------------------------------------";
    std::cout << "\n" << std::endl;

}

int main()
{
    srandom(time(0));
    test();
    return 0;
}
