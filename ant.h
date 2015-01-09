/* 
 * File:   ant.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 09:30
 */

#ifndef ANT_H
#define	ANT_H

#include <vector>
#include <list>

int liczba_mrowek;

struct Ant{
    std::list<operacja*> rozwiazanie;
    int max_ocena;
    int ocena;
};


std::vector<Ant> colony;

void createColony(int rozmiar_koloni){
    liczba_mrowek = rozmiar_koloni;
    
    for(int i = 0; i<liczba_mrowek; i++)
    {
        colony.push_back(Ant());
        colony[i].ocena = 0;
        colony[i].max_ocena = 0;
    }
}

void resetColony(){
    for(int i = 0; i<liczba_mrowek; i++)
    {
        colony[i].ocena = 0;
        colony[i].rozwiazanie.clear();
    }
}

void clearColony(){
    
        
}


#endif	/* ANT_H */

