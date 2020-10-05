  #include <iostream>
  #include <fstream>
  #include <stdlib.h>
  
  const int MAX_NAME = 256;
  const int MAX_VET  = 1000;
  

  // Definizione del tipo
  typedef int TipoValue;
  
  #include "linked-list.h"

  using namespace std;
  
  
  // DICHIARAZIONE delle funzioni
  int copy_file(ifstream &in, ofstream &out);
  bool open_stream(fstream &s, bool out);
  void file2vec(fstream &in, TipoValue v[], int &n);
  int  vec2file(fstream &out, TipoValue v[], int n);

  

  int main() {
    
    fstream instream,  outstream;
    char in_name[MAX_NAME], out_name[MAX_NAME];    
    int  choice, n;
    TipoValue vec[MAX_VET];
    nodo *l;
    
    do {
	cout<<endl<<"SCEGLIERE L'OPERAZIONE DA ESEGUIRE"<<endl;
	cout<<endl<<"0 --> terminare il programma";
	cout<<endl<<"1 --> da file a vettore";
	cout<<endl<<"2 --> da file a lista";	
	cout<<endl<<"3 --> da vettore a file";
	cout<<endl<<"4 --> da lista a vettore";
	
	cout<<endl<<"operazione: ";
	cin>>choice;
	cin.ignore();

	switch(choice) {
	  // TERMINAZIONE del programma
	  case 0:
	    cout<<endl<<"programma terminato!"<<endl;
	    exit(1);
	    
	  // FILE --> VETTORE
	  case 1:	    
	    // si apre lo stream in input
	    if (open_stream(instream, false)) {
	      file2vec(instream, vec, n);
	      cout<<endl<<"è stato caricato il seguente vettore:"<<endl;
	      vec2file((fstream &) cout, vec, n);
	    }
/*	    
	    cout<<endl<<"digitare il nome del file di input: ";
            cin.getline(in_name, MAX_NAME);
            infile.open(in_name);
	    if (!infile) 
              cout<<endl<<"ERRORE!: impossibile aprire il file: "<<in_name;
	    else loaded = true;
	    */
	    break;
	      

	  // FILE --> LISTA
	  case 2:
	    if (open_stream(instream, false)) {
	      file2list(instream, l);
	      cout<<endl<<"è stata caricata la seguente lista:"<<endl;
	      list2file((fstream &)  cout, l);
	    }
	     /*cout<<endl<<"digitare il nome del file di output: ";
            cin.getline(out_name, MAX_NAME);
            outfile.open(out_name);
	    if (!outfile) {
              cout<<endl<<"ERRORE!: impossibile aprire il file: "<<out_name;
              break;      
            }*/
	    
	    
	    break;
	  
	  // VETTORE --> FILE
	  case 3:
	    
	    /*cout<<endl<<"digitare il nome del file cifrato: ";
            cin.getline(out_name, MAX_NAME);
            outfile.open(out_name);
	    if (!outfile) {
              cout<<endl<<"ERRORE!: impossibile aprire il file: "<<out_name;
              break;      
            }*/
	    if (open_stream(outstream, true)) {
	      vec2file(outstream, vec, n);
	    }
	    break;  
	    
          // LISTA --> FILE
	  case 4:
	    // Si controlla se il file di input è stato precedentemente caricato
	    if (open_stream(outstream, true)) 
	      list2file(outstream, l);
	      
	    
	    break;
	  
	  //break;  
        }
    } while (choice != 0);
    
    return 0;
  }
  
  /* Apre lo stream passato come primo parametro, il parametro out 
   * specifica se è uno stream di output.                               
   */
  bool open_stream(fstream &s, bool out)
  {
    char f_name[MAX_NAME];
    
    // Si controlla innanzituttto che lo stream non sia gia aperto
    //if (s)
      s.close();
    
    
    cout<<endl<<"digitare il nome del file da aprire: ";
    cin.getline(f_name, MAX_NAME);
    
    // Si controlla se è uno stream di output
    if (out)
      s.open(f_name, ios::out);    
    else s.open(f_name, ios::in);
    
    // Si controlla se lo stream è stato aperto correttamente
    if (!s) {
      cout<<endl<<"ERRORE!: impossibile aprire il file: "<<f_name; 
      return false;
    } else return true;
  
  }
  
  /* estrae dallo stream di input (primo parametro), e memorizza 
   * nel vettore v (secondo parametro). il parametro n 
   * (passato per riferimento) rappresenta il numero di valori
   * effettivamente estratto dall stream.
   */ 
  void file2vec(fstream &in, TipoValue v[], int &n)
  {
    n=0;
    
    while(in>>v[n])  
      n++;

    return;
  }
  
    
  /* inserisce nello stream di output (primo parametro), gli elementi 
   * del vettore v (secondo parametro). il parametro n (passato per 
   * valore) rappresenta il numero di valori da inserire.   
   */
  int vec2file(fstream &out, TipoValue v[], int n)
  { 
    int i;
  
    i=0;
    while (i < n && out) 
       out<<v[i++]<<" ";
    
    out.flush();

    return i;
  }
  
 
