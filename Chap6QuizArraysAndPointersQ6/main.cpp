#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

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
    int value {0};

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
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand(); // To remove junk first value

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

    printDeck(deck);

    shuffleDeck(deck);

    printDeck(deck);

    std::cout << getCardValue(deck.at(9));

    return 0;
}










