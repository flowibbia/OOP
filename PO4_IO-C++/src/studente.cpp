  
  #include "studente.h"
  
  void studente::output(ostream &out)
  { 
    out<<endl;
    out<<nome<<",";
    out<<cognome<<",";
    out<<matr;

    return;

  }
  
  
  
  bool studente::input(ifstream &in)
  { 
    char str[max_string];
  
    if (in.getline(str, max_string, ','))
      strcpy(nome, str);
    else return false;

    if (in.getline(str, max_string, ','))
      strcpy(cognome, str);
    else return false;

    if (in.getline(str, max_string))
      matr = atoi(str);
    else return false;

    return true;
}
   
