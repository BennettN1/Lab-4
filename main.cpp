/*
 Nick Bennett
 C++ 2021
 October 17, 2021
 The purpose of the lab is getting a temps that are inside of file to input them to the screen and putting the temps graphed on the screen with stars as the bars of the graph. The range of temps inside of the lab should go from -30 to 120. Also have the maximum amount of stars on the screen should be 50 which means that each stars has a value of 3.
 */

#include <iostream>
#include <fstream> // file streaming
#include <iomanip> // using for the graph
#include <string>
#include <math.h> // math functions
using namespace std;
//the 2 functions that are for error checking the file and printing the graph out the screen
int ErrorCheck(ifstream inFile);
void Graph(string Filename, ifstream inFile);

int main()
{
    ifstream inFile;
    string Filename;
    do // seeing if the file that was selected is opening or not
    {
        cout << "Please enter the location of the file that you want to use: ";
        cin >> Filename; // entering the filename
        inFile.open(Filename); // opening the file
        if (!inFile) // if file can't be open or found this will run
        {
            cout << "The file that was input failed to open. Make sure the file location is correct. " << endl << "You may try again or can say 'q' or 'Q' to quit the program" << endl; // asking the user if they want to quit the porgram or not
            cin >> Filename;
            if (Filename == "q" || Filename == "Q")
            {
                cout << "You have choice to end the program. Goodbye for now!" << endl;
                return 1;
            } // stops the program if user chooses to
            else inFile.open(Filename);
        }
    } while (!inFile);
    
    int ErrorCheck(ifstream inFile);
    
    void Graph(string Filename,ifstream inFile);
    
    return 0;
}

int ErrorCheck(ifstream& inFile)
{
    char errorCheck;// seeing if the file has errors inside of the file itself
        inFile >> errorCheck;
        // seeing if the file that was inputed has an invalid value in it
        while (inFile)
        {
            if (isalpha(errorCheck)) // isalpha is used to find if there are chars inside of the file. If it comesback as true then the if statement will be outputted.
            {
                cout <<  endl << endl << "There is an error inside of the file!";
                cout << "____________________________________________________________________________" << endl;
                cout << "The file that was selected has a invalid input in it: " << "'" << errorCheck << "'" << endl;
                cout << "Ensure that the input file only has integer or float values." << endl;
                cout << "____________________________________________________________________________"<< endl;
                return 1; //errors were found in the input file and shuts down.
            }
            inFile >> errorCheck; // if no chars were found it will run as normal
        }
        inFile.close();
        return 0; // if nothing is outputted to the screen then nothing was found as an error
}

void Graph(string Filename, ifstream& inFile)
{
    float temp;
    cout << "Tempurates for a 24 hour period are: " << endl;
    cout << setw(8) << -30 << setw(8) << 0 << setw(10) << 30 << setw(10) << 60 << setw(10) << 90 << setw(10) << 120 << setw(10);
    // printing the heading of the graph with text and values of the range of the graph
    inFile.open(Filename.c_str());
        inFile >> temp;
        while (inFile)
        {
            temp = ceil(temp); // rounds numbers so that the code deals with only ints and not floats
            string starOutput;
            starOutput = "";
            if (temp < -30 || temp > 120) { // Checks to see if the temp is inside of the range of graph that is given
                inFile >> temp;
                continue; // tells computer to skip part of the loop
            }
            else { //temp in range
                cout << temp << ":";
            }
            //loop is used to get the correct number of stars per degree.
            for (int i = 1; i <= (abs(temp) / 3.0); ++i) //abs is used for negative inputs
            {
                starOutput.append("*"); //Appends a star to a string called starOutput every time the loop iterates.
            }
            //if else ladder prints the corressponding temperature and number of stars associated with that value
            if (temp == -30) {
                cout << setw(12) << starOutput + "|";
            }
            else if (temp > -30 && temp <= -10) {
                cout << setw(12) << starOutput + "|";
            }
            else if (temp > -10 && temp < 0) {
                cout << setw(13) << starOutput + "|";
            }
            else if (temp >= 0 && temp < 10) {
                cout << setw(14) << "|" << starOutput;
            }
            else if (temp >= 10 && temp < 100) {
                cout << setw(13) << "|" << starOutput;
            }
            else if (temp >= 100 && temp <= 120) {
                cout << setw(12) << "|" << starOutput;
            }
            cout << endl;
            inFile >> temp;
        }
        cout << "________________________";
        cout << "* = 3 degrees";
        cout << "________________________";
        inFile.close();
}
