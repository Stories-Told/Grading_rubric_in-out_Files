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

    // Variable for reading in the file (input)
    ifstream inFile;
    // Variable for creating new file (output)
    ofstream gradesFile;

    // Create new file called grades.txt
    gradesFile.open("grades.txt");


    // Read in the file of students data
    inFile.open("YOUR PATH HERE");

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
        // Runs while loop in order to:
        // store text from the .txt file into variables and output on
        // separate lines in formatted style
        // ends when reaches the EOF(end of file)
        while(inFile >> firstName >> lastName >> testOne >> testTwo >> testThree >> testFour)
        {
            // Variable to calculate weighted grade
            double finalNumberGrade =  ((testOne * 0.2) + (testTwo * 0.25) +
                                        (testThree * 0.25) + (testFour * 0.30));

            // String to store the letter grade
            string finalLetterGrade;

            // If statement to find the letter grade of the student
            if (finalNumberGrade >= 90)
            {
                finalLetterGrade = "A";
            }
            else if(finalNumberGrade >= 80)
            {
                finalLetterGrade = "B";
            }
            else if(finalNumberGrade >= 70)
            {
                finalLetterGrade = "C";
            }
            else if(finalNumberGrade >= 60)
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
