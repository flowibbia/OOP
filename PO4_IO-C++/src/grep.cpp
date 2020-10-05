  #include <iostream>
  #include <fstream>
  #include <cstring>
  

  const int MAX_NAME = 256;
  const int MAX_LINE = 100000;

  using namespace std;
  
  
  // DICHIARAZIONE delle funzioni
  bool open_stream(fstream &s, bool out);
  void show_file(fstream &in);
  bool grep(fstream &in, const char str[]);
  

  int main() {
    fstream instream;
    char str[MAX_LINE];
    
    
        
    // Si apre lo stream e si controlla se è stato aperto correttamente
    if (!open_stream(instream, false))
      return 0;
    
    cout<<endl<<"inserisci la stringa da cercare:"<<endl;
    cin.getline(str, MAX_LINE);
    
    if (!grep(instream, str))
      cout<<endl<<"la stringa: "<<str<< " è   assente"<<endl;
    else cout<<endl;
    // Si chiude lo stream
    instream.close();    
    
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
  
  /* Mostra a terminale il contenuto dello stream di input  
   */
  
  bool grep(fstream &in, const char str[])
  {
    char line[MAX_LINE];
    int i;
    bool found;
    
    found = false;    
    i=1; 
    while (in) {
      in.getline(line, MAX_LINE);
      if (strstr(line, str)) {
	cout<<i<<": "<<line;
        found = true;
      }
      ++i;    
    }
    
    
    
    return found;  
  }
  