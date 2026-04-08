#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_LIVES = 7;

string getRandomWord()
{
    vector<string> words = {
        // Animals
        "elephant", "giraffe", "dolphin", "penguin", "cheetah",
        "crocodile", "kangaroo", "leopard", "flamingo", "gorilla",

        // Countries
        "pakistan", "germany", "australia", "argentina", "portugal",
        "malaysia", "ethiopia", "indonesia", "switzerland", "bangladesh",

        // Programming Terms
        "algorithm", "compiler", "recursion", "variable", "function",
        "iterator", "polymorphism", "inheritance", "debugging", "array",

        // Fruits & Vegetables
        "watermelon", "pineapple", "strawberry", "blueberry", "cucumber",
        "avocado", "broccoli", "mango", "pomegranate", "spinach",

        // Sports
        "cricket", "football", "swimming", "badminton", "volleyball",
        "basketball", "wrestling", "gymnastics", "hockey", "archery"
    };

    return words[rand() % words.size()];
}

void drawHangman(int lives)
{
    switch (lives)
    {
    case 6:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    case 5:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |      O" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    case 4:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |      O" << endl;
        cout << " |      |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    case 3:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |      O" << endl;
        cout << " |     /|" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    case 2:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |      O" << endl;
        cout << " |     /|\\" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    case 1:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |      O" << endl;
        cout << " |     /|\\" << endl;
        cout << " |     /" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    case 0:
        cout << " --------" << endl;
        cout << " |      |" << endl;
        cout << " |      O" << endl;
        cout << " |     /|\\" << endl;
        cout << " |     / \\" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    default:
        cout << " --------" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "__" << endl;
        break;
    }
}

int main()
{
    // Seed random number generator once at program start
    srand(static_cast<unsigned int>(time(0)));

    string word_to_guess = getRandomWord();
    vector<char> guessed_letters;
    int lives = MAX_LIVES;

    // Pick one fixed hint letter at the start
    char hintLetter = toupper(word_to_guess[rand() % word_to_guess.length()]);

    // Initialize the display string with underscores
    string display_word(word_to_guess.length(), '_');

    cout << "=============================" << endl;
    cout << "     Welcome to Hangman!     " << endl;
    cout << "=============================" << endl;
    cout << "Hint: The word contains the letter '" << hintLetter << "'" << endl;

    while (lives > 0 && display_word != word_to_guess)
    {
        drawHangman(lives);
        cout << "\nLives remaining: " << lives << endl;

        cout << "Guessed letters: ";
        for (char letter : guessed_letters)
            cout << letter << " ";
        cout << endl;

        cout << "Word: " << display_word << endl;

        // Get input
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        // Validate input - letters only
        if (!isalpha(guess))
        {
            cout << "Invalid input. Please enter a letter only." << endl;
            continue;
        }

        guess = toupper(guess);

        // Check if already guessed
        if (find(guessed_letters.begin(), guessed_letters.end(), guess) != guessed_letters.end())
        {
            cout << "You already guessed that letter. Try again." << endl;
            continue;
        }

        guessed_letters.push_back(guess);

        // Check if guess is correct
        bool correct_guess = false;
        for (int i = 0; i < (int)word_to_guess.length(); ++i)
        {
            if (toupper(word_to_guess[i]) == guess)
            {
                display_word[i] = word_to_guess[i];
                correct_guess = true;
            }
        }

        if (!correct_guess)
        {
            lives--;
            cout << "Incorrect guess!" << endl;
        }
        else
        {
            cout << "Good guess!" << endl;
        }
    }

    // Game over
    if (lives == 0)
    {
        drawHangman(0);
        cout << "\nGame Over! The word was: " << word_to_guess << endl;
    }
    else
    {
        cout << "\nCongratulations! You guessed the word: " << word_to_guess << endl;
    }

    return 0;
}
