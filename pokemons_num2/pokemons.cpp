#include <iostream>
#include <fstream>
#include "Header.h"
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;


vector<Pokemon> completion()					//заполнение структуры Gamer покемонами
{
	string path = "text.txt";		//переменная хранит путь к файлу
	ifstream fin;
	fin.open(path);					//открытие файла

	if (!fin.is_open()) {
		cout << "\terror!" << endl;
	}
	else {
		cout << "\topen!" << endl;
	}

	Pokemon pokemon;
	for (int i = 0; i < 6; i++)
	{
		vector<Pokemon>poko;
		while (fin >> pokemon.name >> pokemon.hp >> pokemon.energy >> pokemon.attack >> pokemon.super_attack)
		{
			poko.push_back(pokemon);
		}
		return poko;
	}
}

void Welcome(Gamer gamer) {
	std::cout << std::setw(15) << std::left << "Name"
		<< std::setw(6) << std::right << "HP"
		<< std::setw(10) << std::right << "Energy"
		<< std::setw(10) << std::right << "Attack"
		<< std::setw(15) << std::right << "Super Attack" << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << std::setw(15) << std::left << gamer.mass_poko[i].name
			<< std::setw(6) << std::right << gamer.mass_poko[i].hp
			<< std::setw(8) << std::right << gamer.mass_poko[i].energy
			<< std::setw(10) << std::right << gamer.mass_poko[i].attack
			<< std::setw(12) << std::right << gamer.mass_poko[i].super_attack << std::endl;
	}
	cout << endl << endl;
}

void Welcome_body(Gamer* gamer, int choice, int choice_2) {
	cout << endl;
	std::cout << std::setw(15) << std::left << "Name"
		<< std::setw(6) << std::right << "HP"
		<< std::setw(10) << std::right << "Energy"
		<< std::setw(10) << std::right << "Attack"
		<< std::setw(15) << std::right << "Super Attack" << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << std::setw(15) << std::left << gamer->mass_poko[choice].name
		<< std::setw(6) << std::right << gamer->mass_poko[choice].hp
		<< std::setw(8) << std::right << gamer->mass_poko[choice].energy
		<< std::setw(10) << std::right << gamer->mass_poko[choice].attack
		<< std::setw(12) << std::right << gamer->mass_poko[choice].super_attack << std::endl;
	std::cout << std::setw(15) << std::left << gamer->mass_poko[choice_2].name
		<< std::setw(6) << std::right << gamer->mass_poko[choice_2].hp
		<< std::setw(8) << std::right << gamer->mass_poko[choice_2].energy
		<< std::setw(10) << std::right << gamer->mass_poko[choice_2].attack
		<< std::setw(12) << std::right << gamer->mass_poko[choice_2].super_attack << std::endl;
	cout << endl << endl;
}

void fight(Gamer* gamer, int pokemon, int pokemon_2, int choice, int& round) {

	if (round % 2 == 0) {
		if (choice == 1) {
			gamer->mass_poko[pokemon_2].hp -= gamer->mass_poko[pokemon].attack;
			gamer->mass_poko[pokemon].energy += 10;
		}
		else if (choice == 2) {

			if (gamer->mass_poko[pokemon].energy >= 100) {
				gamer->mass_poko[pokemon_2].hp -= gamer->mass_poko[pokemon].super_attack;
				gamer->mass_poko[pokemon].energy -= 100;
			}
			else {
				cout << "Вам не хватает энергии! Ход пропущен!" << endl;
			}

		}
		else {
			cout << "Некорректный ввод! Ход пропущен... " << endl;
		}
	}
	else if (round % 2 != 0) {
		if (choice == 1) {
			gamer->mass_poko[pokemon].hp -= gamer->mass_poko[pokemon_2].attack;
			gamer->mass_poko[pokemon_2].energy += 10;
		}
		else if (choice == 2) {

			if (gamer->mass_poko[pokemon_2].energy >= 100) {
				gamer->mass_poko[pokemon].hp -= gamer->mass_poko[pokemon_2].super_attack;
				gamer->mass_poko[pokemon_2].energy -= 100;
			}
			else {
				cout << "Вам не хватает энергии! Ход пропущен!" << endl;
			}
		}
		else {
			cout << "Некорректный ввод! Ход пропущен... " << endl;
		}
	}

}