#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum GameState { WON, LOST, CONTINUE };

int cardGenerator(void);
int houseCards(void);
bool isGameOver(enum GameState);
enum GameState gameState(int, int, char);

int main() {
  enum GameState state = CONTINUE;
  srand(time(NULL));
  int sum = 0, card = 0;
  bool endGame = false;
  int house = houseCards();

  while (!endGame) {
    char selection;

    puts("Would you like to draw a card? (Y/n)");
    scanf(" %c", &selection);

    if ('n' == selection) {
      state = gameState(sum, house, selection);
      endGame = isGameOver(state);
      break;
    }

    if ('y' == selection) {

      card = cardGenerator();

      if (1 == card && (sum + 10) <= 21)
        card = 11;

      sum += card;

      printf("\n%s%d\n", "The card number is: ", sum);
    }

    if (sum > 21) {
      printf("\n%s%d\n", "Out of bounds!\nYou scored: ", sum);
      break;
    }
  }
  return 0;
}

/**
 * @brief Card generation
 * @return Card points
 */
int cardGenerator(void) {
  int cardNumber = 0;

  cardNumber = 1 + (rand() % 13);

  if (cardNumber >= 10) {
    return 10;
  } else {
    return cardNumber;
  }
}

/**
 * @brief Checks gameState
 * @param state Enumeration of all possible states
 * @return Whether the game has ended or not
 */
bool isGameOver(enum GameState state) {
  bool gameOver = false;

  switch (state) {
  case LOST:
  case WON:
    gameOver = true;
    break;

  case CONTINUE:
    gameOver = false;
    break;
  } // end switch

  return gameOver;
}

/**
 * @brief Checks whether you lost or won
 * @param sum Total sum of points
 * @return Game state
 */
enum GameState gameState(int sum, int house, char selection) {
  enum GameState state;

  if (house > 21) {
    printf("%s%d\n", "You won! House has got ", house);
    state = WON;
  } else if (house >= sum) {
    printf("%s%d\n", "You lost! The house scored: ", house);
    state = LOST;
  } else if (house < sum && 21 == sum) {
    printf("%s\n", "You won by scoring the highest possible points!");
    state = WON;
  } else if (house < sum) {
    printf("%s%d\n", "You won! The house scored: ", house);
    state = WON;
  } else
    state = CONTINUE;

  return state;
}

/**
 * @brief Generates house cards until sum < 18
 * @return Sum of cards
 */
int houseCards(void) {
  int sum = 0;

  while (sum < 17) {
    sum += cardGenerator();
  }

  return sum;
}
