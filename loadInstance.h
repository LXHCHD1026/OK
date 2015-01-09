/* 
 * File:   loadIstance.h
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 00:35
 */

#ifndef LOADISTANCE_H
#define	LOADISTANCE_H


#include <fstream>
#include <iostream>
#include <string>

#include "instance.h"

    using namespace std;
    
    int liczba_zadan;
    int liczba_przerw;
    
    bool loadFile(string src){
        ifstream plik;
        plik.open(src.c_str());
        if (!plik.good()) return false; //nie ma takiego pliku
        plik >> liczba_zadan;
        cout << "Liczba zadań " << liczba_zadan << endl;
        for(int i =0; i<liczba_zadan; i++)
        {
            
            zadania.push_back(zadanie());
            char c;
            plik >> zadania[i].op1.czas >>c >> zadania[i].op2.czas >>c >> zadania[i].op1.maszyna >>c >> zadania[i].op2.maszyna >>c;
            cout<<"Zadanie "<< zadania[i].op1.czas <<" "<< zadania[i].op2.czas<<" " << zadania[i].op1.maszyna<<" " << zadania[i].op2.maszyna<<endl;
            
        }
       int i=0;
       do
        {
            char c;
            przerwy.push_back(operacja());
            plik >> przerwy[i].id >> c>> przerwy[i].maszyna>>c>>przerwy[i].czas>>c>>przerwy[i].start>>c;
            
            i++;
        }
       while(!plik.eof());
       przerwy.pop_back();
       
       for(i=0; i< przerwy.size(); i++)
           cout <<"Przerwa "<<przerwy[i].id<<" "<<przerwy[i].maszyna<<" "<<przerwy[i].czas<<" "<<przerwy[i].start<<endl;
       
        
    }
    
    void clearInstance(){
        //for(size_t i = 0; i<zadania.size(); i++)
           // delete *zadania[i];
    }

#endif	/* LOADISTANCE_H */

