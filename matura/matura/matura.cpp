#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

struct Igralec {
    string Ime;
    string Ekipa;
    int Visina;
    int Overall;
}igralecStruct[4] = { {"LaBrun","",206,99},{"Daront","",208,98},{"Wesbrik","",191,95},{"Kurey","",191,97} };

int main()
{
    srand(time(0));
    int randEkipa, randFGDvojk, randTrojke, menuChoice, randDvojke = 0, rezultat = 0, trojke = 0, FG = 0, visjiOvr = 0, manjsiOvr = 0, ovrEkipe1 = 0, ovrEkipe2 = 0;
    int winBoostOvr = 0, ekipa1Tocke = 0, ekipa2Tocke = 0;
    int Counter1 = 0;
    int Counter2 = 0;
    //int menuChoice;

    string Ekipe[2] = { "Ringerz", "Ballerz" };

    string igralciEkipe1[2];
    string igralciEkipe2[2];

    for (int i = 0; i < 4; i++) {
        randEkipa = rand() % 2;
        if (Counter1 == 2)
            randEkipa = 1;
        if (Counter2 == 2)
            randEkipa = 0;
        if (Counter1 <= 2 && randEkipa == 0) {
            igralecStruct[i].Ekipa = Ekipe[randEkipa];
            Counter1++;
            ovrEkipe1 += igralecStruct[i].Overall;
        }
        else if (Counter2 <= 2 && randEkipa == 1) {
            igralecStruct[i].Ekipa = Ekipe[randEkipa];
            Counter2++;
            ovrEkipe2 += igralecStruct[i].Overall;
        }
    }

    /*for (int i = 0; i < 4; i++) {
        if (igralecStruct[i].Ekipa == Ekipe[0])
        {
            igralciEkipe1[i] + igralecStruct[i].Ime;
        }
    }*/

    for (int i = 0; i < 2; i++) {
        cout << igralciEkipe1[i] << endl;
    }

    cout << "---- BLACKTOP IGRA ----\n";
    cout << "1: Igraj igro\n";
    cout << "2: Poglej generirane ekipe\n";
    cout << "3: EXIT\n";

    cin >> menuChoice;

    //while (menuChoice != 3)
    //{
    switch (menuChoice)
    {
    case 1:
        randTrojke = rand() % 3 + 9;
        randFGDvojk = rand() % 10 + 35;
        winBoostOvr = rand() % 15;
        randDvojke = randFGDvojk * 2;
        trojke = randTrojke * 3;
        rezultat = randDvojke + trojke;
        FG = randFGDvojk + randTrojke;
        if (ovrEkipe1 > ovrEkipe2) {
            rezultat += winBoostOvr;
        }
        else
            cout << "rand FG Dvojk" << randFGDvojk << endl;
        cout << "rand Trojke" << randTrojke << endl;
        cout << "trojke" << trojke << endl;
        cout << "rand Dvojke" << randDvojke << endl;
        cout << "FG" << FG << endl;
        cout << "rez" << rezultat << endl;
        break;
    case 2:
        for (int i = 0; i < 4; i++) {
            cout << igralecStruct[i].Ekipa << endl;
            cout << igralecStruct[i].Ime << endl;
            cout << endl;
        }
        cout << ovrEkipe1;
            cout << endl;
        cout << ovrEkipe2;
        break;
    case 3:
        exit(1);
        break;
    default:
        break;
    }
    //}

    return 0;
}
