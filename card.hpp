enum Suit{
    heart = 0,
    diamond = 1,   
    club = 2,
    spade = 3
};

enum Value{
    Ace = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,
    queen = 12,
    king = 13
};

class Card {
    private:
        Value value;
        Suit suit;
    public:

        void printCard(Card card){
            //TODO
        }
        
        void setValue(Value value){
            value = value;
            //TODO
        }

        void setSuit(Suit suit){
            //TODO
        }

        Value getValue(){
            return value;
            //TODO
        }
        Suit getSuit(){
            //TODO
        }


};