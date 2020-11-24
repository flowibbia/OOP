  #include <iostream>
  #include <fstream>
  #include <cstdlib>
  #include <cstring>
  

  using namespace std;
  
  const int MAX_NAME = 256;
  const int MAX_LINE = 100000;
	const char DELIMS[] = " \t,;";
  
  
  bool comp_dim(ifstream &in, int &r, int &c);
  float** alloc_mat(int r, int c);
  void load_mat(ifstream &in, float **mat, int rows, int cols);
  void show_mat(ostream *out, float **mat, int rows, int cols);
	int compCols(ifstream &in, const char *delim);
 
  int main() {
    ifstream infile;   
    ofstream outfile;
    char in_name[MAX_NAME];
    float **matr;
    int rows, cols;

		// Chiedere all'utente il nome del file di ingresso
       
    // Apertura del file

		// Calcolo di #righe e #colonne		 

		// gestione dello stream
    
    
       
    // Si alloca la matrice
   
    
    // Si carica la matrice 
   
    
    
    // Si visualizza la matrice
   
    
     
           

    return 0; 
  }
