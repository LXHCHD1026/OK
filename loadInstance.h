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
        int i=0;
        while (i<liczba_zadan*2)
        {
            
            zadania.push_back(operacja());
            zadania.push_back(operacja());
            char c;
            plik >> zadania[i].czas >>c >> zadania[i+1].czas >>c >> zadania[i].maszyna >>c >> zadania[i+1].maszyna >>c;
            zadania[i+1].prev = i;
            zadania[i].prev = 0;
            zadania[i].id = i;
            zadania[i+1].id = i+1;
            zadania[i].zad_id = i;
            zadania[i+1].zad_id = i;
            cout<<"Zadanie "<< zadania[i].czas <<" "<< zadania[i+1].czas<<" " << zadania[i].maszyna<<" " << zadania[i+1].maszyna<<endl;
            i+=2;
            
        }
        i = 0;
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
    
    /**
     * Resetuje feromony
     */
    void initInstance(){
       // cout << "Liczba zadan " << liczba_zadan*2 << endl;
             
        feromony = new unsigned int *[liczba_zadan*2];
        for(int i = 0; i<liczba_zadan*2; i++)
        {
            feromony[i] = new unsigned int[liczba_zadan*2];
            for(int j = 0; j<liczba_zadan*2; j++)
                feromony[i][j] = 0; ///startowe feromony
        }
    }
    
    void clearInstance(){
        for(int i = 0; i<liczba_zadan*2; i++)
            delete[] feromony[i];
            delete[] feromony;
    }

#endif	/* LOADISTANCE_H */

