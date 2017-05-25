#include "Type.h"
#include "PokemonStringToType.h"
#include "PokemonTypeToString.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){ 
    //add types to PokemonTypeChartAttack
    map<PokemonType,Type> PokemonTypeChartAttack;
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
        PokemonTypeChartAttack[addTypeName] = addType;
    }
    infile.close();
    //Rework PokemonTypeChartAttack into PokemonTypeChartDefense
    map<PokemonType,Type> PokemonTypeChartDefense;
    for(int typeCounter = normal; typeCounter <= fairy; typeCounter++){
        Type addType;
        Type addType2;
        int addMulti;
        //figure out which types are super effective against normal
        //fighting should be 2, ghost should be 0
        for(int typeCounter2 = normal; typeCounter2 <= fairy; typeCounter2++){
            addType2 = PokemonTypeChartAttack[static_cast<PokemonType>(typeCounter2)];
            addMulti = addType2.getMultiplier(static_cast<PokemonType>(typeCounter));
            addType.addTypeAndMulti(static_cast<PokemonType>(typeCounter2),addMulti);
        }
        PokemonTypeChartDefense[static_cast<PokemonType>(typeCounter)] = addType;
    }
    //ask user what they want
    string input, input2;
    int cut;
    Type currentType, currentType2;
    map<string,PokemonType>::iterator it, it2;
    while(1){
        cout << "Input type: " << endl;
        cin;
        getline(cin,input);
        if(input == "quit"){
            break;
        }
        if(input.find(" ") != std::string::npos){
            cut = input.find(" ");
            input2 = input.substr(cut+1);
            input = input.substr(0,cut);
            it = PokemonStringToType.find(input);
            it2 = PokemonStringToType.find(input2);
            if(it != PokemonStringToType.end() && it2 != PokemonStringToType.end()){
                //Change between attack and defense
                currentType = PokemonTypeChartDefense[PokemonStringToType[input]];
                currentType2 = PokemonTypeChartDefense[PokemonStringToType[input2]];
                cout << "Type Chart against " << input << " and " << input2 << ":" << endl;
                for(int typeCounter = normal; typeCounter <= fairy; typeCounter++){
                    cout << PokemonTypeToString[static_cast<PokemonType>(typeCounter)] << " ";
                    cout << currentType.getMultiplier(static_cast<PokemonType>(typeCounter)) * currentType2.getMultiplier(static_cast<PokemonType>(typeCounter)) << endl;
                }
            } else {
                cout << "not a type" << endl;
            }
        } else {
            it = PokemonStringToType.find(input);
            if (it != PokemonStringToType.end()){
                //Change between attack and defense
                currentType = PokemonTypeChartDefense[PokemonStringToType[input]];
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

   