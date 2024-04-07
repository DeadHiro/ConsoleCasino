#include <iostream>
#include <cmath>
#include <ctime>
#include <limits>
#include <unistd.h>
#include <Windows.h>

using namespace std;

void welcome();
void action();
void rulete();
void enterActionRulete();
void enterAction();
void resultActionRulete();
void animWinNumber();
void winAction();
void loseAction();

void Color(int);
void textWithColor(string, int, bool, bool);
void centredtextWithColor(string, int, bool, bool);
void sertextWithColor(string, int, bool, bool);

string center = "\t\t\t\t\t\t";
string ser = "\t\t\t";
string name;
char dolar = '$';
string actionNumber[] = {"Rulete", "Balance", "Exit" , "Back", "New", "new","back","rulete","balance","exit"};
string comand;

int money = 1000;
int stavka;
int number;
int winNumber;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);