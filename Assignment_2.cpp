#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

int main()
{

    // Variables for first and last name
    string firstName;
    string lastName;

    // Variables for test scores
    double testOne;
    double testTwo;
    double testThree;
    double testFour;

    // Variables to use to match against the final grade
    // to get the letter grade
    int gradeA = 9;
    int gradeB = 8;
    int gradeC = 7;
    int gradeD = 6;


    // Variable for reading in the file
    ifstream inFile;
    ofstream gradesFile;

    // Create new file called grades.txt
    gradesFile.open("grades.txt");


    // Read in the file of students data
    inFile.open("C:\\Users\\Michael\\Documents\\CS150 Assignments\\Assignment 2\\students.txt");

    // Check if the file was open
    // if not throw an error
    if(!inFile)
    {
        cerr << "Unable to open file students.txt";
        exit(1); // Call system to stop
    }

    // Read from the stream
    if(inFile.is_open())
    {
        while(inFile >> firstName >> lastName >> testOne >> testTwo >> testThree >> testFour)
        {
            // Variable to calculate weighted grade
            double finalNumberGrade =  ((testOne * 0.2) + (testTwo * 0.25) +
                                       (testThree * 0.25) + (testFour * 0.30));
            // Variable to get the first digit of the final number grade
            int firstDigitOfNumberGrade = finalNumberGrade;

            // String to store the letter grade
            string finalLetterGrade;

            //loop to get the first digit
            while(firstDigitOfNumberGrade >= 10)
            {
               firstDigitOfNumberGrade = firstDigitOfNumberGrade / 10;
            }


            // If statement to check if the first number in final number grade
            // is the same as the int for each variable grade
            // if they match then thats the letter grade for that user
            if (firstDigitOfNumberGrade == gradeA)
            {
                finalLetterGrade = "A";
            }
            else if(firstDigitOfNumberGrade == gradeB)
            {
                finalLetterGrade = "B";
            }
            else if(firstDigitOfNumberGrade == gradeC)
            {
                finalLetterGrade = "C";
            }
            else if(firstDigitOfNumberGrade == gradeD)
            {
                finalLetterGrade = "D";
            }
            else
            {
               finalLetterGrade = "F";
            }

            // Output the information for the user to read
            // making sure to set the limit of characters per column using setw()
            // and setting the justification
            cout << left
                 << setw(15)
                 << lastName
                 << left
                 << setw(15)
                 << firstName
                 << right
                 << setw(6)
                 << setprecision(3)
                 << finalNumberGrade
                 << right
                 << setw(4)
                 << finalLetterGrade
                 << endl;

            // This reads into the new file called grades.txt
            // and saves it
            gradesFile << left
                 << setw(15)
                 << lastName
                 << left
                 << setw(15)
                 << firstName
                 << right
                 << setw(6)
                 << setprecision(3)
                 << finalNumberGrade
                 << right
                 << setw(4)
                 << finalLetterGrade
                 << endl;
        }
    }

    //*BONUS*
    // Print the time in the file it was saved
    time_t now = time(0);
    tm* localtm = localtime(&now);
    gradesFile << "\nTime saved: " << asctime(localtm) << endl;

    // Close the input streams
    inFile.close();
    gradesFile.close();

    return 0;
}
