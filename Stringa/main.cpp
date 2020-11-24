/* 
 * File:   main.cpp
 * Author: Felice
 *
 * Created on 24 giugno 2013, 14.47
 */

#include <cstdlib>
#include <iostream>
#include "stringa.h"


using namespace std;

int main(int argc, char** argv) {
    Stringa a(4);
    a.leggi("trye");
    cout << endl << "Leggo primo char " << a.first();
    cout << endl << "Leggo ultimo char " << a.last();
    return 0;
}

