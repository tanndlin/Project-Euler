// https://projecteuler.net/problem=54

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GAMES 1000
#define FACES 13
#define SUITS 4

typedef struct {
    char value;
    char suit;
} Card;

typedef struct {
    Card cards[5];
    int facesInHand[FACES];
    int suitsInHand[SUITS];
    int eval[10];
} Hand;

typedef struct {
    Hand hand1;
    Hand hand2;
} Game;

void loadData(Game *);
void assessHand(Hand *);
void evalHand(Hand *);
void printHand(Hand);
void printGame(Game);
bool compareHands(Game);
bool handleTie(Hand, Hand);
int getHighestCard(Hand, int);

int main() {
    srand(time(0));

    Game games[NUM_GAMES];
    loadData(games);

    int total = 0;
    for (int i = 0; i < NUM_GAMES; i++) {
        bool winner = compareHands(games[i]);
        if (winner)
            total++;
    }

    printf("Player 1 won: %d times,\n", total);
    return 0;
}

void loadData(Game *games) {
    FILE *fp = fopen("p054_poker.txt", "r");
    char data[32];

    for (int gameNum = 0; gameNum < NUM_GAMES; gameNum++) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%s", &data);
            games[gameNum].hand1.cards[i].value = data[0];
            games[gameNum].hand1.cards[i].suit = data[1];
        }
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%s", &data);
            games[gameNum].hand2.cards[i].value = data[0];
            games[gameNum].hand2.cards[i].suit = data[1];
        }

        assessHand(&games[gameNum].hand1);
        assessHand(&games[gameNum].hand2);
        evalHand(&games[gameNum].hand1);
        evalHand(&games[gameNum].hand2);
    }

    fclose(fp);
}

void assessHand(Hand *hand) {
    for (int i = 0; i < FACES; i++)
        hand->facesInHand[i] = 0;
    for (int i = 0; i < SUITS; i++)
        hand->suitsInHand[i] = 0;

    for (int i = 0; i < 5; i++) {
        Card card = hand->cards[i];
        switch (card.suit) {
        case 'H':
            hand->suitsInHand[0]++;
            break;
        case 'D':
            hand->suitsInHand[1]++;
            break;
        case 'S':
            hand->suitsInHand[2]++;
            break;
        case 'C':
            hand->suitsInHand[3]++;
            break;
        }

        // printf("%c %d\n", card.value, card.value - '0' - 2);
        if (card.value - '0' < 10) {
            hand->facesInHand[card.value - '0' - 2]++;
        } else {
            switch (card.value) {
            case 'T':
                hand->facesInHand[8]++;
                break;
            case 'J':
                hand->facesInHand[9]++;
                break;
            case 'Q':
                hand->facesInHand[10]++;
                break;
            case 'K':
                hand->facesInHand[11]++;
                break;
            case 'A':
                hand->facesInHand[12]++;
                break;
            }
        }
    }
}

void evalHand(Hand *hand) {

    bool royalStraight = false, straight = false, flush = false, four = false,
         three = false;
    int pairs = 0;

    // Royal straight
    int rank = 8;
    while (hand->facesInHand[rank])
        rank++;

    royalStraight = rank == 13;

    // Straight
    rank = 0;
    while (!hand->facesInHand[rank])
        rank++;

    int numConsec = 0;
    for (; hand->facesInHand[rank]; rank++)
        numConsec++;

    if (numConsec == 5)
        straight = true;

    // Flush
    for (int i = 0; i < SUITS; i++)
        if (hand->facesInHand[i] == 5)
            flush = true;

    for (int i = 0; i < FACES; i++) {
        if (hand->facesInHand[i] == 4)
            four = true;
        if (hand->facesInHand[i] == 3)
            three = true;
        if (hand->facesInHand[i] == 2)
            pairs++;
    }
    hand->eval[0] = royalStraight && flush;
    hand->eval[1] = straight && flush;
    hand->eval[2] = four;
    hand->eval[3] = three && pairs == 1;
    hand->eval[4] = flush;
    hand->eval[5] = straight;
    hand->eval[6] = three;
    hand->eval[7] = pairs == 2;
    hand->eval[8] = pairs == 1;
    hand->eval[9] = true;
}

void printHand(Hand hand) {
    for (int i = 0; i < 5; i++)
        printf("%c%c ", hand.cards[i].value, hand.cards[i].suit);
    printf("\nSuits: ");

    for (int i = 0; i < SUITS; i++)
        printf("%d ", hand.suitsInHand[i]);
    printf("\nFaces: ");

    for (int i = 0; i < FACES; i++)
        printf("%d ", hand.facesInHand[i]);
    printf("\nEval: ");

    for (int i = 0; i < 10; i++)
        printf("%d ", hand.eval[i]);

    printf("\n");
}

void printGame(Game game) {
    printHand(game.hand1);
    printHand(game.hand2);
    printf("\n");
}

bool compareHands(Game game) {
    Hand a = game.hand1;
    Hand b = game.hand2;

    for (int i = 0; i < 10; i++) {
        if (a.eval[i] || b.eval[i]) {

            if (a.eval[i] && !b.eval[i])
                return true;
            else if (b.eval[i] && !a.eval[i])
                return false;
            else
                return handleTie(a, b);
        }
    }
}

bool handleTie(Hand a, Hand b) {

    int winningCondition = 0;
    while (!a.eval[winningCondition])
        winningCondition++;

    if (winningCondition == 0) {
        printf("That shouldn't have happened!");
    }
    if ((winningCondition > 0 && winningCondition <= 5) ||
        winningCondition == 9)
        return getHighestCard(a, 1) > getHighestCard(b, 1);

    if (winningCondition == 6)
        return getHighestCard(a, 3) > getHighestCard(b, 3);

    if (winningCondition == 7 || winningCondition == 8)
        return getHighestCard(a, 2) > getHighestCard(b, 2);

    return false;
}

int getHighestCard(Hand hand, int target) {
    int highestCard;

    for (int i = FACES - 1; i >= 0; i--) {
        if (hand.facesInHand[i] == target) {
            highestCard = i;
            break;
        }
    }
}
