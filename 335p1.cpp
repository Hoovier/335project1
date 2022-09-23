// 335p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//this function will just print all the elements in the diskList
void printDiskList(vector<string> diskList)
{
    for (string element : diskList)
    {
        cout << element << " ";
    }
    cout << endl;
}

//this struct is used so that the sortDisks function can return both a vector and an int, as required
//by the project description
struct diskResult
{
    int m;
    vector<string> diskList;
    
    //constructor
    diskResult(vector<string> _list, int _m) 
    {
        diskList = _list;
        m = _m;
    }
};

diskResult sortDisks(int n, vector<string> diskList)
{
    int moves = 0;
    //here we will loop the swaps for (n/2)+1 times
    //because this allows odd number of n to be processed correctly without
    //affecting the M count.
    for (int k = 0; k < ((n/2)+1); k++)
    {
        //loop through every element going forward -1 because we are looking "ahead"
        for (int i = 0; i < ((2 * n)-1); i++)
        {
            //if a white is on the left, with a black on the right, swap them.
            if (diskList[i] == "White" && diskList[i + 1] == "Black")
            {
                moves++;
                diskList[i] = "Black";
                diskList[i + 1] = "White";
            }
        }
        //printDiskList(diskList);
        //loop through every element going backward
        for (int i = ((2*n)-1); i > 0; i--)
        {
            //if a white is on the left, with a black on the right, swap them.
            if (diskList[i] == "Black" && diskList[i - 1] == "White")
            {
                moves++;
                diskList[i] = "White";
                diskList[i - 1] = "Black";
            }
        }
        //printDiskList(diskList);
    }
    //construct our return object.
    diskResult result = diskResult(diskList, moves);
    return result;
}


int main()
{
    int n = 5;
    cout << "Project 1: CPSC 335!\n";
    cout << "Javier Perez\n";
    cout << "Please enter the n disks: ";
    //set up our diskList
    vector<string> diskList;
    cin >> n;
    //fill our list as described by project description
    //"They  alternate:  light,  dark,  light, dark, and so on."
    for (size_t i = 0; i < (2*n); i++)
    {
        if (i % 2 != 0)
        {
            diskList.push_back("Black");
        }
        else
        {
            diskList.push_back("White");
        }
    }
    //print starting diskList
    printDiskList(diskList);
    cout << "Sorting..." << endl;
    //call our sortDisks function.
    diskResult result = sortDisks(n, diskList);
    //print resulting list, sorted.
    printDiskList(result.diskList);
    cout << "Total Moves: " <<  result.m << endl << "Enter any character to close this window!\n";
    cin >> n;
    return 0;

}


