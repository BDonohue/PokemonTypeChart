#ifndef POKEMONTYPETOSTRING_H
#define POKEMONTYPETOSTRING_H

#include <map>
#include <string>
#include "PokemonType.h"
using namespace std;

map<PokemonType,string> PokemonTypeToString ({
    {normal,"normal"},
    {fighting,"fighting"},
    {flying,"flying"},
    {poison,"poison"},
    {ground,"ground"},
    {rock,"rock"},
    {bug,"bug"},
    {ghost,"ghost"},
    {steel,"steel"},
    {fire,"fire"},
    {water,"water"},
    {grass,"grass"},
    {electric,"electric"},
    {psychic,"psychic"},
    {ice,"ice"},
    {dragon,"dragon"},
    {dark,"dark"},
    {fairy,"fairy"}
});

#endif