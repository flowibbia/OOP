  
  
  #include "studente.h"
  
  // DICHIARAZIONE delle funzioni
  void show_students (studente s[], int n, ostream &os);
  void write_students(studente s[], int n, ofstream &out);
  void read_students(studente s[],  int &n, ifstream &in);

  const int max_students = 100;
  const int max_name     = 256;
  
  // Variabile GLOBALE per la memorizzazione degli studenti caricati
  studente std_array[max_students];
  
  int main() 
  {    
    char f_name[max_name];
    ifstream in;
    ofstream out;
       
    int choice, n;
    
    do {
	cout<<endl<<"SCEGLIERE L'OPERAZIONE DA ESEGUIRE"<<endl;
	cout<<endl<<"0 --> Terminare il programma";
	cout<<endl<<"1 --> Visualizzazione di array ";
	cout<<endl<<"2 --> Caricamento da file di testo";
	cout<<endl<<"3 --> Caricamento da file binario ";
	cout<<endl<<"4 --> salvataggio su file di testo";
	cout<<endl<<"5 --> salvataggio su file binario ";
	
	cout<<endl<<"operazione: ";
	cin>>choice;
	cin.ignore();
	
	switch(choice) {
	  // TERMINAZIONE del programma
	  case 0:
	    cout<<endl<<"programma terminato!"<<endl;
	    exit(1);
	    
	  // VISUALIZZAZIONE
	  case 1:	    
	    if (n) {
	      cout<<endl<<"elenco studenti: "<<endl;
	      show_students(std_array, n, cout);	      
	    }
	    else cout<<"elenco vuoto!!";
	    // end case 1
	    break;
	    
          // CARICAMENTO da file di testo
	  case 2:   
	    cout<<endl<<"scrivere il nome del file di input :"<<flush;
	    cin.getline(f_name, max_name);    
            // Si apre lo stream
           in.open(f_name);
	   // Si controlla la corretta apertura dello stream
	   if (!in) {
	     cout<<"ERRORE!: impossibile aprire il file: "<<f_name<<endl;
	     exit(EXIT_FAILURE);
	   }   
	   // Si carica l'array
           n=0;
	   while (std_array[n].input(in))
           n++;
	   // Si verifica l'effettiva lettura di almeno un elemento
	   if (n)
	     cout<<endl<<"sono stati caricati "<<n<<" studenti"<<endl;
	   else cout<<endl<<"ERRORE!: file VUOTO!";
	   // Si chiude lo stream
	   in.close();
	   // end case 2
	   break;
	   
	  // CARICAMENTO da file binario
	  case 3:
	    cout<<endl<<"scrivere il nome del file di input (binario):"<<flush;
	    cin.getline(f_name, max_name);    
	    // Si apre lo stream
	    in.open(f_name, ios::binary);
	    // Si controlla la corretta apertura dello stream
	    if (!in) {
	      cout<<"ERRORE!: impossibile aprire il file: "<<f_name<<endl;
	      exit(EXIT_FAILURE);
	    }
	    // Si scrive nello stream in modalità binaria
	    read_students(std_array, n, in);
	    // Si verifica l'effettiva lettura di almeno un elemento
	    if (n)
	      cout<<endl<<"sono stati caricati "<<n<<" studenti"<<endl;
	    else cout<<endl<<"ERRORE!: file VUOTO!";
	    // Si chiude lo stream
	   in.close();
	   // end case 3
	   break;
	   
	   // SALVATAGGIO su file di testo
	  case 4:
	    cout<<endl<<"scrivere il nome del file di output (testo) :"<<flush;
	    cin.getline(f_name, max_name);    
	    // Si apre lo stream di output in modalità testo
	    out.open(f_name);	    
	    // Si controlla la corretta apertura dello stream
	    if (!out) {
	      cout<<"ERRORE!: impossibile aprire il file: "<<f_name<<endl;
	      exit(EXIT_FAILURE);      
	    }	    
	    // L'array viene scritto nello stream di  output appena aperto
	    show_students(std_array, n, out);   
	    // Si chiude lo stream 
	    out.close();
	    // end case 4
	   break;
	   
	  // SALVATAGGIO su file binario
	  case 5:
	    cout<<endl<<"scrivere il nome del file di output (binario) :"<<flush;
	    cin.getline(f_name, max_name);    
	    // Si apre lo stream di output in modalità BINARIA
	    out.open(f_name, ios::binary);	    
	    // Si controlla la corretta apertura dello stream
	    if (!out) {
	      cout<<"ERRORE!: impossibile aprire il file: "<<f_name<<endl;
	      exit(EXIT_FAILURE);      
	    }    
	    // L'array viene scritto nello stream di  output appena aperto
	    write_students(std_array, n, out);   
	    // Si chiude lo stream 
	    out.close();
	    // Fine case 5
	   break;
	}
    } while (choice != 0);
    
    
    return 0;  
  }
  
  // Visualizza gli studenti del vettore s sullo stream o passato come parametro
  void show_students(studente s[], int n, ostream &os)
  {
    int i;
    
    for (i=0; i < n; ++i)
       s[i].output(os);
    
    return;    
  }
  
  /************  Funzioni di I/O BINARIO ************/
  
  // Scrive, in modalità binaria, gl elementi del vettore s nell stream out
  
  void write_students(studente s[], int n, ofstream &out)
  {
    int dim, i;
    char *ptr; 

    dim = n * sizeof(studente);
    ptr = (char *) s; 

    for(i=0; i < dim; ++i)
      out.put(ptr[i]);

    return;
  }
  
  // Legge dallo stream in (binario), n elementi e li copia nel vettore s  
  void read_students(studente s[], int &n, ifstream &in)
  {
    int max, i;
    char *ptr; 

    max = max_students * sizeof(studente); 
    ptr = (char *) s; // CASTING

    i=0;
    while((in.get(ptr[i])) && (i < max))
      ++i;

    n = i / sizeof(studente);

    return;
  }