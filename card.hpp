enum Suit{
    heart,
    diamond,   
    club,
    spade
};

enum Value{
    ace = 'A',
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 'J',
    queen = 'Q',
    king = 'K'
};

class Card {
    private:
        Value value;
        Suit suit;
    public:

        Card(Suit s, Value val){
            //add sanity checks later
            suit = s;
            value = val;        
        }

        Value getValue(){
            return value;
            //TODO
        }
        Suit getSuit(){
            return suit;
            //TODO
        }

        void printCard(){
            Value val = value;
            Suit s = suit;
            std::cout << ".-----."<< std::endl;
            std::cout << "|" << val << "    |" <<std::endl;
            std::cout << "|  " << s << "  |" << std::endl;
            std::cout << "|    " <<val<<"|" << std::endl;
            std::cout << "'-----'" << std::endl;
        }



};