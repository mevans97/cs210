#include <string>
#include <iostream>
#include <map>
#include <fstream>

class ItemCounter{
    public:

    //----------------------------------------------------------------------------------------------------------------------------
        //The fileInput method will take in a file containing items and use it to populate the map
        void fileInput(std::string file){
            std::string line; // this will be used to store each line within the file while looping through it with getline()

            //opening file for use :
            std::cout << "Attempting to open file"<<std::endl;
            inFS.open(file);

            //below is an if statement lets the user know if there was an issue opening the file 
            if (!inFS.is_open()) {
                 throw std::invalid_argument("File was not successfully opened");
            }
            else{
                std::cout << "file successfully opened"<<std::endl;
            }

            // Can now use file

            //This while loop will populate the map with the items and their frequencies
            while(std::getline(inFS, line))//getline is used in order to go line by line through the file
            {
                if (itemFrequency.find(line) == itemFrequency.end()) { // this if statement is activated if the item does not exist in the map already
                    //if the line does not exist a new key with the item will be made with a starting frequency value of 1 being it is the first time the item is seen
                    itemFrequency[line] = 1;
                } 
                else {//this activates if the item is already in the map as a key
                    //if the item is already in the map as a key we will simply add 1 to the frequency
                    itemFrequency[line]++;
                }
            };

            //closing file so it can be used again 

            std::cout << "Closing file" << std::endl;
            inFS.close(); // Done with file, so close it
        };
    //-------------------------------------------------------------------------------------------------------------------
        //fileOutput takes data and writes said data to a file input by the user in the argument

        void fileOutput(std::string file){
            
            // Open file
            outFS.open(file);

            //check if file was opened successfully
            if (!outFS.is_open()) {
                throw std::invalid_argument("File was not successfully opened");
            }
            else{
                std::cout << "file successfully opened"<<std::endl;
            }

            // Write to file
            for(it = itemFrequency.begin(); it != itemFrequency.end(); it++){//this for loop uses the map iterator "it" to look through the map from beginning to end
                
                    outFS << it->first << ' ' << it->second << std::endl; // outFS is used as an input and writes it to the file

                    //it->first displays the key(the string value)
                    //it->second displays the value(the int value)
            }
            // Done with file, so close
            std::cout << "Data successfully saved...Closing file"<<std::endl;

            outFS.close();

        };
    //-------------------------------------------------------------------------------------------------------------------
        //itemFrequencyValue is a method that takes in a string to search for a matching key and return the frequency as a counter
        void itemFrequencyValue(std::string item){

            if (itemFrequency.find(item) == itemFrequency.end()) {
                std::cout << "Item was not found in the list"<<std::endl;
            } 
            else {
                std::cout << itemFrequency[item]<< std::endl;
            }
        };


    //--------------------------------------------------------------------------------------------------------------
        //itemFrequencyListAsNumber is a method that returns all items and their frequencies(output is as numbers) as a list utilizing the itemFrequency map and the 'it' iterator
        void itemFrequencyListAsNumber(){

            if(itemFrequency.empty() == 1){//when the .empty method returns 1 that means that no values exist in the map

                std::cout << "The list of items is empty" << std::endl;

            }
            else{
                for(it = itemFrequency.begin(); it != itemFrequency.end(); it++){//this for loop uses the map iterator "it" to look through the map from beginning to end
                
                    std::cout << it->first << ' ' << it->second << std::endl; // This outputs all key/value pairs to the display

                    //it->first displays the key(the string value)
                    //it->second displays the value(the int value)
                }
            }
        };

    //------------------------------------------------------------------------------------------------------------
        //itemFrequencyListAsHistogram is a method that returns all items and their frequencies(output is as numbers) as a list utilizing the itemFrequency map and the 'it' iterator
        void itemFrequencyListAsHistogram(){
            if(itemFrequency.empty() == 1){//when the .empty method returns 1 that means that no values exist in the map

                std::cout << "The list of items is empty" << std::endl;

            }
            else{
                for(it = itemFrequency.begin(); it != itemFrequency.end(); it++){//this for loop uses the map iterator "it" to look through the map from beginning to end
                
                    std::cout << it->first << ' ' << std::string(it->second,'*') << std::endl; // This outputs all key/value pairs to the display

                    //it->first displays the key(the string value)
                    //it->second holds the frequency of an item as an int value. We use that int value to display the '*' char that many times
                }
            }

        }

    private:

        // This is a map that will keep track of the item(string) as a key and the frequency(int) as the value
        std::map<std::string,int> itemFrequency; 

        // This iterator allows us to use the find() method to look up values by their key. example it.find(tomatoes) returns the value of tomatoes
        std::map<std::string,int>::iterator it;

        //This input file stream allows us to open files that we will use to populate the map when the itemCounter object is constructed
        std::ifstream inFS; //Input file stream

        //This output file stream allows us to open files that we will use to write our data to as we specify
        std::ofstream outFS; // Output file stream


};