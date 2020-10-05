  
  #include <iostream>
  #include <cstdlib>
  
  // Definzione del tipo di dato della coda
  typedef  int TipoValue;
  
  #include "queue.h"
  using namespace std;
  
   
  /** *****  Funzione di INIZIALIZZAZIONE *******/
  void Queue::init(int l)
  { 
    v = new TipoValue[l];
    h = t = 0;  
    len = l; 
  }

  /** *****  Restituisce la LUNGHEZZA della coda *******/
  int Queue::size()
  { 
    if (t >= h)
      return (t - h);
    else return (len - (h - t));
  }

  /*******  insieme PIENA???   *******/
  bool Queue::full()
  { 
    return (((t + 1) % len) == h);
  }
  
  /*******  insieme VUOTO???   *******/
  bool Queue::empty()
  { 
    return (h == t);
  }
  
  
  /** *****  restituisce la TESTA, senza eliminarla   *******/
  TipoValue Queue::head()
  { 
    if (!empty())  
      return v[h];
    else {
      cout<<"ERRORE: coda vuota!";
      exit(EXIT_FAILURE);
    }
  }
  
  /** *****  AGGIUNGE in CODA  *******/
  void Queue::add(TipoValue val)
  { 
    if (!full()) 
      v[t] = val;
    else {
      cout<<"ERRORE: coda piena!";     
      return;
    }

    // si incrementa la  coda (BUFFER CIRCOLARE);
    t = (t + 1) % len;
      
    return;
  }

    
  
  /** *****  PRELEVAMENTO dalla TESTA *******/  
  TipoValue Queue::take()
  { 
    TipoValue tmp;
    
    if (!empty())  
      tmp = v[h]; // Si memorizza la testa
    else { 
      cout<<"ERRORE: coda vuota!";
      exit(EXIT_FAILURE);
    }
  
    // si incrementa la testa (BUFFER CIRCOLARE).
    h = (h + 1) % len;

    return tmp;
  } 