#include <ios>
#include <iostream>
#include <array>
#include <limits>
#include <vector>
#include <algorithm>
#include "..\..\headers\Random.h"
#include <cassert>

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    // We'll also prefix these for consistency
    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };
    static constexpr std::array allRanks{rank_ace, rank_2, rank_3, rank_4, rank_5 ,rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
    static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart, suit_spade};
    
    static_assert(max_ranks == std::size(allRanks));
    static_assert(max_suits == std::size(allSuits));
    
    static constexpr std::array letters{'A', '2', '3', '4', '5', '6', '7', '8','9','T', 'J', 'Q', 'K'};
    static constexpr std::array values{11, 2,3,4,5,6,7,8,9,10,10,10,10};

    static_assert(max_ranks == std::size(letters));
    static_assert(max_ranks == std::size(values));

    static constexpr std::array suits{'C', 'D', 'H', 'S'};
    static_assert(max_suits == std::size(suits));

    Rank rank{};
    Suit suit{}; 

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        out << letters[card.rank] << suits[card.suit];
        return out;
    }

    int getValue() const
    {
        return values[rank];
    }

};

class Deck
{
std::vector<Card> m_cards{};
int m_current_card{0};
public:
    Deck()
    {
        for (auto suit: Card::allSuits)
        {
            for (auto rank: Card::allRanks)
            {
                m_cards.push_back(Card{rank, suit});
            }
        }

    }

    Card dealCard()
    {
        assert(m_current_card!=51);
       
        return m_cards[m_current_card++];
    }

    void shuffle()
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_current_card = 0;
    }
};

struct Player
{
    int score{};
};


namespace Settings
{
    constexpr int bust_Value {21};
    constexpr int dealer_stop_value{17};
}

bool dealerTurn(Player& dealer, Deck& deck)
{
    while (dealer.score < Settings::dealer_stop_value)
    {
        Card dealer_card{deck.dealCard()};

        dealer.score += dealer_card.getValue();

        std::cout << "The dealer flips a " << dealer_card << ". They now have: " << dealer.score << "\n";

        if (dealer.score > Settings::bust_Value)
        {
            return true;
        } 
    }
    return false;
};

char getInput()
{   
    char input{};
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> input;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad input. Try again: \n";
            continue;
        }

        if (!std::cin.eof() && std::cin.peek()!='\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Too much input. Try again: \n";
            continue;
        }

        if (input != 's' && input != 'h')
        {
            std::cout << "Choose appropriately. Try again\n: ";
            continue;
        }

        return input;
    }
}
bool playerTurn (Player& player, Deck & deck)
{
    //returns true if player busts false otherwise or if stands
    while (player.score < Settings::bust_Value)
    {
        char option {getInput()};

        if (option=='h')
        {
            Card card {deck.dealCard()};
            player.score += card.getValue();
            std::cout << "You were dealt " << card << ". You now have: " << player.score << "\n";

            if (player.score > Settings::bust_Value)
            {
                return true;
            }
        }
        else 
        {
            return false;
        }
    }
    if(player.score > Settings::bust_Value)
    {
        return true;
    }
    else 
    {
        return false; //he didnt bust
    }
    
};

bool blackjack()
{
//shuffle deck, 
//pick first two for player, next for dealer
    Deck deck{};
    deck.shuffle();

    Player dealer{};
    Player player{};
    
    player.score += (deck.dealCard().getValue());
    player.score += (deck.dealCard().getValue());
    dealer.score += (deck.dealCard().getValue());

    std::cout << "The dealer is showing: " << dealer.score << "\n"; 
    std::cout << "You have score: " << player.score << "\n"; 
    if (playerTurn(player,deck))
    {
        return false; 
    }
    if(dealerTurn(dealer,deck))
    {
        return true;
    }

    return (player.score > dealer.score);   
}
int main()
{
 
    if(blackjack())
    {
        std::cout << "You win\n";
    }
    else 
    {
        std::cout << "You lose \n";
    }
    
}