// hangman.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to return a random word from a predefined list
const char* get_random_word() {
    static const char *words[] = {
        "programming", "javascript", "hangman", "computer", "developer"
    };
    int random_index = rand() % 5;  // Get a random index
    return words[random_index];
}

// Function to check if the guess is correct
int check_guess(const char* word, char guess) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess) {
            return 1;  // Correct guess
        }
    }
    return 0;  // Incorrect guess
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Get random word
    const char* word = get_random_word();
    printf("Random word selected: %s\n", word);  // This will be hidden in production

    // Start the game loop (can be extended with logic to send data to a server)
    char guess;
    int attempts = 6;  // Number of allowed wrong attempts
    int correct_guesses = 0;

    while (attempts > 0) {
        printf("\nEnter your guess (single letter): ");
        scanf(" %c", &guess);

        if (check_guess(word, guess)) {
            printf("Correct guess!\n");
            correct_guesses++;
        } else {
            attempts--;
            printf("Incorrect guess! You have %d attempts left.\n", attempts);
        }

        if (correct_guesses == strlen(word)) {
            printf("Congratulations! You've guessed the word: %s\n", word);
            break;
        }
    }

    if (attempts == 0) {
        printf("Game over! The word was: %s\n", word);
    }

    return 0;
}
