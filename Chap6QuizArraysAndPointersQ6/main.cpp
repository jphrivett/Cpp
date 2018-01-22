#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
enum class Outcome
{
    WIN,
    LOSE,
    TIE
};

enum class CardRank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    MAX_RANK
};

enum class CardSuit
{
    CLUB,
    DIAMOND,
    HEART,
    SPADE,
    MAX_SUIT
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card)
{

    switch (card.rank)
    {
        case CardRank::TWO:       std::cout << '2'; break;
        case CardRank::THREE:       std::cout << '3'; break;
        case CardRank::FOUR:       std::cout << '4'; break;
        case CardRank::FIVE:       std::cout << '5'; break;
        case CardRank::SIX:       std::cout << '6'; break;
        case CardRank::SEVEN:       std::cout << '7'; break;
        case CardRank::EIGHT:       std::cout << '8'; break;
        case CardRank::NINE:       std::cout << '9'; break;
        case CardRank::TEN:       std::cout << 'T'; break;
        case CardRank::JACK:       std::cout << 'J'; break;
        case CardRank::QUEEN:       std::cout << 'Q'; break;
        case CardRank::KING:       std::cout << 'K'; break;
        case CardRank::ACE:       std::cout << 'A'; break;
    }

    switch (card.suit)
    {
        case CardSuit::CLUB:        std::cout << 'C'; break;
        case CardSuit::DIAMOND:        std::cout << 'D'; break;
        case CardSuit::HEART:        std::cout << 'H'; break;
        case CardSuit::SPADE:        std::cout << 'S'; break;
    }

}

void printDeck(const std::array<Card,52> &deck)
{
    int i {0};

    for (const Card &card : deck)
    {
         printCard(card);
         std::cout << ' ';
         ++i;
         if (i % 10 == 0)
            std::cout << '\n';

    }

    std::cout << "\n\n";
}

void swapCard(Card &card1, Card &card2)
{
    Card temp = card1;

    card1 = card2;
    card2 = temp;
    }

void shuffleDeck(std::array<Card,52> &deck)
{

    for (int i = 0; i < 52; ++i)
    {
        static const double frac = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
        //Get random number between 0 and 51:
        int irand = 0 + static_cast<int>(52*rand()*frac);

        swapCard(deck.at(i),deck.at(irand));
    }

}

int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case CardRank::TWO:       return 2;
        case CardRank::THREE:       return 3;
        case CardRank::FOUR:       return 4;
        case CardRank::FIVE:       return 5;
        case CardRank::SIX:       return 6;
        case CardRank::SEVEN:       return 7;
        case CardRank::EIGHT:       return 8;
        case CardRank::NINE:       return 9;
        case CardRank::TEN:       return 10;
        case CardRank::JACK:       return 10;
        case CardRank::QUEEN:       return 10;
        case CardRank::KING:       return 10;
        case CardRank::ACE:       return 11;
    }

    return 0;
}

//Not a good idea to have these functions changing the score and card.
//As shown on the website:
//http://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/comment-page-5/#comment-315505
//it is better to have these as constants and increase the pointer value/card
//number in the function call itself and then use the output of the function to
//add to the score. As in:
//playerTotal += getCardValue(*cardPtr++);
//After the pointer parameter has been passed into the function, it increments
//the card number.
void playerDraw(int &playerScore, Card *cards, int &card, int &playerAces)
{
    std::cout << "The player draws ";
    printCard(cards[card]);
    std::cout << '\n';
    playerScore += getCardValue(cards[card]);
    std::cout << "The player's score is " << playerScore << '\n';
    if (cards[card].rank == CardRank::ACE)
        ++playerAces;
    ++card;
}

void dealerDraw(int &dealerScore, Card *cards, int &card, int &dealerAces)
{
    std::cout << "The dealer draws ";
    printCard(cards[card]);
    std::cout << '\n';
    dealerScore += getCardValue(cards[card]);
    std::cout << "The dealers's score is " << dealerScore << '\n';
    if (cards[card].rank == CardRank::ACE)
        ++dealerAces;
    ++card;
}

Outcome playBlackjack(std::array<Card,52> &deck)
{
    int card = 0;
    Card *cards = &deck[card];
    int playerScore = 0;
    int dealerScore = 0;
    int playerAces = 0;
    int dealerAces = 0;


    dealerDraw(dealerScore, cards, card, dealerAces);
    playerDraw(playerScore, cards, card, playerAces);
    playerDraw(playerScore, cards, card, playerAces);

    std::cout << "Draw again? (y/n) \n";
    char drawAgain = 0;
    std::cin >> drawAgain;

    while (drawAgain == 'y')
    {
        playerDraw(playerScore, cards, card, playerAces);
        while (playerScore > 21)
        {
            if (playerAces-- > 0)
            {
                playerScore -= 10;
                std::cout << "Taking ace = 1, the player's score is "
                          << playerScore << '\n';
            }
            else
            {
                return Outcome::LOSE;
            }

        }
        std::cout << "Draw again? (y/n) \n";
        std::cin >> drawAgain;
    }

    while (dealerScore < 17)
    {
        dealerDraw(dealerScore, cards, card, dealerAces);
        while (dealerScore > 21)
        {
            if (dealerAces-- > 0)
            {
                dealerScore -= 10;
                std::cout << "Taking ace = 1, the dealers's score is "
                          << dealerScore << '\n';
            }
            else
            {
                return Outcome::WIN;
            }

        }

    }

    //if (playerScore > dealerScore)
    //    return 1;
    //else
    //    return 0;

    //Can write this more efficiently simply as:
    //return (playerScore > dealerScore);

    //Including ties:
    if (playerScore > dealerScore)
        return Outcome::WIN;
    else if (playerScore < dealerScore)
        return Outcome::LOSE;
    else
        return Outcome::TIE;

}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand(); // To remove junk first value

    //Instantiate and assign the cards in the deck:
    std::array<Card,52> deck;
    int card {0};
    for (int irank = 0; irank < static_cast<int>(CardRank::MAX_RANK); ++irank)
    {
        for (int isuit = 0; isuit < static_cast<int>(CardSuit::MAX_SUIT); ++isuit)
        {
            deck.at(card).rank = static_cast<CardRank>(irank);
            deck.at(card).suit = static_cast<CardSuit>(isuit);
            ++card;
        }
    }

    shuffleDeck(deck);
    Outcome outcome = playBlackjack(deck);
    if (outcome == Outcome::WIN)
        std::cout << "You win!";
    else if (outcome == Outcome::LOSE)
        std::cout << "You lose!";
    else if (outcome == Outcome::TIE)
        std::cout << "You tie!";

    //if (playBlackjack(deck))
    //    std::cout << "You win!";
    //else
    //    std::cout << "You lose!";

    return 0;
}










