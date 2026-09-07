/*a)we can have a num_aces and so for example if with an 11 you go bust we can subtract 10 to make it a 1
yh treat them as 11 and if go bust subtract 10

b) instead of return (player.score > dealer.score);  just have an if statement checking the appropriate conditions
and we cant use a bool as there are three possibilities now. maybe use 0 1 2 as the different states?
*/

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


enum gameOverState
{
    PlayerWin,
    DealerWin,
    Tie,
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
    int aces{};
};


namespace Settings
{
    constexpr int bust_Value {21};
    constexpr int dealer_stop_value{17};
}

void addCard(Player& player, Card& card)
{
    /*
    if card is an ace we increment player ace counter
    we add card score to player score

    if player busts check number of aces left and if greater than 1 we decrease score by 10 and reduce ace count
    */
    if (card.rank == Card::rank_ace)
    {
        player.aces++;
    }

    player.score += card.getValue();

    if (player.score > Settings::bust_Value)
    {
        if(player.aces > 1)
        {
            player.score -= 10;
            player.aces--;
        }
    }
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

gameOverState blackjack()
{
//shuffle deck, 
//pick first two for player, next for dealer
    Deck deck{};
    deck.shuffle();

    Player dealer{};
    Player player{};
    
    Card playercard1 = deck.dealCard();
    Card playercard2 = deck.dealCard();
    Card dealercard = deck.dealCard();

    player.score += (playercard1.getValue());
    player.score += (playercard2.getValue());
    dealer.score += (dealercard.getValue());

    std::cout << "The dealer is showing: " << dealercard << " (" << dealer.score << ")\n"; 

    std::cout << "You are showing: "<< playercard1 <<  " " << playercard2  << " (" << player.score << ")\n"; 

    if (playerTurn(player,deck))
    {
        return DealerWin; 
    }
    if(dealerTurn(dealer,deck))
    {
        return PlayerWin;
    }

    if (player.score == dealer.score)
    {
        return Tie;
    }  
    else if (player.score > dealer.score)
    {
        return PlayerWin;
    }
    else 
    {
        return DealerWin;
    }
}
int main()
{
    gameOverState game= blackjack();
    if(game == Tie)
    {
        std::cout << "Draw\n";
    }
    else if(game == PlayerWin)
    {
        std::cout << "You win \n";
    }
    else {
        std::cout << "You lose \n";
    }
    
}