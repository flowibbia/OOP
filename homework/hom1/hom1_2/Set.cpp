#include <iostream>
typedef int TipoValue;

#include "Set.h"
using namespace std;

/** *****  Funzione di INIZIALIZZAZIONE   *******/
void Set::init(bool (*eq)(TipoValue,TipoValue),bool (*lt)(TipoValue,TipoValue))
{
  v = new TipoValue[4];

  //inizializzazione puntatore a funzione per il la gestione del sort
  eq_fptr=eq;
  lt_fptr=lt;

  //inizializzazione 
  len = 4;
  n = 0;
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
  return search_bin(el);
}

/** *****  funzione di CANCELLAZIONE   *******/
void Set::remove(TipoValue el)
{
  int i;
  bool found;

  i = 0;
  found = false;
  while ((i < n) && (!found))
    if ((*eq_fptr)(v[i] , el))
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
  len = 2;
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

  if(member(el))
    return;
  //inserimento ordinato nell'array
  int i;
  for (i = n - 1; (i >= 0 && (*lt_fptr)(el,v[i])); i--)
    v[i + 1] = v[i];

  v[i + 1] = el;

  n++;
}

/** *****  funzione (ausiliaria) di ELIMINAZIONE: *******
   ** *****  elimina l'elemento di indice pos       *******/
void Set::elim(int pos)
{
  //quando vengono eliminati il 25% degli elementi, alloco
  if (n <= len / 4)
  {
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
  len = len * f;

  //allocazione nuovo array
  TipoValue *temp = new TipoValue[len];

  //copia dei valori nel un nuovo array
  for (int i = 0; i < n; i++)
    temp[i] = v[i];

  //deallocazione memoria vecchio array
  delete[] v;

  std::cout << "\n la lunghezza dell'array ora è: " << len << "\n";

  //faccio puntare v al nuovo array allocato in memoria
  v = temp;
}

/** *****  funzione (ausiliaria) di INSERIMENTO: *******
   ** *****  inserisce val nella posizione pos del vettore *******/
void Set::ins(TipoValue val, int pos)
{

  std::cout << n << std::endl;

  if (n > 0)
  {
    for (int i = n; i > pos; i--)
      v[i] = v[i - 1];
  }

  v[pos] = val;
  n++;
  return;
}

bool Set::search_bin(int el)
{

  //ricerca binaria
  int start = 0;
  int end = n - 1;
  int pos = (start + end) / 2;

  while (start <= end)
  {
    pos = (start + end) / 2;
    //  std::cout<<"pos in search()"<<pos<<std::endl;

    if ((*eq_fptr)(v[pos], el)) //is_equal(v[pos],el)
      return true;    //element is in the set, and it must not be added in the set
    else if ((*lt_fptr)(v[pos] , el))
      start = pos + 1;
    else
      end = pos - 1;
  }
  //restituisce la posizione in cui va inserito l'elemento
  return false;
}
