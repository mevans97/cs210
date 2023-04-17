#include "itemCounter.cpp"//this is our item counter class
#include <string>
#include <iostream>


int main()
{
    //variables used

    ItemCounter itemCounter; // this creates our itemCounter object
    std::string dataFile = "C:/Users/Computer/OneDrive/Desktop/CS 210/Project3/CS210_Project_Three_Input_File.txt";//file with data
    std::string saveFile = "C:/Users/Computer/OneDrive/Desktop/CS 210/Project3/frequency.dat";//file our data will be saved to when the program closes
    int choice;//will be used to choose the menu option
    std::string item; //will be used for case1 in the switch case

    //program 
    itemCounter.fileInput(dataFile);//this opens a file and creates a map of items and their frequencies using the file data

    while(true)
    {
        // Display menu
        std::cout << "======================================" << std::endl;
        std::cout << "              MAIN MENU               " << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "1. Search for an item" << std::endl;
        std::cout << "2. Display all frequencies" << std::endl;
        std::cout << "3. Display histogram" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "======================================" << std::endl;

        //choose an option from the menu to enter into the swith case
        std::cout << "Choose an option : "<< std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1://runs the function for menu option 1
            std::cout << "Enter an item: " << std::endl;
            std::cin >> item;
            itemCounter.itemFrequencyValue(item);
            break;
        case 2://runs the function for menu option 2
            itemCounter.itemFrequencyListAsNumber();
            break;
        case 3://runs the function for menu option 3
            itemCounter.itemFrequencyListAsHistogram();
            break;
        case 4://runs the function for menu option 4
            //save data to output file
            std::cout << "Saving data...";
            itemCounter.fileOutput(saveFile);
            std::cout << "Goodbye :)" << std::endl;
            return false;//exits the while loop
            
        default:
            std::cout << "Invalid Input, please enter an option 1 - 4";
            break;
        }
    }
    

    return 0;
};
    