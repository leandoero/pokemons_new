#include <iostream>
#include <fstream>
#include "Header.h"
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int game;
	char restart_game;
	int choice;
	int choice_2;
	char start;
	char key;
	int round = 0;
	
	do {
		Gamer gamer;
		gamer.mass_poko = completion();
		Welcome(gamer);
		cout << "Выберите покемонов:";
		cin >> choice;
		cin >> choice_2;
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Вы выбрали: " << gamer.mass_poko[choice].name << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Выбор противника: " << gamer.mass_poko[choice_2].name << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
		cout << "Начать бой? y/n" << endl;
		do {
			cin >> start;
			if (start == 'y' || start == 'Y') {
				cout << endl;
				std::cout << std::setw(15) << std::left << "Name"
					<< std::setw(6) << std::right << "HP"
					<< std::setw(10) << std::right << "Energy"
					<< std::setw(10) << std::right << "Attack"
					<< std::setw(15) << std::right << "Super Attack" << std::endl;

				std::cout << "-------------------------------------------------------------" << std::endl;
				std::cout << std::setw(15) << std::left << gamer.mass_poko[choice].name
					<< std::setw(6) << std::right << gamer.mass_poko[choice].hp
					<< std::setw(8) << std::right << gamer.mass_poko[choice].energy
					<< std::setw(10) << std::right << gamer.mass_poko[choice].attack
					<< std::setw(12) << std::right << gamer.mass_poko[choice].super_attack << std::endl;
				std::cout << std::setw(15) << std::left << gamer.mass_poko[choice_2].name
					<< std::setw(6) << std::right << gamer.mass_poko[choice_2].hp
					<< std::setw(8) << std::right << gamer.mass_poko[choice_2].energy
					<< std::setw(10) << std::right << gamer.mass_poko[choice_2].attack
					<< std::setw(12) << std::right << gamer.mass_poko[choice_2].super_attack << std::endl;
				cout << endl << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "Первым ходит зелёный игрок. Ударить с руки или использовать супер атаку? (Помни, что супер атака потратит шкалу энергии!Удар с руки восполняет энергию на 10 единиц!)"
					" Чтобы ударить с руки нажми 1, а для супер атаки - 2" << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

				do {
					cout << "Раунд: " << round << endl;
					if (round % 2 == 0) {
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << gamer.mass_poko[choice].name << ":" << '\t';
					}
					else {
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << gamer.mass_poko[choice_2].name << ":" << '\t';
					}
					cin >> game;
					system("cls");
					fight(&gamer, choice, choice_2, game, round);
					SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					Welcome_body(&gamer, choice, choice_2);
					round += 1;
				} while (gamer.mass_poko[choice].hp > 0 && gamer.mass_poko[choice_2].hp > 0);
				if (gamer.mass_poko[choice].hp <= 0) {
					cout << "Бой окончен! Победа : " << gamer.mass_poko[choice_2].name << endl;
					break;
				}
				else if (gamer.mass_poko[choice_2].hp <= 0) {
					cout << "Бой окончен! Победа : " << gamer.mass_poko[choice].name << endl;
					break;
				}
				else {
					cout << "Бой окончен! Ничья! " << endl;
					break;
				}

			}
			else if (start == 'n' || start == 'N') {
				return 0;
			}
			else {
				cout << "Некорректный ввод. Попробуйте еще раз!" << endl;
			}
		} while (start != 'y' || start != 'Y');
		cout << "Начать новую игру? y/n" << endl;
		do {
			cin >> restart_game;
			if (restart_game == 'n') {
				cout << "Выход из программы..." << endl;
				return 0;
			}
			cout << "Некорректный ввод! Попробуйте еще раз! " << endl;
			
		} while (restart_game != 'Y' && restart_game != 'y');
		system("cls");
	} while (restart_game == 'Y' || restart_game == 'y');
	
}
