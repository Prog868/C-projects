#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[]);

int main() {
  // initialising the array deck
  int deck[SUITS][FACES] = {0};

  srand(time(NULL));
  shuffle(deck);

  // initialisng the array suit
  const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

  // initialising the array face
  const char *face[FACES] = {"Ace",  "Deuce", "Three", "Four", "Five",
                             "Six",  "Seven", "Eight", "Nine", "Ten",
                             "Jack", "Queen", "King"};

  deal(deck, face, suit);
}

/**
 * @brief Shuffles the cards
 * @param deck is a 2D array
 */
void shuffle(int deck[][FACES]) {
  for (size_t card = 1; card <= CARDS; card++) {
    size_t row = 0;
    size_t column = 0;

    // search for an empty space in the 2D array 
    // if it is 0 than it places the card in the array
    do {
      row = rand() % SUITS;
      column = rand() % FACES;
    } while (deck[row][column] != 0);

    deck[row][column] = card;
  }
}

/**
  * @brief Deals the cards
  * @param deck 2D array
  * @param face array of pointers containing the card number
  * @param suit array of pointers containing the card suit
  */
void deal(int deck[][FACES], const char *face[], const char *suit[]) {
  // untill all cards have been displayed
  for (size_t card = 1; card <= CARDS; card++) {
    // untill all rows have been searched
    for (size_t row = 0; row < SUITS; row++) {
      // untill all columns have been searched
      for (size_t column = 0; column < FACES; column++) {
        // if the element contains the current card print it 
        if (deck[row][column] == card)
          printf("%5s of %-8s ", face[column], suit[row]);
      }
    }
  }
  puts("");
}
