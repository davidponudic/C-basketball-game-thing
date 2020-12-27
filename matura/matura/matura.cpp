#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int randEkipa, randFGDvojk, randTrojke, menuChoice, randDvojke = 0, rezultat = 0, trojke = 0, FG = 0, visjiOvr = 0, manjsiOvr = 0,
ovrEkipe1 = 0, ovrEkipe2 = 0, winBoostOvr = 0, ekipa1Tocke = 0, ekipa2Tocke = 0, randRaz = 0, Counter1 = 0, Counter2 = 0,
scoreEkipa1 = 0, scoreEkipa2 = 0, oddRez = 0, ekipa1Zmage = 0, ekipa2Zmage = 0, draws = 0;

string Ekipe[2] = { "Ringerz", "Ballerz" };

struct Igralec {
    string Ime;
    string Ekipa;
    int Visina;
    int Overall;
}igralecStruct[4] = { {"LaBrun","",206,99},{"Daront","",208,98},{"Wesbrick","",191,96},{"Kurey","",191,97} };

//void za koncne rezultate iger
void endScore(int ringerzTocke, int ballerzTocke, int ringerzZmage, int ballerzZmage, int draws) {
    cout << "Ringerz: " << ringerzTocke << "            Zmage: " << ringerzZmage;
    cout << "\nBallerz: " << ballerzTocke << "            Zmage: " << ballerzZmage << endl;
    cout << "                       Neodlocbe: " << draws << endl << endl;
}

int main()
{
    srand(time(0));

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

            randDvojke = randFGDvojk * 2;

            trojke = randTrojke * 3;
            rezultat = randDvojke + trojke;
            ekipa1Tocke = rezultat / 2;
            ekipa2Tocke = ekipa1Tocke;
            FG = randFGDvojk + randTrojke;

            int ekipa1RandTrojke, ekipa1TockeStats, ekipa1TockeStatsHalf, ekipa1TockeStatsHalfRand, ekipa1RandDvojke, ekipa2RandTrojke, ekipa2TockeStats, ekipa2TockeStatsHalf,
                ekipa2TockeStatsHalfRand, ekipa2RandDvojke;

            

            int team1Player1Dvojke = 0, team1Player2Dvojke = 0;
            int team2Player1Dvojke = 0, team2Player2Dvojke = 0;

            int team1Player1Trojke = 0, team1Player2Trojke = 0;
            int team2Player1Trojke = 0, team2Player2Trojke = 0;


            ekipa1RandDvojke = randFGDvojk / 2;
            ekipa2RandDvojke = ekipa1RandDvojke;

            ekipa1RandTrojke = randTrojke / 2;
            ekipa2RandTrojke = ekipa1RandTrojke;

            int ekipa1Trojke = ekipa1RandTrojke;
            int ekipa1TrojkeHalf;
            int ekipa2Trojke = ekipa2RandTrojke;
            int ekipa2TrojkeHalf;

            int ekipa1Dvojke = ekipa1RandDvojke;
            int ekipa1DvojkeHalf;
            int ekipa2Dvojke = ekipa2RandDvojke;
            int ekipa2DvojkeHalf;

            

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

            cout << "Team 1 player 1 dvojke: " << team1Player1Dvojke << endl;
            cout << "Team 1 player 2 dvojke: " << team1Player2Dvojke << endl;
            cout << "Team 1 player 1 trojke: " << team1Player1Trojke << endl;
            cout << "Team 1 player 2 trojke: " << team1Player2Trojke << endl;

            cout << "Team 2 player 1 dvojke: " << team2Player1Dvojke << endl;
            cout << "Team 2 player 2 dvojke: " << team2Player2Dvojke << endl;
            cout << "Team 2 player 1 trojke: " << team2Player1Trojke << endl;
            cout << "Team 2 player 2 trojke: " << team2Player2Trojke << endl;
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

            //srecna ekipa dobi random tocke
            if (randEkipa == 1) {
                ekipa1Tocke += randRaz;
            }
            else {
                ekipa2Tocke += randRaz;
            }

            //counter zmag za ekipe
            if (ekipa1Tocke > ekipa2Tocke) {
                ekipa1Zmage++;
            }
            else
                ekipa2Zmage++;

            //counter neodlocb
            if (ekipa1Tocke == ekipa2Tocke) {
                draws++;
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
            cout << "team 1 dvojke" << ekipa1Dvojke << endl;
            cout << "team 2 dvojke" << ekipa2Dvojke << endl;
            cout << "team 1 trojke" << ekipa1Trojke << endl;
            cout << "team 2 trojke" << ekipa2Trojke << endl;
            cout << ovrEkipe1;
            cout << endl;
            cout << ovrEkipe2;
            cout << endl;
            //

            endScore(ekipa1Tocke, ekipa2Tocke, ekipa1Zmage, ekipa2Zmage, draws);

            string plswork = "";
            string plswork2 = "";

            int team1Player1Tocke = ((team1Player1Dvojke*2)+(team1Player1Trojke*3)), team1Player2Tocke = ((team1Player2Dvojke*2)+(team1Player2Trojke*3));
            int team2Player1Tocke = ((team2Player1Dvojke*2)+(team2Player1Trojke*3)), team2Player2Tocke = ((team2Player2Dvojke*2)+(team2Player2Trojke*3));

            int team1Tocke = team1Player1Tocke + team1Player2Tocke;
            int team2Tocke = team2Player1Tocke + team2Player2Tocke;

            for (int i = team1Tocke; i < ekipa1Tocke; i++)
            {
                team1Tocke++;
            }

            cout << team1Tocke;

            int Tocke[4] = { team1Player1Tocke, team1Player2Tocke, team2Player1Tocke, team2Player2Tocke };

            //prikaz imen igralcev v pod njihovimi ekipami
            cout << Ekipe[0] << " (OVR: " << ovrEkipe1 << ")" << ": " << endl;
            for (int i = 0; i < 4; i++) {
                if (igralecStruct[i].Ekipa == Ekipe[0])
                {
                    cout << igralecStruct[i].Ime << " " << Tocke[i] << " ";
                }
            }
            cout << plswork.substr(0, plswork.length() - 2);
            cout << endl << endl;
            cout << Ekipe[1] << " (OVR: " << ovrEkipe2 << ")" << ": " << endl;
            for (int i = 0; i < 4; i++) {
                if (igralecStruct[i].Ekipa == Ekipe[1])
                {
                    cout << igralecStruct[i].Ime << " " << Tocke[i] << " ";
                }
            }
            cout << plswork2.substr(0, plswork2.length() - 2) << endl;


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
            cout << "2: Poglej generirane ekipe\n";
            cout << "3: Poglej statistike igralcev\n";
            cout << "4: EXIT\n";
            cout << "Vnesi izbiro: ";
            cin >> menuChoice;
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
