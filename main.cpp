/* 
 * File:   main.cpp
 * Author: kuba
 *
 * Created on 9 styczeń 2015, 00:35
 */

#include <cstdlib>
#include "instance.h"
#include "loadInstance.h"
#include "aco.h"

#define iterations 100
#define ants 5



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout <<"ACO Grzeszczuk&Malczewski" << endl;
    loadFile("p2.in");
    aco(
            iterations,
            ants
            );
    return 0;
}

