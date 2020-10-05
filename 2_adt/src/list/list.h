  const int MAX_ELEMENTS = 1000;

    
  struct List{
    void init();                         // funzione di inizializzazione.
    int  size();                          // restituisce il numero di elementi.    
    void  clear();                         // svuota la lista
    bool empty();                         // lista vuota?
    void insert(TipoValue val, int pos); // inserisce il valore val alla posizione pos
    void remove(int pos);                // rimuove l'elemento  nella posizione pos
    void set(TipoValue val, int pos);    // assegna il valore val all'i-esima posizione.
    TipoValue get(int pos);              // restituisce il valore dell'elemento 
                                         // alla  posizione pos.
  private:
      TipoValue *v;
      int n, len;      
      void ins(TipoValue val, int pos);  // funzione ausiliaria di inserimento
      void elim(int pos);                // funzione ausiliaria per l'eliminazione
  };