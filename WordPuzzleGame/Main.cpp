#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {

	enum fields { WORD, HINT, NUM_FIELDS };

	/* List of words and hints */
	const int NUM_WORDS = 21;
	const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {

		{"computer", "Electronic device for processing data"},
		{"television", "Device for watching programs"},
		{"calendar", "Tool for tracking datesand events"},
		{"backpack", "Bag worn on the back"},
		{"telephone", "Device for making calls"},
		{"sunglasses", "Eyewear for blocking the sun"},
		{"umbrella", "Tool for staying dry in the rain"},
		{"coffee", "A popular hot beverage made from roasted coffee beans"},
		{"shower", "A device used for bathing that sprays water onto the body"},
		{"bicycle", "A human-powered vehicle with two wheels and pedals"},
		{"traffic", "The movement of vehicles on a road or highway"},
		{"homework", "Assignments given to students to be completed outside of class time"},
		{"jacket", "A type of clothing worn on the upper body for warmth or protection"},
		{"airport", "A location where airplanes take off and land, usually with facilities for passengers to boardand disembark"},
		{"sandwich", "A type of food made by placing ingredients between two slices of bread"},
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer"},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it"},
		{"jumble", "It's what the game is all about"},
		{"library", "Place to borrow books"},

	};

	char again = 'y';
	int score = 0;

	/* Welcome */
	std::cout << "Welcome to Word Puzzle \n" << std::endl;
	std::cout << "Unscramble the letters to make a word" << std::endl;
	std::cout << "Enter 'hint' for a hint" << std::endl;
	std::cout << "Enter 'quit' to quit the game" << std::endl;

	/* Game loop */
	do {

		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		std::string theWord = WORDS[choice][WORD];
		std::string theHint = WORDS[choice][HINT];

		/* Mixing up the word */
		std::string mixUp = theWord;
		int length = mixUp.size();

		for (int i = 0; i < length; ++i) {
			int index1 = (rand() % length);
			int index2 = (rand() % length);

			char temp = mixUp[index1];
			mixUp[index1] = mixUp[index2];
			mixUp[index2] = temp;

		}

		std::cout << "\n The mixed-up word is: " << mixUp << std::endl;

		std::string guess;
		std::cout << "Your guess: ";
		std::cin >> guess;

		/* Using hint or quit the game */
		while ((guess != theWord) && (guess != "quit")) {

			if (guess == "hint") {

				/* Decrease the score if the player used hint */
				score--;

				std::cout << theHint << std::endl;
				std::cout << std::endl;
			}
			else {
				std::cout << "Sorry, that's not it" << std::endl;
			}

			std::cout << "Your guess: ";
			std::cin >> guess;

		}

		/* Guessed the word and playing again */
		if (guess == theWord) {

			std::cout << "That's it! You guessed it! \n" << std::endl;

			/* Increase score in each round if the player guessed the word */
			score++;
			std::cout << "Your score: " << score << std::endl;

			std::cout << "Would you like to play again? Y/N" << std::endl;
			std::cin >> again;

		}

	} while (again == 'y');

	std::cout << "Thanks for playing" << std::endl;

	return 0;
}