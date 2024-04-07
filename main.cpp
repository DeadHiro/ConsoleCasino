#include "main.h"

int main() {
    welcome();
    action();
    return 0;
}

void welcome() {
    Color(12);
    cout << center << "HIRO CASINO" << endl;
    sertextWithColor("Enter your name: ", 15,false, false);
    getline(cin, name);
    sertextWithColor("Welcome " + name + " to Hiro casinos ", 14, true, false);
    sertextWithColor("Your balance: " + to_string(money) + dolar, 10, true, false);
}

void action() {
    enterAction();
    if (comand.compare(actionNumber[0]) == 0 ||comand.compare(actionNumber[7]) == 0 ){
    if(money > 0){
    rulete();
    } else {
    sertextWithColor("You dont have money", 12, true, false);  
    action();
    }
    } else if (comand.compare(actionNumber[1]) == 0 || comand.compare(actionNumber[8]) == 0){
    sertextWithColor("Your balance: " + to_string(money) + dolar, 10, true, false);
    Color(8);
    action();
    } else if (comand.compare(actionNumber[2]) == 0 || comand.compare(actionNumber[9]) == 0){
    exit(0);
    } else {
    sertextWithColor("Error action", 12, true, false);
    action();
    }
}

void rulete() {
    srand(time(NULL));
    winNumber = rand() % 10+1;
    Color(12);
    cout << center << "WELCOME IN RULETE" << endl;
    sertextWithColor("Enter stavka: ", 2, false, false);
    cin >> stavka;
    if(stavka > money || stavka <= 0){
    system("cls");
    sertextWithColor("Error stavka", 4, true, false);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    rulete();
    }
    sertextWithColor("Enter number: ", 3, false, false);
    cin >> number;
    if(number <= 0 || number > 10){
    system("cls");
    sertextWithColor("Error number", 4, true, false);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    rulete();
    }
    if(number == winNumber) {
    winAction();
    } else {
    loseAction();
    }
}

void winAction() {
    animWinNumber();
    sertextWithColor("YOU WIN", 10, true, false);
    sertextWithColor("Win number: " + to_string(winNumber), 15, true, false);
    money += stavka;
    sertextWithColor("Your new balance: " + to_string(money), 10, true, false);
    enterActionRulete();
    resultActionRulete();
}

void loseAction() {
    animWinNumber();
    sertextWithColor("YOU LOSE", 12, true, false);
    sertextWithColor("Win number: " + to_string(winNumber), 15, true, false);
    money -= stavka;
    sertextWithColor("Your new balance: " + to_string(money) + dolar, 12, true, false);
    enterActionRulete();
    resultActionRulete();
}

void animWinNumber() {
    int animNumber;
    Color(11);
    cout << ser << ++animNumber << flush;
    for (;;) {
    if(number == winNumber && animNumber == winNumber) { break; }
    if(number != winNumber) {
    if(animNumber == winNumber + 1 && winNumber < 10) { break; }
    }if (winNumber == 10 && animNumber == winNumber - 1) { break; }
    Color(11);
    sleep(1);
    cout << "\b" << ++animNumber << flush;
    }
}

void enterActionRulete() {
    sertextWithColor("Enter action: ", 2, true, false);
    sertextWithColor("1.Back ", 4, true, false);
    sertextWithColor("2.New ", 2, true, false);
    Color(7);
    cout << ser << "> ";
    cin >> comand;
    system("cls");
}
void enterAction() {
    sertextWithColor("Enter action: ", 2, true, false);
    sertextWithColor("1. Rulete ", 3, true, false);
    sertextWithColor("2. Balance ", 6, true, false);
    sertextWithColor("3. Exit ", 4, true, false);
    Color(7);
    cout << ser << "> ";
    cin >> comand;
    system("cls");
}

void resultActionRulete() {
    if(comand.compare(actionNumber[3]) == 0 || comand.compare(actionNumber[6]) == 0){
    action();
    } else if(comand.compare(actionNumber[4]) == 0 || comand.compare(actionNumber[5]) == 0){
    if(money > 0){
    rulete();
    } else {
    sertextWithColor("You dont have money", 12, true, false);  
    enterActionRulete();
    resultActionRulete();
    }
    } else {
    sertextWithColor("Error action", 12, true, false);
    enterActionRulete();
    resultActionRulete();
  }
}

void Color(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void textWithColor(string text, int color,bool end, bool flu) {
    SetConsoleTextAttribute(hConsole, color);
    if(end && !flu){
    cout << text << endl;
    } else {
    cout << text;
    }
    if(flu){
    cout << text << flush;
    } else if (flu && end) {
    cout << text << endl << flush;
    }
}

void centredtextWithColor(string text, int color,bool end, bool flu) {
    SetConsoleTextAttribute(hConsole, color);
    if(end && !flu){
    cout << center << text << endl;
    } else {
    cout << center << text;
    }
    if(flu){
    cout << center << text << flush;
    } else if (flu && end) {
    cout << center << text << endl << flush;
    }
}

void sertextWithColor(string text, int color,bool end, bool flu) {
    SetConsoleTextAttribute(hConsole, color);
    if(end && !flu){
    cout << ser << text << endl;
    } else {
    cout << ser << text;
    }
    if(flu){
    cout << ser << text << flush;
    } else if (flu && end) {
    cout << ser << text << endl << flush;
    }
}