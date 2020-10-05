  
  #include <iostream>
  #include <fstream>
  #include <cstdlib>
  #include <cstring>
  using namespace std;
  
  
  const int max_string = 10000;

  struct studente {
	  char nome[max_string];
	  char cognome[max_string];
	  int  matr;
	  void input();  // input da utente
	  bool input(ifstream &in);  // input da file
	  void output(ostream &out); // output su file/schermo 
  };
