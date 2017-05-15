#ifndef GLOBAL_H
#define GLOBAL_H

#include <map>
#include <array>
using namespace std;

enum PokemonType {
	normal,
	fighting,
	flying,
	poison,
	ground,
	rock,
	bug,
	ghost,
	steel,
	fire,
	water,
	grass,
	electric,
	psychic,
	ice,
	dragon,
	dark,
	fairy
};

map<PokemonType,string> PokemonTypeString ({
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