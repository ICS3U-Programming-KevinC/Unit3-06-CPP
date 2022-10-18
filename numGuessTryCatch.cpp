// Copyright (c) 2022 Kevin Csiffary All rights reserved.
//
// Created by: Kevin Csiffary
// Date: Oct. 17, 2022
// This program gets the user to guess a randomly selected number
// it also has error checking

// Include all required libraries
#include <time.h>
#include <iostream>

int main() {
    // declare all required variables
    int randomInt;
    std::string userGuessStr;
    int userGuessInt;
    bool exception = false;
    unsigned int seed;

    // sets the seed for the random number to the time
    seed = time(NULL);

    // generates the random number
    randomInt = rand_r(&seed) % 9 + 0;

    // asks user for their guess
    std::cout << "Im thinking of a number between 0 and 9" << std::endl;
    std::cout << "whats your guess? ";
    std::cin >> userGuessStr;

    // adds extra line
    std::cout << "\n";

    // tries to cast the users guess into an integer
    try {
        userGuessInt = std::stoi(userGuessStr);

    // if it cannot cast, display that the input is invalid
    } catch (std::invalid_argument) {
        exception = true;
        std::cout << userGuessStr << " is an invalid integer" << std::endl;
    }


    // workaround for else statement
    if (!exception) {
        // checks if the user guessed correctly
        if (userGuessInt == randomInt) {
            std::cout << "You guessed correctly!" << std::endl;
        } else {
            std::cout << "You guessed incorrectly, the correct answer was "
            << randomInt << std::endl;
        }
    }

    std::cout << "\nThank you for playing!\n";
}
