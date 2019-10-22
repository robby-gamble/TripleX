#include <iostream>
#include <ctime> // I need time capabilities to effect the range of the random values for my difficulty.


void printIntroduction(int Difficulty){
    
    //This is the welcome message for the game.
    std::cout << "\n\n You are a secret agent breaking into a level " << Difficulty <<" secure server room...";
    std::cout << std::endl;
    std::cout <<"Enter the correct code to continue...\n\n";
    
}
bool PlayGame(int Difficulty){
    
    printIntroduction(Difficulty);
    
    // Declaring my easy level variables
    const int codeA = rand() % Difficulty + Difficulty;
    const int codeB = rand() % Difficulty + Difficulty;
    const int codeC = rand() % Difficulty + Difficulty;
    
    
    const int codeSum = codeA + codeB + codeC;
    const int codeProduct = codeA * codeB * codeC;
    
    // Display the codeSum and codeProducts to the terminal
    
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << codeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << codeProduct << std::endl;
    
    //Store Player Guesses
    int guessA, guessB, guessC;
    std::cin >> guessA >> guessB >> guessC;
    std::cout<< "You entered: " << guessA << guessB << guessC;
    
    int guessSum = guessA + guessB + guessC;
    int guessProduct = guessA * guessB * guessC;
    
    //Checking if the player's guess is correct
    if(guessSum == codeSum && guessProduct == codeProduct){
        std::cout << "\n*** Great job! You've extracted a file. Keep going! ***";
        return true;
    }
    else {
        std::cout << "\n*** You entered the wrong code. Be careful agent! Try again! ***";
        return false;
    }
}


int main(){
    srand(time(NULL)); // Creates a new seed everytime I begin a new game based on the time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficutly = 5;
    
    while(LevelDifficulty <= MaxDifficutly){
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears errors
        std::cin.ignore();// discards the buffer
   
    if(bLevelComplete){
        
        LevelDifficulty++;
        
        }
    }
    
    std::cout<< "\n*** Good work agent! You've extracted all the files. Now get out of there! ***\n";
    return 0;
}
