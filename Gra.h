#pragma once
#include <iostream>
#define GRACZ_X 'X'
#define GRACZ_O 'O'
using namespace std;

class GraKiK
{

    char **P;
    int rozmiar;
    int IleAbyWygrac;
    public:
    GraKiK();

    GraKiK(int bok);
/*
 *  wypisuje plansze w konsoli
 */
    void WypiszPlansze();

/*
 *  sprawdza czy aktualny uklad planszy
 * jest zwycieski dla ktoregos z graczy
 */
    bool CzyWygrana(char Gracz);

/*
 *  tworzy pusta plansze
 */
    void PrzygotujPlanszeDoGry();

/*
 *  sprawdza czy jest wolne pole w tablicy
 */
    bool CzyJestWolnePole();

/*
 *  realizuje ruch gracza
 */
    void TuraGracza(char Gracz);

/*
 *  realizuje algorytm minmax i wykonuje ruch komputera
 */
    int MiniMax(int poziom, char gracz, int Glebokosc);
};
