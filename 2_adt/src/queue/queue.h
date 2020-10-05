  const int MAX_ELEMENTS = 1000;

    
  struct Queue {

    void init(int l); 		// funzione di inizializzazione
    int size();       		// restituisce la lunghezza della coda
    bool full();      		// controlla se la coda è piena
    bool empty();     		// controlla se la coda è vuota
    void add(TipoValue val); 	// aggiunta di un elemento
    TipoValue take();        	// estrazione
    TipoValue head();        	// restituisce la testa

    private:  
    TipoValue *v;  // array di elementi    
    int h;         // Punta alla testa della coda
    int t;         // Punta all'ultimo elemento della coda
    int len;       // capacità della coda
  };