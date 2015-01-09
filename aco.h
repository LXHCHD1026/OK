/* 
 * File:   aco.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 03:17
 */

#ifndef ACO_H
#define	ACO_H

#include <list>
#include "instance.h"
#include "ant.h"

#define A 2
#define B 2


unsigned int ocenaFeromonowa(int from, int to, unsigned int all){
    unsigned int somthing_else = zadania[to].czas;
    unsigned int feromon = feromony[from][to]
    return pow(feromon,A)*
            pow(somthing_else,B)/all;
}

/**
 * Szeregowanie zadan
 * @param mrowka
 */

void szeregowanie(Ant &mrowka){
    //czas maszyn wyzerować
    maszyny[0].czas = 0;
    maszyny[1].czas = 0;
    //oraz odwiedzonych
    for(vector<operacja>::iterator it = zadania.begin();
            it != zadania.end();
            ++it)
        (*it).visited = false;
    mrowka.ocena = 0;
    //nie odwiedziliśmy nikogo więc każdego możemy!
    int foo = 0;
    list<kandydat> kandydaci_m1;
        for(vector<operacja>::iterator it = zadania.begin();
                it != zadania.end();
                ++it)
        {
            kandydaci_m1.push_back(kandydat());
            kandydat * pom = kandydaci_m1[foo];
            pom->next = it;
        }
    unsigned int last_m1 = 0;
    unsigned int uplyw_czasu=0;
    while(mrowka.rozwiazanie.size() != liczba_zadan*2)   //szeregujemy dopóki nie uszeregujemy wszystkich operacji
    {
        unsigned int totalFeromon = 0;
        //lista kandydatów
        for (list<kandydat>::iterator it = kandydaci_m1.begin();
                it != kandydaci_m1.end();
                ++it)
        if(it->next->maszyna == MASZYNA1){
            // jeżeli zadanie poprzedzające nie zostało wykonane olewamy
            if (it->next->prev!=0 && !zadania[it->next->prev].visited) continue; 
            totalFeromon += ocenaFeromonowa(last_m1,it->next->id,1);
        }
        //prawidłowa ocena
        for (list<kandydat>::iterator it = kandydaci_m1.begin();
                it != kandydaci_m1.end();
                ++it)
        if(it->next->maszyna == MASZYNA1){
            // jeżeli zadanie poprzedzające nie zostało wykonane olewamy
            if (it->next->prev!=0 && !zadania[it->next->prev].visited) continue; 
            it->ocena = ocenaFeromonowa(last_m1,it->next->id,totalFeromon); //ocena feromonowa jest w zakresie 0-1
        }
        
        kandydat * wybrany = NULL;
        //metoda ruletki
        do
        {
            for (list<kandydat>::iterator it = kandydaci_m1.begin();
                it != kandydaci_m1.end();
                ++it)
            if(it->next->maszyna == MASZYNA1){
                // jeżeli zadanie poprzedzające nie zostało wykonane olewamy
                if (it->next->prev!=0 && !zadania[it->next->prev].visited) continue; 
                it->ocena -= rand()/RAND_MAX;
                if (it->ocena < 0) //Juhu! wybraliśmy operację
                {
                    wybrany = it;
                    break;
                }
            }
        }
        while(wybrany == NULL)    //dopóki nie wybraliśmy. Logiczne nie? :D
        // -- koniec wyboru
        
        
    }
}


/**
 * ACO
 * @param iteracje
 * @param liczba_mrowek
 */

void aco(
        int iteracje, //liczba iteracji
        int liczba_mrowek
        ) {
    
    createColony(liczba_mrowek);
    

    for(int i = 0; i<iteracje; i++)
    {
        resetColony();
        for(vector<Ant>::iterator mrowka = colony.begin();
                                mrowka != colony.end();
                                ++mrowka){
            //znajdź rozwiązanie
            szeregowanie(*mrowka);
            //jeżeli jest lepsze od najlepszego to zapamiętaj
        }
        //wyparuj feromony
        //dla każdej mrówki
            //rozloz feromony
    }
}

#endif	/* ACO_H */

