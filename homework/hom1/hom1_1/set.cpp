#include <iostream>
// Definzione del tipo di dato della coda
typedef int TipoValue;

#include "set.h"
using namespace std;

/** *****  Funzione di INIZIALIZZAZIONE   *******/
void Set::init()
{
  v = new TipoValue[4];
  len=4;
  n=0;
}

/** *****  Restituisce la CARDINALITÀ dell'insieme   *******/
int Set::size()
{
  return n;
}

/*******  insieme PIENO???   *******/
bool Set::full()
{
  return (n == len);  
}

/*******  insieme VUOTO???   *******/
bool Set::empty()
{
  return (n == 0);
}

/** *****  funzione di RICERCA   *******/
bool Set::member(TipoValue el)
{
  for (int i = 0; i < n; i++)
    if (v[i] == el)
      return true;

  return false;
}

/** *****  funzione di CANCELLAZIONE   *******/
void Set::remove(TipoValue el)
{
  int i;
  bool found;

  

  i = 0;
  found = false;
  while ((i < n) && (!found))
    if (v[i] == el)
    {
      elim(i);
      found = true;
    }
    else
      ++i;

  if (found)
    n--;

  
  return;
}

/** *****  funzione di CANCELLAZIONE TOTALE  *******/
void Set::clear()
{
  delete[] v;
  new TipoValue[2];
  len=2;
  n = 0;
}

/** *****  funzione di VISUALIZZAZIONE TOTALE  *******/
void Set::show()
{
  int i;

  cout << endl;
  for (i = 0; i < n; ++i)
    cout << v[i] << " ";
  cout << endl;
}

/** *****  AGGIUNGE el    *******/
void Set::add(TipoValue el)
{
  if (n == len)
    change_dim(2);

  std::cout << "add()";
  if (!member(el))
    v[n++] = el;

}
/** *****  funzione (ausiliaria) di ELIMINAZIONE: *******
   ** *****  elimina l'elemento di indice pos       *******/

void Set::elim(int pos)
{
  //quando vengono eliminati il 25% degli elementi, alloco 
  if(n<=len/4){
    change_dim(0.25);
  }
  int i;
  for (i = pos; i < n - 1; i++)
    v[i] = v[i + 1];

  return;
}

void Set::change_dim(float f)
{
  //aggiornamento len
  len=len*f;

  //allocazione nuovo array
  TipoValue *temp = new TipoValue[len];

  //copia dei valori in un nuovo array 
  for(int i=0;i<n;i++)
    temp[i]=v[i];

  //deallocazione memoria vecchio array
  delete [] v;
  std::cout<<"\n la lunghezza dell'array ora è: "<<len<<"\n";

  //faccio puntare v al nuovo array allocato in memoria
  v=temp;

}