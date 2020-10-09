  const int MAX_ELEMENTS = 1000;

    
  struct Set {
      void init();			// funzione di inizializzazione.
      int  size();			// restituisce la cardinalità dell'insieme.
      bool full();			// restituisce TRUE se è pieno.
      bool empty();			// restituisce TRUE se è vuoto.
      void clear();			// cancella tutti gli elementi 
      void add(TipoValue el);	// aggiunge  l'elemento el
      void remove(TipoValue el); 		// elimina l'elemento el  
      bool member(TipoValue el);  	// restituisce TRUE se el è presente.
      void show();

    private:
      TipoValue *v;
      int  n, len;
      void elim(int i); // funzione di eliminazione
      void change_dim(float f);
  };
