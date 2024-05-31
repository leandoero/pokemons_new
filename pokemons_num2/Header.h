#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

enum class Element {
	Fire,
	Water,
	Earth,
	Air,
	Electric,
};
//если покемоны разных национальностей то урон наносится у кого то сильнее а у кого то легче;

struct Pokemon {
	string name;
	int hp, energy, attack, super_attack;
	Element element;
};
struct Gamer {
	vector<Pokemon> mass_poko;
	int poko_index = -1;

	Pokemon& curr_poko() {
		return mass_poko[poko_index];
	}
};

vector<Pokemon> completion();
void print_pokemons_info(vector<Pokemon> all_pokemons);
void print_current_pokemons(Gamer gamers[2]);
void fight(Gamer gamers[2], int which_attack, int round);
void choice_poko(Gamer gamers[2]);
int game();