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
    int randEkipa, randFGDvojk, randTrojke, menuChoice, randDvojke = 0, rezultat = 0, trojke = 0, FG = 0, visjiOvr = 0, manjsiOvr = 0,
        ovrEkipe1 = 0,ovrEkipe2 = 0, winBoostOvr = 0, ekipa1Tocke = 0, ekipa2Tocke = 0, randRaz = 0, Counter1 = 0, Counter2 = 0,
        scoreEkipa1 = 0, scoreEkipa2 = 0;
    //int menuChoice;

    string Ekipe[2] = { "Ringerz", "Ballerz" };

    //string igralciEkipe1[2];
    //string igralciEkipe2[2];

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

    //for (int i = 0; i < 2; i++) {
    //    cout << igralciEkipe1[i] << endl;
    //}

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
        randFGDvojk = rand() % 15 + 30;
        winBoostOvr = rand() % 10;
        randRaz = rand() % 11;
        randEkipa = rand() % 2 + 1;
        randDvojke = randFGDvojk * 2;
        trojke = randTrojke * 3;
        rezultat = randDvojke + trojke;
        ekipa1Tocke = rezultat/  2;

        for (int i = ekipa1Tocke; i < rezultat; i++) {
            ekipa2Tocke++;
        }

        FG = randFGDvojk + randTrojke;
        if (ovrEkipe1 > ovrEkipe2) {
            ekipa1Tocke += winBoostOvr;
        }
        else
            ekipa2Tocke += winBoostOvr;

        if (randEkipa == 1) {
            ekipa1Tocke += randRaz;
            cout << "Ekipa 1 dobla tocke\n";
        }
        else {
            ekipa2Tocke += randRaz;
            cout << "Ekipa 2 dobla tocke\n";
        }

        // Debug (?) check thing 
        cout << "rand FG Dvojk" << randFGDvojk << endl;
        cout << "rand Trojke" << randTrojke << endl;
        cout << "trojke" << trojke << endl;
        cout << "rand Dvojke" << randDvojke << endl;
        cout << "FG" << FG << endl;
        cout << "rez" << rezultat << endl;
        cout << "ekipa 1 tocke - " << ekipa1Tocke << endl;
        cout << "ekipa 2 tocke - " << ekipa2Tocke << endl;
        for (int i = 0; i < 4; i++) {
            cout << igralecStruct[i].Ekipa << endl;
            cout << igralecStruct[i].Ime << endl;
            cout << endl;
        }
        cout << ovrEkipe1;
        cout << endl;
        cout << ovrEkipe2;
        //
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
