
  #include <iostream>  
  #include "studente.h"
  
   void studente::input() {
    cout<<"inserire cognome: ";
    cin>>cognome; 
    cout<<"inserire nome: ";
    cin>>nome; 
    cout<<"inserire matricola: ";
    cin>>matr; 
    cout<<"inserire il reddito: ";
    cin>>red; 
  }
  
  void studente::output() {
    cout<<endl<<"cognome: ”<<cognome; 
    cout<<endl<<"nome: ”<<nome; 
    cout<<endl<<"matricola: ”<<matr; 
    cout<<endl<<"reddito: ”<<red;
    out<<endl;
  }   

  void inputStudenti( int &n, Studente v[])‏ 
  { 	 
    int i;  // indice di scorrimento del vettore 

  cout<<"Quanti elementi vuoi inserire? ";
  cin>>n; 

  //assegnaz. di valore agli elementi dell'array 
  cout<<"Inserisci "<<n<<" studenti"<<endl; 

  for (i=0; i < n; i++)‏ 
	    s[i].input(); 
  }

  void outputStudenti(int n, Studente v[])‏ 
  { 
    int i;  // indice di scorrimento del vettore 

    cout<<"Elenco studenti"; 
   
    for (i=0;i < n;i++)‏ {
	cout<<"studente # "<<i + 1<<endl; 
	s[i].output();
    } 
  }
  
  // Ricerca dell'indice dello studente con reddito massimo
  int ric_max_red(int n, Studente v[])
  {
    int i, m;
    
    m = 0;
    for (i=1;i < n; i++)‏
       if (v[i].red > v[m].red)
	 m = i;
        
    return m;
  }
  
  
  void aggiungiStudente(int &n, Studente v[], Studente s)
  {
    if (n == MAX_STUDENTS) {
      cout<<endl<<"ERRORE!: array pieno!!"
      exit(0);      
    }
    
    v[n++] = s;
    
    return;
  }
  
  
  