#include "Management.h"

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


map<string, unsigned int>* loadFile() {
    string inputFilename = "Inventory.txt";
    ifstream inputFile;
    string inventoryRef;
    unsigned int currentNum;
    map<string, unsigned int>* inventoryMap = new map<string, unsigned int>;

    // open the input file
    inputFile.open(inputFilename);

    // error message if file cannot be opened
    if (!inputFile.is_open())
    {
        throw runtime_error("Could not open " + inputFilename + " ,please try again after making sure the file is accessable!");
    }

    // continue until the end of file
    while (!inputFile.fail())
    {
        // read in one line of the file
        getline(inputFile, inventoryRef);

        // check current inv number
        currentNum = (*inventoryMap)[inventoryRef];

        // store number
        (*inventoryMap)[inventoryRef] = currentNum + 1;
    }

    // close the input file
    inputFile.close();

    return inventoryMap;
}


int makeBackup(map<string, unsigned int>* t_inventoryMap) {
    string outputFilename = "frequency.dat";
    ofstream outputFile;
    string inventoryRef;
    unsigned int currentNum = 0;

    // open backup file
    outputFile.open(outputFilename);

    // let user know file could not be opened
    if (!outputFile.is_open())
    {
        throw runtime_error("Could not open " + outputFilename);
        return 1;
    }

    // add information to backup
    for (const pair<const string, unsigned int> item : (*t_inventoryMap))
    {
        outputFile << item.first << "," << item.second << endl;
    }

    // close the file
    outputFile.close();

    return 0;
}