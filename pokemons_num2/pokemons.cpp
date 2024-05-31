#include <iostream>
#include <fstream>
#include "Header.h"
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;


vector<Pokemon> completion()					//���������� ��������� Gamer ����������
{
	string path = "text.txt";		//���������� ������ ���� � �����
	ifstream fin;
	fin.open(path);					//�������� �����

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
		int element;
		while (fin >> pokemon.name >> pokemon.hp >> pokemon.energy >> pokemon.attack >> pokemon.super_attack >> element) //������ �� �����
		{
			pokemon.element = (Element)element;
			poko.push_back(pokemon);
		}
		return poko;
	}
}

const char* element_names[] = {				//������ ���� ���������
	"Fire",
	"Water",
	"Earth",
	"Air",
	"Electric",
};

void print_pokemons_info(vector<Pokemon> all_pokemons) {
	std::cout << "   " << std::setw(15) << std::left << "Name"
		<< std::setw(6) << std::right << "HP"
		<< std::setw(10) << std::right << "Energy"
		<< std::setw(10) << std::right << "Attack"
		<< std::setw(15) << std::right << "Super Attack"
		<< std::setw(15) << std::right << "Element"
		<< std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;

	for (int i = 0; i < all_pokemons.size(); i++)
	{
		std::cout << i << ": " << std::setw(15) << std::left << all_pokemons[i].name
			<< std::setw(6) << std::right << all_pokemons[i].hp   
			<< std::setw(8) << std::right << all_pokemons[i].energy
			<< std::setw(10) << std::right << all_pokemons[i].attack
			<< std::setw(12) << std::right << all_pokemons[i].super_attack
			<< std::setw(20) << std::right << element_names[(int)all_pokemons[i].element]
			<< std::endl;
	}
	cout << endl << endl;
}

void print_current_pokemons(Gamer gamers[2]) {
	cout << endl;
	std::cout << std::setw(15) << std::left << "Name"
		<< std::setw(6) << std::right << "HP"
		<< std::setw(10) << std::right << "Energy"
		<< std::setw(10) << std::right << "Attack"
		<< std::setw(15) << std::right << "Super Attack" << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << std::setw(15) << std::left << gamers[0].curr_poko().name
		<< std::setw(6) << std::right << gamers[0].curr_poko().hp
		<< std::setw(8) << std::right << gamers[0].curr_poko().energy
		<< std::setw(10) << std::right << gamers[0].curr_poko().attack
		<< std::setw(12) << std::right << gamers[0].curr_poko().super_attack << std::endl;
	std::cout << std::setw(15) << std::left << gamers[1].curr_poko().name
		<< std::setw(6) << std::right << gamers[1].curr_poko().hp
		<< std::setw(8) << std::right << gamers[1].curr_poko().energy
		<< std::setw(10) << std::right << gamers[1].curr_poko().attack
		<< std::setw(12) << std::right << gamers[1].curr_poko().super_attack << std::endl;
	cout << endl << endl;
}

void fight(Gamer gamers[2], int which_attack, int round) {

	float attack[5][5] = {			//���� ����� �� �������� ��������
		{1, 1, 1, 1, 1.5f},
		{1, 1, 2.0f, 1, 1},
		{1, 1, 1, 1, 1},
		{1.5f, 1, 1, 1, 1},
		{1, 2.0f, 1, 1, 1},
	};

	if (round % 2 == 0) {
		if (which_attack == 1) {
			gamers[1].curr_poko().hp -= gamers[0].curr_poko().attack * attack[(int)gamers[0].curr_poko().element][(int)gamers[1].curr_poko().element];
			gamers[0].curr_poko().energy += 10;
		}
		else if (which_attack == 2) {

			if (gamers[0].curr_poko().energy >= 100) {
				gamers[1].curr_poko().hp -= gamers[0].curr_poko().super_attack;
				gamers[0].curr_poko().energy -= 100;
			}
			else {
				cout << "��� �� ������� �������! ��� ��������!" << endl;
			}

		}
		else if (which_attack == 3) {
			cout << "������ �����. �������� �������� ��� ���:" << endl;
			for (int i = 0; i < gamers[0].mass_poko.size(); i++) {
				cout << i << ": " << gamers[0].mass_poko[i].name << endl;
			}
			cin >> gamers[0].poko_index;
		}
		else {
			cout << "������������ ����! ��� ��������... " << endl;
		}
	}
	else if (round % 2 != 0) {
		if (which_attack == 1) {
			gamers[0].curr_poko().hp -= gamers[1].curr_poko().attack * attack[(int)gamers[1].curr_poko().element][(int)gamers[0].curr_poko().element];
			gamers[1].curr_poko().energy += 10;
		}
		else if (which_attack == 2) {

			if (gamers[1].curr_poko().energy >= 100) {
				gamers[0].curr_poko().hp -= gamers[1].curr_poko().super_attack;
				gamers[1].curr_poko().energy -= 100;
			}
			else {
				cout << "��� �� ������� �������! ��� ��������!" << endl;
			}
		}
		else if (which_attack == 3) {
			cout << "������ �����. �������� �������� ��� ���:" << endl;
			for (int i = 0; i < gamers[1].mass_poko.size(); i++) {
				cout << i << ": " << gamers[1].mass_poko[i].name << endl;
			}
			cin >> gamers[1].poko_index;
		}
		else {
			cout << "������������ ����! ��� ��������... " << endl;
		}
	}

}

void choice_poko(Gamer gamers[2]) {							//������� ��� ������ ��������
	std::vector<Pokemon> all_pokemons = completion();

	print_pokemons_info(all_pokemons);

	for (int gamer_index = 0; gamer_index < 2; gamer_index++) {
		for (int i = 0; i < 3; i++) {
			cout << gamer_index + 1 << "-�� �����, �������� " << i + 1 << "-�� ��������:\n";
			int choice;
			cin >> choice;
			gamers[gamer_index].mass_poko.push_back(all_pokemons[choice]);
		}
	}
	cout << endl << endl << endl;
}

int game() {
	char restart_game;
	char start;
	char key;
	int round = 0;

	do {
		Gamer gamers[2];

		choice_poko(gamers);

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "�� �������: " << endl;
		for (int i = 0; i < gamers[0].mass_poko.size(); i++) {
			cout << i << ": " << gamers[0].mass_poko[i].name << endl;
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "�� �������: " << endl;
		for (int i = 0; i < gamers[1].mass_poko.size(); i++) {
			cout << i << ": " << gamers[1].mass_poko[i].name << endl;
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
		cout << "������ ���? y/n" << endl;
		do {
			cin >> start;
			if (start == 'y' || start == 'Y') {
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "������ ����� ������ �����. ������� � ���� ��� ������������ ����� �����? (�����, ��� ����� ����� �������� ����� �������!���� � ���� ���������� ������� �� 10 ������!)"
					" ����� ������� � ���� ����� 1, � ��� ����� ����� - 2" << endl;
				cout << "3 - ������� ��������\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

				do {
					if (gamers[0].poko_index == -1) {									//���� ������� �� ������
						cout << "������ �����. �������� �������� ��� ���:" << endl;
						for (int i = 0; i < gamers[0].mass_poko.size(); i++) {
							cout << i << ": " << gamers[0].mass_poko[i].name << endl;
						}
						cin >> gamers[0].poko_index;
					}

					if (gamers[1].poko_index == -1) {
						cout << "������ �����. �������� �������� ��� ���:" << endl;
						for (int i = 0; i < gamers[1].mass_poko.size(); i++) {
							cout << i << ": " << gamers[1].mass_poko[i].name << endl;
						}
						cin >> gamers[1].poko_index;

					}

					cout << "�����: " << round << endl;
					SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					print_current_pokemons(gamers);
					if (round % 2 == 0) {
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << gamers[0].mass_poko[gamers[0].poko_index].name << ":" << '\t';
					}
					else {
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << gamers[1].mass_poko[gamers[1].poko_index].name << ":" << '\t';
					}
					int which_attack;
					cin >> which_attack;
					cout << endl << endl << endl;
					fight(gamers, which_attack, round);
					round += 1;

					if (gamers[0].curr_poko().hp <= 0) {
						gamers[0].mass_poko.erase(gamers[0].mass_poko.begin() + gamers[0].poko_index);
						gamers[0].poko_index = -1;
					}

					if (gamers[1].curr_poko().hp <= 0) {
						gamers[1].mass_poko.erase(gamers[1].mass_poko.begin() + gamers[1].poko_index);
						gamers[1].poko_index = -1;
					}
				} while (!gamers[0].mass_poko.empty() && !gamers[1].mass_poko.empty());
				if (gamers[0].mass_poko.empty()) {
					cout << "��� �������! ������ : " << gamers[1].curr_poko().name << endl;
					break;
				}
				else if (gamers[1].mass_poko.empty()) {
					cout << "��� �������! ������ : " << gamers[0].curr_poko().name << endl;
					break;
				}
				else {
					cout << "��� �������! �����! " << endl;
					break;
				}

			}
			else if (start == 'n' || start == 'N') {
				return 0;
			}
			else {
				cout << "������������ ����. ���������� ��� ���!" << endl;
			}
		} while (start != 'y' || start != 'Y');
		cout << "������ ����� ����? y/n" << endl;
		do {
			cin >> restart_game;
			if (restart_game == 'n') {
				cout << "����� �� ���������..." << endl;
				return 0;
			}
			cout << "������������ ����! ���������� ��� ���! " << endl;

		} while (restart_game != 'Y' && restart_game != 'y');
		cout << endl << endl << endl;
	} while (restart_game == 'Y' || restart_game == 'y');
}