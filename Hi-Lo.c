#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Adding a banking system and a steak counter which increases the money gained by:
 * 1.2 * BET * (STEAK / 2)
 */


enum GameState { WON, LOST };

int cardGenerator(void);
enum GameState gameStateH(int, int);
enum GameState gameStateL(int, int);
void printMessage(enum GameState, int);

int main() { 
  srand(time(NULL));
  int card = 0;
  int nextCard = 0;
  char prediction;
  enum GameState state;

  card = cardGenerator();
  nextCard = cardGenerator();

  printf("%s%d\n", "The card is: ", card);

  printf("%s", "Do you think the next card will be higher(h) or lower (l)? ");
  scanf(" %c", &prediction);

  if ('h' == prediction) 
    state = gameStateH(card, nextCard);
  else if ('l' == prediction)
    state = gameStateL(card, nextCard);

  printMessage(state, nextCard);

  return 0;
}

/**
 * @brief Card generation
 * @return Generated card
 */
int cardGenerator(void) {
  int card = 0;

  card = 1 + (rand() % 13);

  return card;
}

/**
 * @brief Checks win and lose condition based on lower prediction
 * @param card Number of current card
 * @param nextCard Number of next card
 * @return Game state
 */
enum GameState gameStateH(int card, int nextCard) {
  enum GameState state; 

  if (card < nextCard) 
    state = WON;
  else if (card >= nextCard)
    state = LOST;

  return state;
}

/**
 * @brief Checks win and lose condition based on lower prediction
 * @param card Number of current card
 * @param nextCard Number of next card
 * @return Game state
 */
enum GameState gameStateL(int card, int nextCard) {
  enum GameState state;

  if (card <= nextCard) 
    state = LOST;
  else if (card > nextCard)
    state = WON;

  return state;
}

void printMessage(enum GameState state, int nextCard) {

  if (WON == state) 
    printf("%s%d\n", "You Won! Next drawn card is: ", nextCard);
  else if (LOST == state)
    printf("%s%d\n", "You Lost! Next drawn card is: ", nextCard);
}










