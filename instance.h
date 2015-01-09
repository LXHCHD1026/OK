/* 
 * File:   instance.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 00:41
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include <vector>
#include <iostream>


#define MASZYNA1 1

struct operacja{
    unsigned int czas;     // czas wykonania operacji
    unsigned int maszyna;  // numer maszyny na której ma zostać wykonany
    unsigned int start;    // czas rozpoczęcia operacji
    unsigned int end;      // czas końca operacji
    unsigned int id;       // identyfikator operacji
    unsigned int zad_id;   // id zadania
    bool visited;          // czy został odwiedzony?
    int prev;              // numer zadanie które musi zostać wykonane przed
};

struct zadanie{             //zadanie identyfikuje indeks w tabeli
    operacja op1;
    operacja op2;
};

struct maszyna{
    int czas_do_konca;
    unsigned int ostatnie_zadanie;
};

struct kandydat{
    operacja * next;
    int ocena;
};

std::vector<operacja> zadania;
std::vector<operacja> przerwy;
maszyna maszyny[2];

unsigned int **feromony;

/**
 * Sprawdza czy zależność między operacjami jest spełniona
 * @param op
 * @return 
 */
bool zaleznosc(operacja *op, unsigned int time){
  /*  std::cout    <<  "Test zależności: P:"
            <<  op->prev<<" V:"
            <<  (zadania[op->prev].visited?1:0)
            <<  " GT:"
            <<  time
            <<  " ZT:"
            <<  zadania[op->prev].end
            <<  std::endl;*/
    if(op->prev != -1 && !zadania[op->prev].visited ||
       op->prev != -1 && zadania[op->prev].visited     && time<zadania[op->prev].end) 
        return false;
    return true;
}


#endif	/* INSTANCE_H */

