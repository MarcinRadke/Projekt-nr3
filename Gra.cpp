# include "Gra.h"

using namespace std;
GraKiK :: GraKiK()
{
    rozmiar=3;
    P=new  char*[3];
    for(int i= 0; i<3; ++i)
    {
        P[i]=new char[3];
    }
    for(int j=0; j<3; ++j)
    {
        for(int k=0; k<3; ++k)
        {
            P[j][k]=' ';
        }
    }
}

GraKiK::GraKiK(int bok)
{

    if(bok<=2)
        rozmiar=3;
    else
        rozmiar=bok;
    cout<<"Podaj do ilu gra\n od 2 do "<<rozmiar<<endl;
    cin>>IleAbyWygrac;
    if(IleAbyWygrac<2 || IleAbyWygrac>rozmiar)
    {
        IleAbyWygrac=rozmiar;
        cout<<"niepoprawna liczba znakow w wierszeszu do wygrania\naby wygrac trzeba zapelnic " << rozmiar<<" komorki\n";
    }
    P=new  char*[rozmiar];
    for(int i= 0; i<rozmiar; ++i)
    {
        P[i]=new char[rozmiar];
    }
    for(int j=0; j<rozmiar; ++j)
    {
        for(int k=0; k<rozmiar; ++k)
        {
            P[j][k]=' ';
        }
    }
}

void  GraKiK::WypiszPlansze()
{
    cout<<endl;
    for(int j=0; j<rozmiar; ++j)
    {
        for(int k=0; k<rozmiar; ++k)
        {
            cout<<" "<<P[j][k]<<" ";
            if(k!=rozmiar-1)
                cout<<"|";
        }
        cout<<endl;
        if(j<rozmiar-1)
        {
            for(int l=0; l<rozmiar-1; ++l )
            {
                cout << "--- ";
            }
            cout<<"---"<<endl;
        }
    }
}

bool GraKiK :: CzyWygrana(char Gracz)
{
    //wierszami
    int licz;
    for(int i=0; i<rozmiar; ++i)
    {
        licz=0;
        for(int j=0; j<rozmiar-1; ++j)
        {
            if(P[i][j]==P[i][j+1] && P[i][j+1]==Gracz)
            {
                licz++;
                if(licz==IleAbyWygrac-1)
                    return true;
            }
            else
                licz=0;
        }
    }

    //kolumnami
    for(int j=0; j<rozmiar; ++j)
    {
        licz=0;
        for(int i=0; i<rozmiar-1; ++i)
        {
            if(P[i][j]==P[i+1][j] && P[i+1][j]==Gracz)
            {
                licz++;
                if(licz==IleAbyWygrac-1)
                    return true;
            }
            else
                licz=0;
        }
    }

    // Po przekatnych
    licz=0;
    for(int i =0; i<rozmiar-1; ++i)
    {
        if(P[i][i]==P[i+1][i+1] && P[i+1][i+1]==Gracz)
        {
            licz++;
            if(licz==IleAbyWygrac-1)
                return true;
        }
        else
            licz=0;
    }

    for(int i =0; i<rozmiar-1; ++i)
    {
        if(P[i][rozmiar-1-i]==P[i+1][rozmiar-1-(i+1)] && P[i+1][rozmiar-1-(i+1)]==Gracz)
        {
            licz++;
            if(licz==IleAbyWygrac-1)
                return true;
        }
        else
            licz=0;
    }

    // Reszta pzekatnych
    if(IleAbyWygrac<rozmiar)
    {
        //lna lewo od Lewej gornej
        for( int i =1; i<=rozmiar-IleAbyWygrac; i++)
        {
            for(int j =0; j<rozmiar-i-1; ++j)
            {
                if(P[i+j][j]==P[i+j+1][j+1] && P[i+j+1][j+1]==Gracz)
                {
                    licz++;
                    if(licz==IleAbyWygrac-1)
                        return true;
                }
                else
                    licz=0;
            }
        }

        //powyzej glownej lewa gora
        for( int i =1; i<=rozmiar-IleAbyWygrac; i++)
        {
            for(int j =0; j<rozmiar-i-1; ++j)
            {
                if(P[j][j+i]==P[j+1][j+1+i] && P[j+1][i+j+1]==Gracz)
                {
                    licz++;
                    if(licz==IleAbyWygrac-1)
                        return true;
                }
                else
                    licz=0;
            }
        }

        // lewa glowna lewa dolna
        for( int i=1; i<rozmiar-1; ++i)
        {
            for(int j =0; j<=rozmiar-IleAbyWygrac-i; ++j)
            {
                if( P[rozmiar-(i+j)-1][rozmiar-(rozmiar-j)]==P[rozmiar-(i+j)-1-1][rozmiar-(rozmiar-j)+1] &&P[rozmiar-(i+j)-1-1][rozmiar-(rozmiar-j)+1]==Gracz)
                {
                    licz++;
                    if(licz==IleAbyWygrac-1)
                        return true;
                }
                else
                    licz=0;
            }
        }

        // prawa glowna lewa dolna
        for( int i =1; i<=rozmiar-IleAbyWygrac; ++i)
        {
            for(int j =rozmiar-i-1; j>=1; --j)
            {
                if(P[i+j][rozmiar-1-j]==P[i+j-1][rozmiar-j] && P[i+j-1][rozmiar-j] ==Gracz)
                {
                    licz++;
                    if(licz==IleAbyWygrac-1)
                        return true;
                }
                else
                    licz=0;
            }
        }
    }
    return false;
}

void GraKiK :: PrzygotujPlanszeDoGry()
    {
        for(int k =0; k<rozmiar; ++k)
        {
            for(int l=0; l<rozmiar; ++l)
                P[k][l]=' ';
        }
    }

bool GraKiK :: CzyJestWolnePole()
    {
        for(int k =0; k<rozmiar; ++k)
        {
            for(int l=0; l<rozmiar; ++l)
            {
                if(P[k][l]==' ')
                    return true;
            }
        }
        return false;
    }

void GraKiK :: TuraGracza(char Gracz)
    {
        int *TabPom=new int [2];
        bool Wpisane = false;
        do
        {
            cout<<"Podaj numer wierszesza\n";
            cin>>TabPom[0];
            cout<<"Podaj numer kolumnyny\n";
            cin>>TabPom[1];
            if(TabPom[0]<0 || TabPom[0]>rozmiar-1 || TabPom[1]<0 || TabPom[1]>rozmiar-1)
            {
                cout<<"Wspolrzedne poza tablica\n";
            }
            else if(P[TabPom[0]][TabPom[1]]!=' ')
            {
                cout<<"Ta komorka jest zajeta\n";
            }
            else
            {
                P[TabPom[0]][TabPom[1]]=Gracz;
                Wpisane=true;
            }
        }
        while(!Wpisane);
        delete TabPom;
    }

    int GraKiK :: MiniMax(int poziom, char gracz, int Glebokosc)
    {
        int licz=0, wiersze, kolumny;
        for(int i =0; i<rozmiar; ++i)
        {
            for(int j = 0; j<rozmiar; ++j)
            {
                if(P[i][j]==' ')
                {
                    P[i][j]=gracz;
                    kolumny=j;
                    wiersze=i;
                    licz++;
                    bool test = CzyWygrana(gracz);
                    P[i][j]=' ';
                    if(test)
                    {
                        if(!poziom)
                            P[i][j]=gracz;
                        return gracz == 'X' ? -1 : 1;
                    }
                }
            }
        }
        //czy jest remis
        if(licz==1)
        {
            if(!poziom)
                P[wiersze][kolumny]=gracz;
            return 0;
        }
        // wybór najbardziej korzystnego ruchu
        int V, VMax;
        VMax=(gracz=='X' ? rozmiar-1 : -rozmiar+1);
        for(int i=0; i<Glebokosc; ++i)
        {
            for(int j =0; j<Glebokosc; ++j)
            {
                if(P[i][j]==' ')
                {
                    P[i][j]=gracz;
                    V=MiniMax( poziom+1,(gracz=='X' ? 'O' :'X'), Glebokosc);
                    P[i][j]=' ';
                    if(((gracz=='X') &&(V<VMax)) ||((gracz=='O') && V>VMax))
                    {
                        wiersze=i;
                        kolumny=j;
                        VMax=V;
                    }
                }
            }
        }
        if (!poziom)
            P[wiersze][kolumny]=gracz;
        return VMax;
    }
