  
  #include <iostream> 
  
  // Definzione del tipo di dato della coda
  typedef  int TipoValue;
  
  #include "set.h"
  using namespace std;
  
   
  /** *****  Funzione di INIZIALIZZAZIONE   *******/
  void Set::init(int l)
  { 
    v = new TipoValue[l];
    len = l;
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
    int i;

    for (i=0; i < n; ++i)    
	if (v[i] == el) 
	  return true;             
      
    return false;
  }
  
  /** *****  funzione di CANCELLAZIONE   *******/
  void Set::remove(TipoValue el)
  { 
    int i;
    bool found;

    i=0;
    found = false;
    while ((i < n) && (!found))    
      if (v[i] == el) {
	      elim(i);
	      found = true;
      } else ++i;
  
    if (found)
      n--;
      
    return;
  }
  
  
  
  /** *****  funzione di CANCELLAZIONE TOTALE  *******/  
  void Set::clear()
  { 
    n = 0;
  }

 /** *****  funzione di VISUALIZZAZIONE TOTALE  *******/  
  void Set::show()
  { 
    int i;

    cout<<endl;
    for (i=0; i < n; ++i)
       cout<<v[i]<<" ";
    cout<<endl;
  }
 
  /** *****  AGGIUNGE el    *******/
  void Set::add(TipoValue el)
  { 
    if (!full()) {
      if (!member(el))
	v[n++] = el;
    }
    else cout<<endl<<"ERRORE: vettore pieno";


  }
  
  /** *****  funzione (ausiliaria) di ELIMINAZIONE: *******
   ** *****  elimina l'elemento di indice pos       *******/
  void Set::elim(int pos)
  { 
    int i;

    for (i=pos; i < n - 1; ++i) 
       v[i] == v[i+1];
    
    return;
  }




