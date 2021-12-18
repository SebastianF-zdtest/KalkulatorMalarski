#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <cmath>

using namespace std;

float surface = 15; // 15 metrow kwadratowych potrzebny 1 litr
float quantity = 1; // na jeden surface potrzebny 1 litr
float cost = 25; // 1h pracy to 25 zl
float wage = 75; // 15 metrow scian to 3h = 75 zl
float a, b, price;
int rooms;

float no_rooms()
{
    cout << "\n----\n";
    cout << "Prosze podac cene farby: \n";
    cin >> price;

    while(price <= 10)
    {
        cout << "\n----\n";
        cout << "Prosze podac poprawna cene farby: \n";
        cin >> price;
    }

    cout << "\n----\n";
    cout << "Prosze podac ilosc pokoi: \n";
    cin >> rooms;

    while(rooms <= 1)
    {
        cout << "\n----\n";
        cout << "Prosze podac poprawna ilosc pokoi: \n";
        cin >> rooms;
    }

    cout << "\n----\n";
    cout << "Podana cena farby: " << price <<endl;
    cout << "Podana ilosc pokoi: " << rooms <<endl;

    return 0;
}

float room_size()
{
    int i;
    float sides = 0;
    float surfaces, hours, paint_price, wages, total_price;
    float * x = new float [rooms];
    for (i = 1; i <= rooms; i++)
    {
        cout << "\n----\n";
        cout << "Prosze podac pierwszy wymiar sciany pokoju ["<< i << "] : \n";
        cin >> a;
        cout << "Prosze podac drugi wymiar sciany pokoju ["<< i << "] : \n";
        cin >> b;

        x[i] = (a * b) * 4;
        sides = sides + x[i];

        cout << "\n----\n";
        cout << "Powierzchnia scian w pokoju ["<< i << "] : "<< x[i]<<"\n";
    }

    cout << "\n----\n";
    cout << "Calkowita powierzchnia pomieszczen: "<< sides<<endl;

    surfaces = sides / surface;
    cout << "\n***********Koncowe obliczenia kalkulatora!!!\n";
    cout << "1) Wymagana ilosc farby: "<< surfaces<< setprecision(3+3) <<" l.\n";
    hours = sides /5;
    cout << "2) Wymagana ilosc czasu: "<< hours << setprecision(3+3) <<" h.\n";
    paint_price = price * surfaces;
    cout << "3) Koszta farby: "<< paint_price << setprecision(3+3) <<" pln.\n";
    wages = wage * hours;
    cout << "4) Koszt roboczo-godzin: "<< wages << setprecision(3+3) <<" pln.\n";
    total_price = wages + paint_price;
    cout << "5) Calkowity koszt malowania "<<rooms<<" pokoi: "<< total_price << setprecision(3+3) <<" pln.\n";


    return x[rooms];

}

float total()
{

}

int main()
{
    cout << "\n***********Kalkulator malarski***********\n";
    cout << "\n***********\n";
    cout << "Instrukcja dzialania kalkulatora: \n";
    cout << "1) Klient wprowadza ilosc pokoi(minimalna ilosc 1)\n";
    cout << "2) Klient wprowadza wymiary scian w pokojach\n";
    cout << "3) Klient wprowadza cene farby(minimalna cena 10zl)\n";
    cout << "4) Zostaje obliczone: \n";
    cout << "       1) ilosc potrzebnej farby\n";
    cout << "       2) ilosc godzin pracy\n";
    cout << "       3) koszt calkowity farby\n";
    cout << "       4) koszt pracy\n";
    cout << "       5) calkowity koszt\n";

    no_rooms();

    room_size();
}
