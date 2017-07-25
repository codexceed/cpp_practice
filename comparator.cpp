#include <iostream>
#include <vector>
using namespace std;

struct Player{
    string name;
    int score;
};

void structSwap(Player& pl1, Player& pl2){
    Player temp;
    temp = pl1;
    pl1 = pl2;
    pl2 = temp;
}

int main(){
    Player pl1;
    pl1.name = "yolo";
    pl1.score = 100;

    Player pl2;
    pl2.name = "swag";
    pl2.score = 50;

    structSwap(pl1, pl2);

    cout<<pl1.name;

    return 0;
}
