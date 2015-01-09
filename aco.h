/* 
 * File:   aco.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 03:17
 */

#ifndef ACO_H
#define	ACO_H

/**
 * Szeregowanie zadan
 * @param mrowka
 */

void szeregowanie(Ant &mrowka){
    
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
    
    createColony();

    for(int i = 0; i<iteracje; i++)
    {
        resetColony();
        for(Ant &mrowka : colony){
            //znajdź rozwiązanie
            szeregowanie(mrowka);
            //jeżeli jest lepsze od najlepszego to zapamiętaj
        }
        //wyparuj feromony
        //dla każdej mrówki
            //rozloz feromony
    }
}

#endif	/* ACO_H */

