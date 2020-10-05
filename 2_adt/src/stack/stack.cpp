  
  #include <iostream>
  #include <cstdlib>
  
  // Assegnazione di tipo
  typedef int TipoValue;
  
  #include "stack.h"
  using namespace std;
  
   
  /** *****  Funzione di INIZIALIZZAZIONE   *******/
  void Stack::init(int l)
  { 
    v = new TipoValue[l];
    len = l;
    last = -1;
  
    return;
  }

 

  /** *****  pila PIENA???   *******/
  bool Stack::full()
  { 
    return (last + 1 == len);   
  }
  
  /** *****  pila VUOTA???   *******/
  bool Stack::empty()
  { 
    return (last  == -1);   
  }
  
    
  /** *****  restituisce l'elemento in testa    *******/
  TipoValue Stack::top()
  { 
    if (last >= 0)  
      return v[last];
    else {
      cout<<"ERRORE: stack vuoto!";    
      exit(EXIT_FAILURE);
    }
  }  
  
  
  
  
  /** *****  AGGIUNGE val  in testa   *******/
  void Stack::push(TipoValue val)
  { 
    if (last < len)  
      v[++last] = val;
    else cout<<"ERRORE: stack pieno";
    
    return;
  }
  
  /** *****  ESTRAE l'elemento in TESTA *******/
  TipoValue Stack::pop()
  { 
    if (last >= 0)  
      return v[last--];
    else {
      cout<<"ERRORE: stack vuoto!";    
      exit(EXIT_FAILURE);
    } 
    
  }  