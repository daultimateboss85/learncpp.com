#include <iostream>
#include <array>
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

        std::cout << m_cards.size() << "\n";
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


int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}