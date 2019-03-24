/**
*
* \file     main.cpp
* \author   Cyrus Lomibao
* \class    Computer Programming I, CIT-1154-C02
* \date     2018-11-19
* \brief    Program that counts vowel from input file
*
* This Vowel Counter program is documented
*
*  Pre-Condition: There is an input file in the same folder where this C++ file is located
*  and that input file consists of vowels, or not.
*
*  Post-Condition: This program counts the amount of certain vowels detected from the input file
*  and prints stars as results to a new output file named "Analysis-" added to the original file name.
*
**/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

const int SIZE = 5;

void countFromFile(ifstream& inStream, int count[], int size);
void reportToFile(ofstream& outStream, int count[], int size);
void printStars(ofstream& outputStar, int n);

int main()
{
    char fileName[50];
    char fillIn[50];
    int counter[SIZE];
    ifstream inFile;
    ofstream outFile;

	// Program Banner
    cout << "Vowel Counter - Assignment 4 - CIT-1154-CO2" << endl;
    cout << "by Cyrus Lomibao";
    cout << endl;
    cout << endl;

    cout << "This program will count the vowels in the requested file and will create" << endl;
    cout << "a histogram of the results in a file with a similar name." << endl;
    cout << "(e.g. sample.txt will generate Analysis-sample.txt)" << endl;
    cout << endl;

    // This allows user to specify which file to process
    cout << "Please enter the name of the file you want to analyze: " << endl;
    cin.getline(fileName, 50);

    cout << endl;
    cout << "Great! We will analyze the file: " << endl << fileName << endl;

    // Opens the file entered by the user
    inFile.open(fileName);
    if (inFile.fail()) {
        cout << endl;
        cout << "Input file opening failed!";
        exit(1);
    }

    // Function call for function
    // that counts vowels from the input file
    countFromFile(inFile, counter, SIZE);

    // member function strcpy puts the string "Analysis-" into variable fillIn and 
	// member function strncat attaches the file name
    // indicated by the user to the variable fillIn to form file that is
	// named "Analysis-(file name indicated by user)"
    strcpy (fillIn, "Analysis-");
    strncat (fillIn, fileName, 50);

	// Opens output file using value stored in variable fillIn as file name
    outFile.open(fillIn);
    if (outFile.fail()) {
        cout << endl;
        cout << "Output file opening failed!";
        exit(1);
    }

    cout << endl;

    // Function call for function
    // that outputs results from countFromFile function to output file
    reportToFile(outFile, counter, SIZE);

    // The string displayed below is what is used as scale of how much
    // of a certain vowel is in an input file that is analyzed by the program
    outFile << "   -+----+----+----+----+----+----+----+----+----+----+-----+----+----+----+----+----+----+----+----+----+----" << endl;
    outFile << "    0    5    10   15   20   25   30   35   40   45   50    55   60   65   70   75   80   85   90   95  100";

    inFile.close();
    outFile.close();

    return 0;
}


void countFromFile(ifstream& inStream, int count[], int size)   {

    int vowelA = 0, vowelE = 0, vowelI = 0, vowelO = 0, vowelU = 0;
    char text;

    // This while loop reads a file which contains
    // an if statement that scans and reads if there is a certain vowel in a file
    while(inStream >> text)  {

        if((text == 'A') || (text == 'a'))  {

            vowelA++;


        }else if((text == 'E') || (text == 'e'))  {

            vowelE++;


        }else if((text == 'I') || (text == 'i'))  {

            vowelI++;


        }else if((text == 'O') || (text == 'o'))  {

            vowelO++;


        }else if((text == 'U') || (text == 'u'))  {

            vowelU++;


        }

    }

    // The results from the if statements above is then
    // stored inside the following count[] elements
    count[0] = vowelA;
    count[1] = vowelE;
    count[2] = vowelI;
    count[3] = vowelO;
    count[4] = vowelU;

}

void reportToFile(ofstream& outStream, int count[], int size) {

    using namespace std;

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};

    //This for loop outputs the results of each vowel that was analyzed
    for(int vowelTitle = 0; vowelTitle < size; vowelTitle++)   {

        outStream << vowels[vowelTitle] << " |  ";

		// Function call for function that outputs stars based on
		// amount of certain vowels stored in elements of array count[]
        printStars(outStream, count[vowelTitle]);
        outStream << endl;

    }

}

void printStars(ofstream& destination, int n)  {

    using namespace std;

    // This for loop outputs stars based on how much of a certain vowel is counted
    for(int count = 0; count < n; count ++)  {

        destination << "*";

    }

}
