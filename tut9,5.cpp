#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <ctime>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::vector;



void save_score(int count)                                           // Function to keep track of best score
{   
    string filu = "best_score";
    std::ofstream file;
    file.open("Data\\" + filu + ".txt");                             // Opens file (creates if doesn't exist) to folder data using username as file name
    file.close();                                                    // Creates file "best_score.txt"                                            
    std::ifstream input("best_score.txt");                           // Opens file "best_score.txt"
    if(!input.is_open())                                             // Check if you couldnt open the file
    {
        cout << "Unable to read file \n";
        return;
    }

    int best_score;
    input >> best_score;                                             // Inputs best score

    std::ofstream output("best_score.txt");
    if(!output.is_open())
    {
        cout << "Unable to read file \n";
        return;
    }
    if(count < best_score)                                           // If new score is lower than high score, save the new score
    {
        output << count;
    }
    else                                                             // Otherwise save the previous high score
    {
        output << best_score;
    }

}

void print_vector(vector<int> vector)                                // Adds +1 to vector everytime  play game is ran
{
    for(int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << "\t";
    }
    cout << "\n";
}

void play_game()
{
    vector<int> guesses;     
    int count = 0;
    int random = rand() % 251;                                      // Picks "random" number between 0-250
    cout << random << std::endl;                                    // Shows the picked random number, just to make it easier to visualize & test, can be removed.
    cout << "Toss a number: ";
    while(true)                                                     // While loop for guesses
    {
        int guessi;                                                 // Couldnt get vector input work, but worked around it. Not the most elegant, but does the job. 
        std::cin >> guessi;                                         // Takes user input for random number guess.   
        count++;

        guesses.push_back(guessi);                                  // Pushes the guess to vector guessess for tracking
        
        if(guessi == random)                                        // If guess equals to random number, we got a winner.
        {   
            cout << "Ding ding ding, someones lucky! \n";
            break;
        } else if (guessi < random)                                 // If guessed number is smaller than random 
        {
            cout << "Too low, try going higher! \n";
        } else                                                      // Else ( if number is bigger than random number)
        {
            cout << "Too high, try going lower! \n";
        }
    }

    save_score(count);                                              // Saves the "High score", amount of guesses used
    print_vector(guesses);                                          // Prints vector that stores all guesses 
}

void mainmenu()                                                     // Menu for starting / quitting the game
{
    srand(time(NULL));                                              // Uses internal clock to control random number seed
    int choice;                                                     // int for choosing to play or not to play
    do
    {
       cout << "0. QUIT" << std::endl << "1. PLAY GAME\n"; 
       std::cin >> choice;                                          // Takes user input for Playing again or Closing the game

       switch(choice)
       {
            case 0:                                                 // Run if 0 chosen
                cout << "Thanks for nothing\n";
                continue;
            case 1:                                                 // Run if 1 chosen
                cout << "WE GO AGAIN!\n";
                play_game();                                        // Calls the function game
                break;
       }
    } while (choice != 0);

}
