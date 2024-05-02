#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Pokemon {
	string name;
	int hp, energy, attack, super_attack;
};
struct Gamer {
	vector<Pokemon> mass_poko;
};

vector<Pokemon> completion();
void Welcome(Gamer gamer);
void Welcome_body(Gamer* gamer, int choice, int choice_2);
void fight(Gamer* gamer, int pokemon, int pokemon_2, int choice, int& round);
