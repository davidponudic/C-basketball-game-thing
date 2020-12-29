#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

int randEkipa, randFGDvojk, randTrojke, menuChoice, randDvojke = 0, rezultat = 0, trojke = 0, FG = 0, visjiOvr = 0, manjsiOvr = 0,
ovrEkipe1 = 0, ovrEkipe2 = 0, winBoostOvr = 0, ekipa1Tocke = 0, ekipa2Tocke = 0, randRaz = 0, Counter1 = 0, Counter2 = 0,
scoreEkipa1 = 0, scoreEkipa2 = 0, oddRez = 0, ekipa1Zmage = 0, ekipa2Zmage = 0, draws = 0;

int customPlayerOvr = 0, customPlayerHeight = 0, customPlayerIzbira, customPlayerNadomestitev;
string customPlayerIme;
int c = 0;

int ekipa1Visina = 0, ekipa2Visina = 0, visinaBoost;

string Ekipe[2] = { "Ringerz", "Ballerz" };

struct Igralec {
    string Ime;
    string Ekipa;
    int Visina;
    int Overall;
    int Tocke;
}igralecStruct[5] = { {"LaBrun","",206,99,},{"Daront","",208,98,},{"Wesbrick","",191,96,},{"Kurey","",191,97,},{"","",customPlayerHeight,customPlayerOvr,} };

//void za koncne rezultate iger
void endScore(int ringerzTocke, int ballerzTocke, int ringerzZmage, int ballerzZmage, int draws) {
    cout << "Ringerz: " << ringerzTocke << "            Zmage: " << ringerzZmage;
    cout << "\nBallerz: " << ballerzTocke << "            Zmage: " << ballerzZmage << endl;
    cout << "                       Neodlocbe: " << draws << endl << endl;
}

int main()
{
    srand(time(0));

    cout << "Hoces narediti custom igralca?\n";
    cout << "1: DA\n";
    cout << "2: NE\n";
    cout << "3: EXIT\n";
    cout << "Vnesi izbiro: "; 
    cin >> customPlayerIzbira;

    if (customPlayerIzbira == 1)
    {
        system("cls");
        cout << "Vnesi ime igralca: ";
        cin.ignore();
        getline(cin, customPlayerIme);
        while (customPlayerIme[c])
        {
            if (isalpha(customPlayerIme[c]))
            {
                break;
            }
            else
            {
                cout << "Vnesi ime igralca: ";
                getline(cin, customPlayerIme);
            }
        }
        system("cls");
        cout << "Vnesi visino igralca (cm): ";
        cin >> customPlayerHeight;
        system("cls");
        cout << "Vnesi overall igralca (1-99): ";
        while (customPlayerOvr > 99 || customPlayerOvr < 1)
        {
            cin >> customPlayerOvr;
            if (customPlayerOvr > 99 || customPlayerOvr < 1)
            {
                cout << "Vnesi stevilo med 1 in 99: ";
            }
        }
        system("cls");
        cout << "Katerega igralca boste nadomestili: \n";
        cout << "1: LaBrun (OVR: " << igralecStruct[0].Overall << ")\n";
        cout << "2: Daront (OVR: " << igralecStruct[1].Overall << ")\n";
        cout << "3: Westbrick (OVR: " << igralecStruct[2].Overall << ")\n";
        cout << "4: Kurey (OVR: " << igralecStruct[3].Overall << ")\n";
        cin >> customPlayerNadomestitev;
        if (customPlayerNadomestitev == 1)
        {
            igralecStruct[0].Ime = customPlayerIme;
            igralecStruct[0].Visina = customPlayerHeight;
            igralecStruct[0].Overall = customPlayerOvr;
        }
        else if (customPlayerNadomestitev == 2)
        {
            igralecStruct[1].Ime = customPlayerIme;
            igralecStruct[1].Visina = customPlayerHeight;
            igralecStruct[1].Overall = customPlayerOvr;
        }
        else if (customPlayerNadomestitev == 3)
        {
            igralecStruct[2].Ime = customPlayerIme;
            igralecStruct[2].Visina = customPlayerHeight;
            igralecStruct[2].Overall = customPlayerOvr;
        }
        else if (customPlayerNadomestitev == 4)
        {
            igralecStruct[3].Ime = customPlayerIme;
            igralecStruct[3].Visina = customPlayerHeight;
            igralecStruct[3].Overall = customPlayerOvr;
        }
        system("cls");

        //dodelitev ekip igralcem
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
    }
    else if (customPlayerIzbira == 2)
    {
        //dodelitev ekip igralcem
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
                ekipa1Visina += igralecStruct[i].Visina;
            }
            else if (Counter2 <= 2 && randEkipa == 1) {
                igralecStruct[i].Ekipa = Ekipe[randEkipa];
                Counter2++;
                ovrEkipe2 += igralecStruct[i].Overall;
                ekipa2Visina += igralecStruct[i].Visina;
            }
        }
    }
    else if (customPlayerIzbira == 3)
    {
        exit(1);
    }

    system("cls");
    cout << "---- BLACKTOP IGRA ----\n";
    cout << "1: Igraj igro\n";
    cout << "2: Poglej generirane ekipe\n";
    cout << "3: Poglej statistike igralcev\n";
    cout << "4: EXIT\n";

    cout << "Vnesi izbiro: ";
    cin >> menuChoice;

    while (menuChoice != 4)
    {
        switch (menuChoice)
        {
        case 1: {
            system("cls");

            //karkoli se mi je tu pipalo
            randTrojke = rand() % 3 + 9;
            randFGDvojk = rand() % 15 + 30;
            winBoostOvr = rand() % 10;
            randRaz = rand() % 11;
            randEkipa = rand() % 2 + 1;
            visinaBoost = rand() % 7;

            randDvojke = randFGDvojk * 2;

            trojke = randTrojke * 3;
            rezultat = randDvojke + trojke;
            ekipa1Tocke = rezultat / 2;
            ekipa2Tocke = ekipa1Tocke;
            FG = randFGDvojk + randTrojke;

            int ekipa1RandTrojke, ekipa1RandDvojke, ekipa2RandTrojke, ekipa2RandDvojke;

            int team1Player1Dvojke = 0, team1Player2Dvojke = 0;
            int team2Player1Dvojke = 0, team2Player2Dvojke = 0;

            int team1Player1Trojke = 0, team1Player2Trojke = 0;
            int team2Player1Trojke = 0, team2Player2Trojke = 0;

            ekipa1RandDvojke = randFGDvojk / 2;
            ekipa2RandDvojke = ekipa1RandDvojke;

            ekipa1RandTrojke = randTrojke / 2;
            ekipa2RandTrojke = ekipa1RandTrojke;

            int ekipa1Trojke = ekipa1RandTrojke;
            int ekipa2Trojke = ekipa2RandTrojke;

            int ekipa1Dvojke = ekipa1RandDvojke;
            int ekipa2Dvojke = ekipa2RandDvojke;

            //ce je stevilo trojk odd doda eni random ekipi eno tocko
            if (randTrojke % 2 == 1) {
                oddRez = rand() % 1 + 1;
                if (oddRez == 1) {
                    ekipa1Trojke += 1;
                }
                else {
                    ekipa2Trojke += 1;
                }
            }

            //ce je stevilo dvojk odd doda eni random ekipi eno tocko
            if (randFGDvojk % 2 == 1) {
                oddRez = rand() % 1 + 1;
                if (oddRez == 1) {
                    ekipa1Dvojke += 1;
                }
                else {
                    ekipa2Dvojke += 1;
                }
            }

            //stevilo dvojk za igralce ekipe 1 
            team1Player1Dvojke = rand() % ekipa1Dvojke;
            for (int i = team1Player1Dvojke; i < ekipa1Dvojke; i++) {
                team1Player2Dvojke++;
            }

            //stevilo trojk za igracle ekipe 1
            team1Player1Trojke = rand() % ekipa1Trojke;
            for (int i = team1Player1Trojke; i < ekipa1Trojke; i++) {
                team1Player2Trojke++;
            }

            //stevilo dvojk za igralce ekipe 2 
            team2Player1Dvojke = rand() % ekipa2Dvojke;
            for (int i = team2Player1Dvojke; i < ekipa2Dvojke; i++) {
                team2Player2Dvojke++;
            }

            //stevilo trojk za igracle ekipe 2
            team2Player1Trojke = rand() % ekipa2Trojke;
            for (int i = team2Player1Trojke; i < ekipa2Trojke; i++) {
                team2Player2Trojke++;
            }

            /*cout << "Team 1 player 1 dvojke: " << team1Player1Dvojke << endl;
            cout << "Team 1 player 2 dvojke: " << team1Player2Dvojke << endl;
            cout << "Team 1 player 1 trojke: " << team1Player1Trojke << endl;
            cout << "Team 1 player 2 trojke: " << team1Player2Trojke << endl;

            cout << "Team 2 player 1 dvojke: " << team2Player1Dvojke << endl;
            cout << "Team 2 player 2 dvojke: " << team2Player2Dvojke << endl;
            cout << "Team 2 player 1 trojke: " << team2Player1Trojke << endl;
            cout << "Team 2 player 2 trojke: " << team2Player2Trojke << endl;*/

            int ja1 = ((team1Player1Dvojke + team1Player2Dvojke) * 2) + ((team1Player1Trojke + team1Player2Trojke) * 3), ja2 = ((team2Player1Dvojke + team2Player2Dvojke) * 2) + ((team2Player2Trojke + team2Player1Trojke) * 3);
            int ja1Counter = 0, ja2Counter = 0;

            /*cout << ja1 << endl;
            cout << ja2 << endl << endl;*/

            //rezultat = liho stevilo
            if (rezultat % 2 == 1) {
                oddRez = rand() % 1 + 1;
                if (oddRez == 1) {
                    ekipa1Tocke += oddRez;
                }
                else {
                    ekipa2Tocke += oddRez;
                }
            }

            //ekipa z boljsim ovr dobi random bonus tocke
            if (ovrEkipe1 > ovrEkipe2) {
                ekipa1Tocke += winBoostOvr;
            }
            else if (ovrEkipe2 > ovrEkipe1) {
                ekipa2Tocke += winBoostOvr;
            }
            else {
                winBoostOvr = 0;
            }

            //ekipa z visjimi igralci dobi bonus tocke
            if (ekipa1Visina > ekipa2Visina)
            {
                ekipa1Tocke += visinaBoost;
            }
            else if (ekipa2Visina > ekipa1Visina)
            {
                ekipa2Tocke += visinaBoost;
            }
            else if (ekipa1Visina == ekipa2Visina)
            {
                ekipa1Tocke += 0;
                ekipa2Tocke += 0;
            }

            //srecna ekipa dobi random tocke
            if (randEkipa == 1) {
                ekipa1Tocke += randRaz;
            }
            else {
                ekipa2Tocke += randRaz;
            }

            /*/ Debug (?) check thing 
            cout << "rand FG Dvojk" << randFGDvojk << endl;
            cout << "rand Trojke" << randTrojke << endl;
            cout << "trojke" << trojke << endl;
            cout << "rand Dvojke" << randDvojke << endl;
            cout << "FG" << FG << endl;
            cout << "rez" << rezultat << endl;
            cout << "ekipa 1 tocke - " << ekipa1Tocke << endl;
            cout << "ekipa 2 tocke - " << ekipa2Tocke << endl;
            cout << "team 1 dvojke" << ekipa1Dvojke << endl;
            cout << "team 2 dvojke" << ekipa2Dvojke << endl;
            cout << "team 1 trojke" << ekipa1Trojke << endl;
            cout << "team 2 trojke" << ekipa2Trojke << endl;
            cout << ovrEkipe1;
            cout << endl;
            cout << ovrEkipe2;
            cout << endl;
            /*/

            string plswork = "";
            string plswork2 = "";

            int randomTockeBonus1, randomTockeBonus2;
            randomTockeBonus1 = rand() % 2 + 1;
            randomTockeBonus2 = rand() % 2 + 1;

            for (int i = ja1; i < ekipa1Tocke; i++)
            {
                ja1Counter++;
            }

            for (int i = ja2; i < ekipa2Tocke; i++)
            {
                ja2Counter++;
            }
            /*cout << ja1Counter << endl;
            cout << ja2Counter << endl;*/

            int team1Player1Tocke = ((team1Player1Dvojke*2)+(team1Player1Trojke*3)), team1Player2Tocke = ((team1Player2Dvojke*2)+(team1Player2Trojke*3));
            int team2Player1Tocke = ((team2Player1Dvojke*2)+(team2Player1Trojke*3)), team2Player2Tocke = ((team2Player2Dvojke*2)+(team2Player2Trojke*3));

            if (randomTockeBonus1 == 1)
            {
                team1Player1Tocke += ja1Counter;
            }
            else
                team1Player2Tocke += ja1Counter;

            if (randomTockeBonus2 == 1)
            {
                team2Player1Tocke += ja2Counter;
            }
            else
                team2Player2Tocke += ja2Counter;

            int team1Tocke = team1Player1Tocke + team1Player2Tocke;
            int team2Tocke = team2Player1Tocke + team2Player2Tocke;

            int team1TockeCounter = team1Tocke, team2TockeCounter = team2Tocke;

            for (int i = team1Tocke; i < ekipa1Tocke; i++)
            {
                team1TockeCounter++;
            }
            for (int i = team2Tocke; i < ekipa2Tocke; i++)
            {
                team2TockeCounter++;
            }

            /*cout << team1TockeCounter << endl;
            cout << team2TockeCounter << endl;*/

            int Tocke[4] = { team1Player1Tocke, team1Player2Tocke, team2Player1Tocke, team2Player2Tocke };

            //nevem
            int ekipa1TockeCounter = 0;
            for (int i = ekipa1Tocke; i < team1Tocke; i++)
            {
                ekipa1Tocke++;
            }

            //counter zmag za ekipe
            if (team1Tocke > team2Tocke) {
                ekipa1Zmage++;
            }
            else if (team1Tocke == team2Tocke)
            {
                draws++;
            }
            else
                ekipa2Zmage++;

            endScore(ekipa1Tocke, ekipa2Tocke, ekipa1Zmage, ekipa2Zmage, draws);

            cout << Ekipe[0] << " (OVR: " << ovrEkipe1 << ")" << ": " << endl;
            int a = 0;
            for (int i = 0; i < 4; i++) {
                if (igralecStruct[i].Ekipa == Ekipe[0] && a == 0)
                {
                    igralecStruct[i].Tocke = Tocke[0];
                    cout << igralecStruct[i].Ime << " " << igralecStruct[i].Tocke << " ";
                    a++;
                    continue;
                }
                if (igralecStruct[i].Ekipa == Ekipe[0] && a == 1)
                {
                    igralecStruct[i].Tocke = Tocke[1];
                    cout << igralecStruct[i].Ime << " " << igralecStruct[i].Tocke << " ";

                }
            }
            cout << plswork.substr(0, plswork.length() - 2);
            cout << endl << endl;
            cout << Ekipe[1] << " (OVR: " << ovrEkipe2 << ")" << ": " << endl;
            int b = 0;
            for (int i = 0; i < 4; i++) {
                if (igralecStruct[i].Ekipa == Ekipe[1] && b == 0)
                {
                    igralecStruct[i].Tocke = Tocke[2];
                    cout << igralecStruct[i].Ime << " " << igralecStruct[i].Tocke << " ";
                    b++;
                    continue;
                }
                if (igralecStruct[i].Ekipa == Ekipe[1] && b == 1)
                {
                    igralecStruct[i].Tocke = Tocke[3];
                    cout << igralecStruct[i].Ime << " " << igralecStruct[i].Tocke << " ";

                }
            }
            cout << plswork2.substr(0, plswork2.length() - 2) << endl << endl;

            cout << "---- BLACKTOP IGRA ----\n";
            cout << "1: Igraj igro\n";
            cout << "2: Poglej generirane ekipe\n";
            cout << "3: Poglej statistike igralcev\n";
            cout << "4: EXIT\n";
            cout << "Vnesi izbiro: ";
            cin >> menuChoice;

            break;
        }
        case 2: {
            system("cls");

            string plswork = "";
            string plswork2 = "";

            //prikaz imen igralcev v pod njihovimi ekipami
            cout << Ekipe[0] << " (OVR: " << ovrEkipe1 << ")" << ": " << endl;
            for (int i = 0; i < 4; i++) {
                if (igralecStruct[i].Ekipa == Ekipe[0])
                {
                    plswork += igralecStruct[i].Ime + ", ";
                }
            }
            cout << plswork.substr(0, plswork.length() - 2);
            cout << endl << endl;
            cout << Ekipe[1] << " (OVR: " << ovrEkipe2 << ")" << ": " << endl;
            for (int i = 0; i < 4; i++) {
                if (igralecStruct[i].Ekipa == Ekipe[1])
                {
                    plswork2 += igralecStruct[i].Ime + ", ";
                }
            }
            cout << plswork2.substr(0, plswork2.length() - 2) << endl;

            cout << endl;

            cout << "---- BLACKTOP IGRA ----\n";
            cout << "1: Igraj igro\n";
            cout << "2: Generiraj nove ekipe\n";
            cout << "3: Poglej statistike igralcev\n";
            cout << "4: EXIT\n";
            cout << "Vnesi izbiro: ";
            cin >> menuChoice;

            //generiranje novih ekip
            if (menuChoice == 2)
            {
                Counter1 = 0, Counter2 = 0, ovrEkipe1 = 0, ovrEkipe2 = 0;
                //dodelitev ekip igralcem
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
            }
            break; 
        }
        case 3:
            system("cls");

            for (int i = 0; i < 4; i++) {
                cout << "Ime: " << igralecStruct[i].Ime << "\nVisina: " << igralecStruct[i].Visina << " cm" << "\nOverall: " << igralecStruct[i].Overall << "\nEkipa: " << igralecStruct[i].Ekipa << endl << endl;
            }

            cout << "---- BLACKTOP IGRA ----\n";
            cout << "1: Igraj igro\n";
            cout << "2: Poglej generirane ekipe\n";
            cout << "3: Poglej statistike igralcev\n";
            cout << "4: EXIT\n";
            cout << "Vnesi izbiro: ";
            cin >> menuChoice;
            break;
        case 4:
            abort();
        default:
            system("cls");
            cout << "---- BLACKTOP IGRA ----\n";
            cout << "1: Igraj igro\n";
            cout << "2: Poglej generirane ekipe\n";
            cout << "3: Poglej statistike igralcev\n";
            cout << "4: EXIT\n";
            cout << "Vnesi stevilo 1, 2, 3 ali 4: ";
            cout << endl;
            cout << "Vnesi izbiro: ";
            cin >> menuChoice;
            break;
        }
    }

    return 0;
}
