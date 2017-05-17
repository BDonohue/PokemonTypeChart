#ifndef POKEMONSTRINGTOTYPE_H
#define POKEMONSTRINGTOTYPE_H

#include <map>
#include <string>
#include "PokemonType.h"
using namespace std;

map<string,PokemonType> PokemonStringToType ({
    {"normal",normal},
    {"fighting",fighting},
    {"flying",flying},
    {"poison",poison},
    {"ground",ground},
    {"rock",rock},
    {"bug",bug},
    {"ghost",ghost},
    {"steel",steel}, 
    {"fire",fire},
    {"water",water},
    {"grass",grass},
    {"electric",electric},
    {"psychic",psychic},
    {"ice",ice},
    {"dragon",dragon},
    {"dark",dark},
    {"fairy",fairy}
});

#endif