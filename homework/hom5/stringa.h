  class Stringa
  {
    public:
      Stringa();          
      /* COSTRUTTORE: 
       * NON parametrizzato: non alloca spazio. Lo spazio viene allocato da:
		   *  -- il secondo costruttore (con parametro C-string)
		   *  -- il costruttore di copia (inizializza con l'oggetto stringa 
       *     passato come parametro)
       */
      Stringa(char* str);                  
      /* COSTRUTTORE:
       *  inizializza l'oggetto con la c-string passata come parametro, dopo aver allocato la
       *  memoria necessaria.
       */ 
      Stringa(Stringa& o);                 
      /* COSTRUTTORE DI COPIA:
       * alloca la memoria e  inizializza l'ggetto a quello passato come parametro.
       */ 
      ~Stringa();                         
      /* DISTRUTTORE:
       * dealloca la memoria dinamica puntata da str.
       */       
      char get(unsigned int i);   // restituisce il carattere in posizione i-esima
      void set(char c, unsigned int i); // assegna il carattere c alla posizione i-esima
      unsigned int size(); // restituisce lunghezza della stringa (#caratteri)
      void clear();        // dealloca la stringa
      bool empty();        // la stringa è vuota ???
      
      char first(); 
      /* Restituisce il primo carattere della stringa str[0] oppure il terminatore
          se la stringa è vuota  
       */
      char last() ;                       
      /* Restituisce l'ultimo carattere della stringa str[num-1] oppure il terminatore 
          se la stringa è vuota
       */       
            
      Stringa& substr(unsigned int pos, unsigned int len); 
      /* Restituisce un NUOVO oggetto Stringa  contenente la sottostringa che inizia  alla
       *  posizione pos ed è lunga len caratteri. 
       *  NOTE
	     *  Se pos > num la chiamata genera un errore e termina il programma. 
	     *  Se pos+len > num nel nuovo oggetto vengono copiati solo i caratteri 
       *  che vanno da str[pos] fino a str[num]
       */ 
      
      int find_first(char c);   
      /* Cerca nella stringa la prima occorrenza del carattere c e 
       * ne restituisce la posizione, -1 altrimenti
       */ 
      int find_last(char c);   
      /* Cerca nella stringa l'ultima occorrenza del carattere c e 
       *  ne  restituisce la posizione, -1 altrimenti 
       */
      unsigned int max_size();
      // restituisce il massimo numero di caratteri che può essere contenuto. */

			/** ****************** FACOLTATIVI ****************** **/
      Stringa& insert(unsigned int pos,  Stringa& s); 
      /* INSERISCE la string str a partire  da pos. Effettua il ridimensionamento
          dell'array. 
       */ 
      Stringa& insert(unsigned int pos,  char *str); 
      /* INSERISCE la c-string str a partire  da pos. Effettua il ridimensionamento 
       * dell'array.
       */      
			int find(unsigned int pos, Stringa &s);   
      /* Cerca nella stringa la sottostringa s  a partire dalla posizione pos 
       *  e ne  restituisce la   * posizione, -1 altrimenti. FACOLTATIVO.
       */ 
      int find(unsigned int pos, char  *str);   
      /* Cerca nella stringa la sottostringa  str (c-string) a partire 
       *  dalla posizione pos e ne  restituisce la posizione, -1 altrimenti. FACOLTATIVO.
       */
     

                 
      /** OPERATORI DI CONFRONTO */
      bool operator==(Stringa& s);
      bool operator<=(Stringa& s);
      bool operator<( Stringa& s);
      bool operator>=(Stringa& s);
      bool operator>(Stringa& s);
      
      /** OPERATORI di I/O */
      friend ostream& operator<<(ostream& os,  Stringa& s);
      /* INSERITORE della classe.
       */ 
      /** ALTRI OPERATORI */
      Stringa& operator=(Stringa& s);    // Operatore di assegnazione
      Stringa& operator=(char* s);    // Operatore di assegnazione con C-string
      char& operator[](unsigned int i); // operatore []
      Stringa operator+(Stringa& op); // concatenazione
      friend Stringa operator+(char* str, Stringa& op);
      Stringa& operator+=(Stringa& op); // // concatenazione abbreiviato
      
            
      friend istream& operator>>(istream& is, Stringa& s);
      /** ESTRATTORE della classe.
       *  Legge dallo stream tutti i caratteri fino a :
       *   --  spazio (' ')
       *   -- tab     ('\t') 
       *   -- newline ('\n')
       */
      
      
    
      char* str; // puntatore alla vettore di caratteri 
      unsigned int num; // memorizza il numero di caratteri effettivamente presenti nel vettore 
      static unsigned int MAX_SIZE = 10000; // dimensione massima della stringa allocabile (10K)  
           
  };
