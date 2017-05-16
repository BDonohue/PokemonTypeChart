#include "Class.h"
using namespace std;

Type::Type(){
	for(int newType = normal; newType <= fairy; newType++){
		PokemonTypeString[type] = 1;
	}
}

void Type::addSuperEffective(PokemonType type){
	PokemonTypeString[type] = 2;
}

void Type::addNotVeryEffective(PokemonType type){
	PokemonTypeString[type] = 0.5;
}

void Type::addNoEffect(PokemonType type){
	PokemonTypeString[type] = 0;
}

float Type::getMultiplier(PokemonType type){
	return PokemonTypeString[type];
}