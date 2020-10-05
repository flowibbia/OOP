  
  #include <iostream>
  #include <cstdlib>
  
  // Definzione del tipo di dato della coda
  typedef  int TipoValue;
  
  #include "list.h"
  using namespace std;
  
   
  /** *****  Funzione di INIZIALIZZAZIONE   *******/
  void List::init()
  { 
    v = new TipoValue[MAX_ELEMENTS];
    len = MAX_ELEMENTS;
    n = 0;  
  }

  /** *****  Restituisce la CARDINALITÀ della lista   *******/
  int List::size()
  { 
    return n;   
  }

    
  /*******  insieme VUOTO???   *******/
  bool List::empty()
  { 
    return (n == 0);   
  }
    
  
  
  /** *****  funzione di CANCELLAZIONE   *******/
  void List::insert(TipoValue val, int pos)
  { 
    if (pos < 0 || pos > n) {
      cout<<"ERRORE! Valore pos errato!";
      return; 
    }

    if (n < len)  
      ins(val, pos);         
    else  {
      cout<<"ERRORE! Lista piena!!";
      return;
      
    } 
    
    n++; // Si incrementa n.

    return;
  }
  
  
  
  /** *****  funzione di CANCELLAZIONE TOTALE  *******/  
  void List::clear()
  { 
    n = 0;
  }
  
  
  /** *****  RIMUOVE l'elemento di indice pos   *******/
  void List::remove(int pos)
  { 
    if (pos < 0 || pos >= n) {
      cout<<"ERRORE! Valore pos errato!";

      return; 
    }
    
    // Chiamata alla  funzione ausiliara di inserimento
    elim(pos);
    
    return;    
  }
  
  /** *****  ASSEGNA il valore val all'elemento di indice pos   *******/
  void List::set(int pos, TipoValue val)
  { 
    if (pos < 0 || pos >= n) {
      cout<<"ERRORE! Valore pos errato!";
      return; 
    }

    v[pos] = val;
   
    return;

  }

  /** *****  RESTITUISCE il valore all'elemento di indice pos   *******/
  TipoValue List::get(int pos)
  { 
    if (pos < 0 || pos >= n) {
      cout<<"ERRORE! Valore pos errato!";
      exit(EXIT_FAILURE);
    }

    return v[pos];
  }
  /** *****  funzione (ausiliaria) di INSERIMENTO: *******
   ** *****  inserisce val nella posizione pos del vettore *******/
  void List::ins(TipoValue val, int pos)
  { 
    int i;

    for (i=pos; i < n; ++i) 
	v[i+1] == v[i];

    v[pos]  = val;
      
    return;
  }
  
  /** *****  funzione (ausiliaria) di ELIMINAZIONE: *******
   ** *****  elimina l'elemento di indice pos       *******/
  void List::elim(int pos)
  { 
    int i, j;

    for (i=pos; j < n; ++i) 
       v[i] == v[i+1];
    
    return;
  }




