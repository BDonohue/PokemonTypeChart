#ifndef TYPE_H
#define TYPE_H

#include "PokemonType.h"
using namespace std;

class Type{
	public:
		explicit Type();
		void addSuperEffective(PokemonType type);
		void addNotVeryEffective(PokemonType type);
		void addNoEffect(PokemonType type);
		void addTypeAndMulti(PokemonType type, float multi);
		float getMultiplier(PokemonType type);
	private:
		map<PokemonType,float> PokemonTypeString;
};

#endif