#include "testy.h"


void GraPvC_Krzyzyk()
{
    cout<<"Podaj rozmiar Planszy: większy niż 2\n";
    int RozmiarPlanszy;
    cin>>RozmiarPlanszy;
    GraKiK *Gra= new GraKiK(RozmiarPlanszy);
    Gra->WypiszPlansze();
    do
    {
        if(Gra->CzyJestWolnePole())
        {
            Gra->MiniMax(0, GRACZ_O, 3);
            Gra->WypiszPlansze();
            if(Gra->CzyWygrana(GRACZ_O))
            {
            cout<<"Wygrana Gracza O\n";
            break;
            }
        }
        else break;

        Gra->TuraGracza(GRACZ_X);
        Gra->WypiszPlansze();
        if(Gra->CzyWygrana(GRACZ_X)==true)
        {
            cout<<endl<<Gra->CzyWygrana(GRACZ_X)<<endl;
            cout<<"wygrywa gracz X\n";
            break;
        }
        Gra->WypiszPlansze();
    }
    while(Gra->CzyJestWolnePole());
    Gra->WypiszPlansze();
    delete Gra;
}

void GraPvC_Kolko()
{
    cout<<"Podaj rozmiar Planszy: większy niż 2\n";
    int RozmiarPlanszy;
    cin>>RozmiarPlanszy;
    GraKiK *Gra= new GraKiK(RozmiarPlanszy);
    Gra->WypiszPlansze();
    do
    {
    Gra->TuraGracza(GRACZ_O);
    Gra->WypiszPlansze();
    if(Gra->CzyWygrana(GRACZ_O)==true)
    {
        cout<<endl<<Gra->CzyWygrana(GRACZ_O)<<endl;
        cout<<"wygrywa gracz O\n";
        break;
    }
    cout<<"czy jest wolne pole  "<<Gra->CzyJestWolnePole()<<endl;
    if(Gra->CzyJestWolnePole())
    {
        Gra->MiniMax(0, GRACZ_X, 3);
        Gra->WypiszPlansze();
        if(Gra->CzyWygrana(GRACZ_X))
        {
        cout<<"Wygrana Gracza X\n";
        break;
        }

    }
    else break;
    Gra->WypiszPlansze();
    }
    while(Gra->CzyJestWolnePole());
    Gra->WypiszPlansze();
    delete Gra;
}

void GraPvP()
{
    cout<<"Podaj rozmiar Planszy: większy niż 2\n";
    int RozmiarPlanszy;
    cin>>RozmiarPlanszy;
    GraKiK *Gra= new GraKiK(RozmiarPlanszy);
    Gra->WypiszPlansze();
    do
    {
        Gra->TuraGracza(GRACZ_O);
        Gra->WypiszPlansze();
        if(Gra->CzyWygrana(GRACZ_O)==true)
        {
            cout<<endl<<Gra->CzyWygrana(GRACZ_O)<<endl;
            cout<<"wygrywa gracz O\n";
            break;
        }
        Gra->TuraGracza(GRACZ_X);
        Gra->WypiszPlansze();
        if(Gra->CzyWygrana(GRACZ_X)==true)
        {
            cout<<endl<<Gra->CzyWygrana(GRACZ_X)<<endl;
            cout<<"wygrywa gracz X\n";
            break;
        }
    Gra->WypiszPlansze();
    }
    while(Gra->CzyJestWolnePole());
}

void pokazMenu()
{
    cout<<"Witaj w grze: KOLKO I KRYZYK\n";
    cout<<"Aby zagrac z komputerem jako kolko wybierz 1\n";
    cout<<"Aby zagrac z komputerem jako krzyzyk wybierz 2\n";
    cout<<"Aby wybrac gre dla 2 osob ybierz 3\n";
    cout<<"Aby zakonczyc wybierz 'k'\n";
}

void Testy()
{
    GraPvC_Krzyzyk();
}

void FinalnaGra()
{
 char c='a';
    while (c!='k')
    {
    pokazMenu();
    cin>>c;
    switch(c)
    {
    case '1':
    { system("clear");
    GraPvC_Kolko();
    pokazMenu();
    break;
    }
       case '2':
       { system("clear");
        pokazMenu();
        GraPvC_Krzyzyk();
        break;
       }
        case '3':
       {system("clear");
        GraPvP();
        pokazMenu();
        break;
       }
    case 'k': break;
    default:
    {
    cout<<"brak takiej opcji\n"; system("clear");
    pokazMenu();
    break;}
    }
    }
}
