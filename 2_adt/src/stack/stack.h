  const int MAX_ELEMENTS = 1000;

   
  
  struct Stack {

  void init(int l);          // funzione di inizializzazione
  bool empty();              // controlla se la lista è vuota
  bool full();               // controlla se la lista è piena
  
  TipoValue top();           // fornisce l'elemento in testa
  void push(TipoValue val);  // inserimento in testa di val
  TipoValue pop();           // fornisce e rimuove l'elemento in testa
  private:
    TipoValue *v;   	     // array per la memorizzazione 
    int last;                // punta all'ultimo elemento inserito
    int len;		     // cardinalità del vettore
  };
