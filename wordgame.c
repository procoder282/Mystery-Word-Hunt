#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Structure to store each level's word, hints, and fun facts
struct Level {
    char word[50];
    char *hints[5];
    char *funFact;
};

// Function to display the game title
void displayTitle() {
    printf("🎉✨ **Mystery Word Hunt** ✨🎉\n");
}

// Function to play the game
void playGame() {
    // Define levels with meaningful words, hints, and fun facts
    struct Level levels[] = {
        {"cricket", {"Hint 1: It's a popular sport in many countries.",
                     "Hint 2: It involves a bat and a ball.",
                     "Hint 3: It's played in innings.",
                     "Hint 4: The game has formats like Test and T20.",
                     "Hint 5: The World Cup is a major tournament."},
                     "Fun Fact: Cricket is believed to have originated in England in the 16th century."},

        {"football", {"Hint 1: It's known as soccer in some countries.",
                      "Hint 2: It's played on a rectangular field.",
                      "Hint 3: The objective is to score goals.",
                      "Hint 4: It involves kicking a ball.",
                      "Hint 5: The FIFA World Cup is the biggest tournament."},
                      "Fun Fact: Football is the most popular sport in the world."},

        {"love", {"Hint 1: It describes a strong feeling.",
                   "Hint 2: It can be romantic or platonic.",
                   "Hint 3: It's a four-letter word.",
                   "Hint 4: It starts with 'l'.",
                   "Hint 5: It's often associated with heart symbols."},
                   "Fun Fact: The word 'love' has been used in poetry for centuries."},

        {"hope", {"Hint 1: It signifies a feeling of expectation.",
                   "Hint 2: It's often associated with positivity.",
                   "Hint 3: It can be a noun or a verb.",
                   "Hint 4: It has four letters.",
                   "Hint 5: It starts with 'h'."},
                   "Fun Fact: Hope can motivate individuals to overcome challenges."},

        {"cat", {"Hint 1: It's a common household pet.",
                  "Hint 2: It purrs when happy.",
                  "Hint 3: It has whiskers.",
                  "Hint 4: It's often associated with independence.",
                  "Hint 5: It has a strong sense of smell."},
                  "Fun Fact: Cats have been domesticated for thousands of years."},

        {"dog", {"Hint 1: It's known as man's best friend.",
                  "Hint 2: It barks.",
                  "Hint 3: It's often used in therapy.",
                  "Hint 4: They come in various breeds.",
                  "Hint 5: They are known for loyalty."},
                  "Fun Fact: Dogs can learn over a hundred words and commands."},

        {"chair", {"Hint 1: It's a piece of furniture.",
                    "Hint 2: You sit on it.",
                    "Hint 3: It usually has four legs.",
                    "Hint 4: It can be made of wood, metal, or plastic.",
                    "Hint 5: It's often found at a table."},
                    "Fun Fact: The oldest known chair dates back to ancient Egypt."}
    };

    int totalLevels = sizeof(levels) / sizeof(levels[0]);
    int maxAttempts = 5;
    char guess[50];
    char guessedWords[totalLevels][50]; // To store guessed words
    int wordCount = 0;

    printf("🚀 Welcome to the 'Guess the Word' game! 🚀\n");
    printf("📝 Rules of the game:\n");
    printf("1. You will guess the words.\n");
    printf("2. You have 5 attempts to guess each word.\n");
    printf("3. Hints will be provided for each word.\n");
    printf("4. You can skip one word, but you cannot skip more than once.\n");
    printf("5. If you skip, you'll be shown the answer for that word.\n");
    printf("Let's get started!\n");

    // Ask for the word length mode
    int wordLength = 0;
    printf("Do you want to guess words of a specific length? (Enter the length or 0 for no limit): ");
    scanf("%d", &wordLength);
    clearInputBuffer();

    // Loop through each level
    for (int currentLevel = 0; currentLevel < totalLevels; currentLevel++) {
        // Skip the word if it doesn't match the desired length
        if (wordLength > 0 && strlen(levels[currentLevel].word) != wordLength) {
            continue;
        }

        int attempt = 0;
        int wordGuessed = 0;
        bool skipped = false;

        // Provide the initial hint for the word
        printf("\n🗣️ Level %d: You need to guess the word! (Hint: The word has %lu letters)\n", currentLevel + 1, strlen(levels[currentLevel].word));
        
        // Level guessing loop
        while (attempt < maxAttempts && !wordGuessed) {
            printf("🤔 Attempt %d: Enter your guess (or type 'skip' to skip): ", attempt + 1);
            scanf("%49s", guess);
            clearInputBuffer();

            // Check if the user wants to skip
            if (strcmp(guess, "skip") == 0) {
                if (!skipped) {
                    printf("🚫 You have chosen to skip this word! The correct word was: %s\n", levels[currentLevel].word);
                    skipped = true;
                    break;
                } else {
                    printf("🚨 You can only skip one word! Try guessing!\n");
                    continue;
                }
            }

            // Check if the guess is correct
            if (strcmp(guess, levels[currentLevel].word) == 0) {
                wordGuessed = 1;
                strcpy(guessedWords[wordCount], levels[currentLevel].word); // Store guessed word
                wordCount++;
                printf("🎉 Congratulations! You guessed the correct word: %s 🎉\n", levels[currentLevel].word);
                printf("%s\n", levels[currentLevel].funFact); // Display the fun fact
            } else {
                printf("❌ Wrong guess!\n");
                // Provide a hint after each incorrect guess
                printf("%s\n", levels[currentLevel].hints[attempt]);
                attempt++;
            }
        }

        // If the word was not guessed within the attempts
        if (!wordGuessed && !skipped) {
            printf("\n💔 Sorry! You've used all your attempts. The correct word was: %s\n", levels[currentLevel].word);
            printf("Game over!\n");
            return;
        }

        // Notify the user about the next level
        if (currentLevel < totalLevels - 1) {
            printf("\n🌟 You've completed Level %d! Moving on to Level %d... 🌟\n", currentLevel + 1, currentLevel + 2);
        }
    }

    printf("🎊 You've guessed all the words! Thanks for playing! 🎊\n");
}

int main() {
    displayTitle();
    playGame();
    printf("👋 Thanks for playing! See you next time! 👋\n");
    return 0;
}
