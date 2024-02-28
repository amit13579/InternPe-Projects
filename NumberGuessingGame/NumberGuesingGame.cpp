#include <iostream>
#include <cstdlib>
#include <ctime>

class GuessingNumberGame {
public:
    static void playGame() {
        int minRange = 1;
        int maxRange = 100;
        int totalRounds = 3;
        int maxAttemptsPerRound = 15;
        int totalAttempts = 0;
        int totalScore = 0;
        std::cout << "      -----------------------";
        std::cout << "Welcome to the Number Guessing Game!";
        std::cout << "-----------------------\n";
        for (int round = 1; round <= totalRounds; round++) {
            int targetNumber = generateRandomNumber(minRange, maxRange);
            int attempts = 0;
            std::cout << "\nRound " << round << ": Guess the number between " << minRange << " and " << maxRange << "\n";
            while (attempts < maxAttemptsPerRound) {
                std::cout << "Attempts remaining: " << (maxAttemptsPerRound - attempts)
                          << ", Maximum attempts per round: " << maxAttemptsPerRound << "\n";
                std::cout << "Enter your guess: ";
                int userGuess;
                std::cin >> userGuess;
                attempts++;
                totalAttempts++;                if (userGuess == targetNumber) {
                    int roundScore = calculateScore(attempts, round, maxAttemptsPerRound);
                    totalScore += roundScore;
                    std::cout << "      -----------------------\n";
                    std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
                    std::cout << "-----------------------\n";
                    std::cout << "Round " << round << " Score: " << roundScore << " points\n";
                    break;
                } else if (userGuess < targetNumber) {
                    std::cout << "Too low. Enter the greater Number.\n";
                } else {
                    std::cout << "Too high. Enter the smaller number.\n";
                }
            }
            if (attempts == maxAttemptsPerRound) {
                std::cout << "Sorry, you've reached the maximum number of attempts for this round.\n";
            }
        }
        std::cout << "\nGame Over! Your total score is: " << totalScore << " points in " << totalAttempts << " attempts.\n";
    }

    static int generateRandomNumber(int min, int max) {
        static bool first = true;
        if (first) {
            srand(static_cast<unsigned int>(time(nullptr)));
            first = false;
        }
        return rand() % (max - min + 1) + min;
    }

    static int calculateScore(int attempts, int round, int maxAttempts) {
        return (10 - attempts) * round + (5 * maxAttempts);
    }
};

int main() {
    GuessingNumberGame::playGame();
    return 0;
}


