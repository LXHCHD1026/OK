/* 
 * File:   instance.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 00:41
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include <vector>

#define MASZYNA1 1

struct operacja{
    unsigned int czas;     // czas wykonania operacji
    unsigned int maszyna;  // numer maszyny na której ma zostać wykonany
    unsigned int start;    // czas rozpoczęcia operacji
    unsigned int id;       // identyfikator operacji
    bool visited;          // czy został odwiedzony?
    int prev;              // numer zadanie które musi zostać wykonane przed
    unsigned int id;       // id operacji
};

struct zadanie{             //zadanie identyfikuje indeks w tabeli
    operacja op1;
    operacja op2;
};

struct maszyna{
    unsigned int czas;
};

struct kandydat{
    operacja * next;
    unsigned int ocena;
};

std::vector<operacja> zadania;
std::vector<operacja> przerwy;
maszyna maszyny[2];

unsigned int **feromony;


#endif	/* INSTANCE_H */

