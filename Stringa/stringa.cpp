#include <cstdlib>
#include <iostream>
#include <cstring>
#include "stringa.h"

using namespace std;

Stringa::Stringa(unsigned int l)
{
    num=l;
    str= new char[l];
}

Stringa::Stringa(char *s)
{
    int l=0;
    l=strlen(s);
    str=new char[l];
    strcpy(str,s);     
}

Stringa::Stringa( Stringa &s)
{
    num=s.size();
    str=new char[num];
    strcpy(str,s.str);
}

Stringa::~Stringa()
{
    delete[] str;
    num=0;
}

void Stringa::clear()
{
    for(int i=0; i<num; i++)
        set(' ',i);
    num=0;
}
void Stringa::leggi(char *s)
{
    if(strlen(s)>num)
    {
        cout << endl << "Stringa s troppo grande";
        return;
    }
    else
    {
        strcpy(str,s);
        num=strlen(s);
    }
}