#include "Type.h"
#include "PokemonStringToType.h"
#include "PokemonTypeToString.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){ 
    map<PokemonType,Type> PokemonTypeChart;
    ifstream infile; 
    infile.open("typedata.txt"); 
    string word;
    PokemonType addTypeName;
    for(int typeCounter = normal; typeCounter <= fairy; typeCounter++){
        Type addType;
        while(word != "NEWTYPE"){
            infile >> word;
        }
        infile >> word;
        //MAKE NEW TYPE
        addTypeName = PokemonStringToType[word];
        while(word != "SUPEREFFECTIVE"){
            infile >> word;
        }
        infile >> word;
        while(word != "NOTVERYEFFECTIVE"){
            //ADD SUPEREFFECTIVE
            addType.addSuperEffective(PokemonStringToType[word]);
            infile >> word;
        }
        infile >> word;
        while(word != "NOEFFECT"){
            //ADD NOTVERYEFFECTIVE
            addType.addNotVeryEffective(PokemonStringToType[word]);
            infile >> word;
        }
        infile >> word;
        while(word != "NEWTYPE"){
            //ADD NOEFFECT
            addType.addNoEffect(PokemonStringToType[word]);
            infile >> word;
        }  
        PokemonTypeChart[addTypeName] = addType;
    }
    infile.close();

    string input, input2;
    int cut;
    Type currentType;
    map<string,PokemonType>::iterator it;
    while(1){
        cout << "Input type: " << endl;
        cin;
        getline(cin,input);
        if(input == "quit"){
            break;
        }
        if(input.find(" ") != std::string::npos){
            cut = input.find(" ") != std::string::npos;
            cout << "two word" << endl;
        } else {
            it = PokemonStringToType.find(input);
            if (it != PokemonStringToType.end()){
                currentType = PokemonTypeChart[PokemonStringToType[input]];
                cout << "Type Chart against " << input << ":" << endl;
                for(int typeCounter = normal; typeCounter <= fairy; typeCounter++){
                    cout << PokemonTypeToString[static_cast<PokemonType>(typeCounter)] << " ";
                    cout << currentType.getMultiplier(static_cast<PokemonType>(typeCounter)) << endl;
                }
            } else {
                cout << "not a type" << endl;
            }
        }
    }
    return 0;
}

   