/* 
 * File:   instance.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 00:41
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include <vector>
struct operacja{
    unsigned int czas;     // czas wykonania operacji
    unsigned int maszyna;  // numer maszyny na której ma zostać wykonany
    unsigned int start;    // czas rozpoczęcia operacji
    unsigned int id;       // identyfikator operacji
};

struct zadanie{             //zadanie identyfikuje indeks w tabeli
    operacja op1;
    operacja op2;
};


std::vector<zadanie> zadania;
std::vector<operacja> przerwy;


#endif	/* INSTANCE_H */

