#include "Type.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream infile; 
    infile.open("typedata.txt"); 
    string word;
    //Loop through every word in the file
    while (infile >> word)
    {
        cout << word << endl;
    }
    infile.close();
    /*
    map<array<PokemonType,2>,int> PokemonTypeValue ({{}});
    PokemonType attack, defense;
    PokemonType insertTypeValue[2];
    for(int attackType = normal; attackType <= fairy; attackType++){
        attack = static_cast<PokemonType>(attackType);
        insertTypeValue[0] = attack;
        for(int defenseType = normal; defenseType <= fairy; defenseType++){
            defense = static_cast<PokemonType>(defenseType);
            insertTypeValue[1] = defense;
            cout << PokemonTypeString[insertTypeValue[0]] << " " << PokemonTypeString[insertTypeValue[1]] << endl;
            //PokemonTypeValue[insertTypeValue] = 1;
            //PokemonTypeValue.insert(pair<array<PokemonType,2>,int>(insertTypeValue,1));
        }
    }
    */
    return 0;
}

   