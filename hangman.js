// hangman.js
let word = "programming";  // In real usage, this would come from the C backend
let attempts = 6;
let guessedLetters = [];
let correctGuesses = 0;

function updateWordDisplay() {
    let display = "";
    for (let i = 0; i < word.length; i++) {
        display += (guessedLetters.includes(word[i]) ? word[i] : "_") + " ";
    }
    document.getElementById("word-container").textContent = display.trim();
}

function makeGuess() {
    const guess = document.getElementById("guess").value.toLowerCase();
    document.getElementById("guess").value = "";

    if (!guess || guessedLetters.includes(guess)) {
        return;
    }

    guessedLetters.push(guess);

    if (word.includes(guess)) {
        correctGuesses++;
        updateWordDisplay();
    } else {
        attempts--;
        document.getElementById("attempts").textContent = attempts;
        document.getElementById("message").textContent = "Incorrect guess! Try again.";
    }

    document.getElementById("guessed-letters").textContent = "Guessed Letters: " + guessedLetters.join(", ");

    if (correctGuesses === word.length) {
        document.getElementById("message").textContent = "Congratulations! You guessed the word!";
    } else if (attempts === 0) {
        document.getElementById("message").textContent = "Game Over! The word was: " + word;
    }
}

updateWordDisplay();
