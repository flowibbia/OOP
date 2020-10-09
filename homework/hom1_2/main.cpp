#include <iostream>

typedef int TipoValue;
#include "Set.h"

bool less_than(TipoValue a,TipoValue b){
  return a<b;
} 
bool is_equal(TipoValue a, TipoValue b){
  return a==b;
}

int main()
{
  Set *s;
  s = new Set;
  TipoValue tmp;
  int num;

  bool (*eq_fptr) (TipoValue, TipoValue)=is_equal;
  bool (*lt_fptr) (TipoValue, TipoValue)=less_than;


  s->init(eq_fptr,lt_fptr);

  std::cout << "inserire numero di elementi da inserire nell'insieme: ";
  std::cin >> num;

  for (int i = 0; i < num; i++)
  {
    std::cout << std::endl
              << "inserisci elemento " << i << "-esimo: ";
    std::cin >> tmp;
    s->add(tmp);
  }

  //stampa degli elementi inseriti nell'insieme, ed il numero
  s->show();

  std::cout << "inseriti" << s->size() << " " << std::endl;

  std::cout << "inserire quanti elementi si vogliono eliminare: ";
  std::cin >> num;
  std::cout << std::endl;
  for (int i = 0; i < num; i++)
  {
    std::cout << "inserire valore dell'elemento che si vuole eliminare: ";
    int tmp;
    std::cin >> tmp;
    s->remove(tmp);
  }

  //stampa degli elementi rimasti nell'insieme, ed il numero
  s->show();
  std::cout << "elementi rimasti: " << s->size() << std::endl;

  delete s;
}
