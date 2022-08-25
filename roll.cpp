/*
scrap this, this is shit
i wanna use something more functional, OOP makes me sad
this is a SIMPLE application:

DiceOutput is a struct with a list of rolls, the modifier and the answer
print is a function that prints the data of the DiceOutput

the main function should handle the 
*/



#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>

class Dice {
public:
    int n, d, a;
    std::vector<int> rolls;

    Dice(int sides) {
        this->d = sides;
    }

    Dice count(int n) {
        this->n = n;
        return *this;
    }

    Dice add(int a) {
        this->a = a;
        return *this;
    }

    int roll() {
        for (int i = 0; i < this->rolls.size(); i++) {
            this->rolls.push_back(rand() % this->d + 1);
        }
        return 1;
    }

    void print() {
    }
};

int main() {
    srand(clock());
    return 0;
}