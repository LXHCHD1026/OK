/* 
 * File:   aco.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 03:17
 */

#ifndef ACO_H
#define	ACO_H

#include <list>
#include <math.h>
#include "instance.h"
#include "ant.h"

#define A 2
#define B 2
#define SIZE_OF_F 100


unsigned int ocenaFeromonowa(int from, int to, unsigned int all){
    unsigned int somthing_else = zadania[to].czas;
    unsigned int feromon = feromony[from][to];
    return pow(feromon,A)*
            pow(somthing_else,B)/all*SIZE_OF_F;
}

/**
 * Szeregowanie zadan
 * @param mrowka
 */

void szeregowanie(Ant &mrowka){
    cout << "Szeregowanie" << endl;
    //czas maszyn wyzerować
    maszyny[0].czas_do_konca= 0;
    maszyny[0].ostatnie_zadanie = 0;
    maszyny[1].czas_do_konca = 0;
    maszyny[1].ostatnie_zadanie = 0;
    //oraz odwiedzonych
    for(vector<operacja>::iterator it = zadania.begin();
            it != zadania.end();
            ++it)
        (*it).visited = false;
    mrowka.ocena = 0;
    
    //nie odwiedziliśmy nikogo więc każdego możemy!
    
    list<kandydat> kandydaci_m1;
        for(vector<operacja>::iterator it = zadania.begin();
                it != zadania.end();
                ++it)
        {
         
            kandydat pom;
            pom.next = &(*it);
            kandydaci_m1.push_back(pom);
            //cout << "K: "<< kandydaci_m1.back().next->id<<endl;
               
            
        }
    
    
    
    cout << "Resetowanie zakońcozne"<< endl;
    
    while(mrowka.rozwiazanie.size() != liczba_zadan*2)   //szeregujemy dopóki nie uszeregujemy wszystkich operacji
    {
        cout << "Ilość kandydatów " << kandydaci_m1.size() << endl;
        cout << "Rozmiar rozwiązania mrówki"<< mrowka.rozwiazanie.size() << endl;
        for (int nmo = 0; nmo<2; nmo++)                     //dla każdej z dwóch maszyn
        if (mrowka.ocena>=maszyny[nmo].czas_do_konca){
            cout << "Maszyna "<< nmo << " jest wolna GT:"<<mrowka.ocena<<" ME:"<<maszyny[nmo].czas_do_konca<<endl;
            unsigned int totalFeromon = 0;
            //lista kandydatów
            for (list<kandydat>::iterator it = kandydaci_m1.begin();
                    it != kandydaci_m1.end();
                    ++it)
            {
                
                cout<<"Przetwarzam operacją o id:"<<(*it).next->id<<" "<<(*it).next->maszyna<<endl;
                if (it->next->maszyna == nmo+1) {
                    
                    // jeżeli zadanie poprzedzające nie zostało wykonane olewamy
                    if (it->next->prev != 0 && !zadania[it->next->prev].visited) continue;
                    totalFeromon += ocenaFeromonowa(maszyny[nmo].ostatnie_zadanie, it->next->id, 1);
                }
            }
            cout <<" Suma feromonów "<< totalFeromon<<endl;
            //prawidłowa ocena
            for (list<kandydat>::iterator it = kandydaci_m1.begin();
                    it != kandydaci_m1.end();
                    ++it)
                if (it->next->maszyna == nmo+1) {
                    // jeżeli zadanie poprzedzające nie zostało wykonane olewamy
                    if (it->next->prev != 0 && !zadania[it->next->prev].visited) continue;
                    it->ocena = ocenaFeromonowa(maszyny[nmo].ostatnie_zadanie, it->next->id, totalFeromon); //ocena feromonowa jest w zakresie 0-1
                    cout << "Ocena feromonowa: "<< it->ocena<<" id: "<<it->next->id<<endl;
                }

            kandydat wybrany; wybrany.next = NULL;
            //metoda ruletki
            do {
                for (list<kandydat>::iterator it = kandydaci_m1.begin();
                        it != kandydaci_m1.end();
                        ++it)
                    if (it->next->maszyna == nmo+1) {
                        // jeżeli zadanie poprzedzające nie zostało wykonane olewamy
                        if (it->next->prev != 0 && !zadania[it->next->prev].visited) continue;
                        unsigned int r = rand() / (RAND_MAX*1.0f) * SIZE_OF_F;
                        cout <<" W ruletce odejmujemy: "<<r<<endl;
                        it->ocena -= r;
                        if (it->ocena < 0) //Juhu! wybraliśmy operację
                        {
                            wybrany = *it;
                            kandydaci_m1.erase(it);
                            break;
                        }
                    }
            } while (wybrany.next == NULL); //dopóki nie wybraliśmy. Logiczne nie? :D
                // -- koniec wyboru
            cout <<"W wyniku ruletki otrzymano operację " << wybrany.next->id << endl;
                //przechodzimy do operacji
            mrowka.rozwiazanie.push_back(wybrany.next);
            maszyny[nmo].ostatnie_zadanie = wybrany.next->id;
            maszyny[nmo].czas_do_konca += wybrany.next->czas;
            wybrany.next->start = mrowka.ocena;
            //operacja została wykonana
            wybrany.next->visited = true;
            cout <<"Wciśnij dowolny klawisz"<< endl;
            cin.get();
        }
        mrowka.ocena++;
        
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
    
    cout << "Tworzenie kolonii" << endl;
    createColony(liczba_mrowek);
    

    for(int i = 0; i<iteracje; i++)
    {
        cout << "Iteracja: "<<i<<endl;
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

