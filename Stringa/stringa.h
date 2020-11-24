#ifndef STRINGA_H
#define	STRINGA_H

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class Stringa
  {
      
    private:
	    char* str;
	    unsigned int num;
    public:
      Stringa(unsigned int l=0);          
      /* COSTRUTTORE: 
       * Alloca un array di l elementi.
       */
      Stringa( char* s);                  
      /* COSTRUTTORE:
       * inizializza l'oggetto con la c-string passata come parametro, dopo aver allocato la
       * memoria necessaria.
       */ 
      Stringa( Stringa &s);                 
      /* COSTRUTTORE DI COPIA:
       * alloca la memoria e  inizializza l'ggetto a quello passato come parametro.
       */ 
      ~Stringa();                         
      /* DISTRUTTORE:
       * dealloca la memoria dinamica puntata da str.
       */ 
      
      
      char get(unsigned int i) { return str[i-1]; };
      void set(char c, unsigned int i) { str[i-1]=c; };
      unsigned int size() { return num; };                
      void clear();
      bool empty(){ return (num==0 ? true : false); };             
      
      char first(){ return get(1); };                    
      char last(){ return  get(num); };                     
      /* Restituisce l'ultimo carattere della stringa str[num-1].
       */       
//      Stringa& insert(unsigned int pos,  Stringa& s); 
//      /*  INSERISCE la string str a partire  da pos. Effettua il ridimensionamento dell'array.
//       */ 
//      Stringa& insert(unsigned int pos,  char *str); 
//      /* INSERISCE la c-string str a partire  da pos. Effettua il ridimensionamento dell'array.
//       */      
//      Stringa substr(unsigned int pos, unsigned int len); 
      /* Restituisce un NUOVO oggetto Stringa  contenente la sottotringa che inizia  alla
       * posizione pos ed è lunga len caratteri. 
       *  NOTE
	    * Se pos > len la chiamata genera un errore e termina il programma. 
	    * Se pos+len > num nel nuovo oggetto vengono copiati solo i caratteri str[pos] ...  
	      str[num]
       */ 
//      unsigned int find(unsigned int pos, Stringa s);   
//      /* Cerca nella stringa la sottotringa s  a partire dalla posizione pos e ne  restituisce la
//       * posizione, -1 altrimenti
//       */ 
//      unsigned int find(unsigned int pos, char  *str);   
//      /* Cerca nella stringa la sottotringa  str (c-string) a partire dalla posizione pos e ne  restituisce la posizione, -1 altrimenti
//       */
//      unsigned int find_first(char c);   
//      /* Cerca nella stringa la prima occorrenza del carattere c e ne  restituisce la posizione, -1 altrimenti
//       */ 
//      unsigned int find_last(char c);   
//      /* Cerca nella stringa l'ultima occorrenza del carattere c e ne  restituisce la posizione, -1 altrimenti
//       */ 
      
      void show(){ cout << "'" << str << "'"; };
                 
      /** OPERATORI DI CONFRONTO */
//      bool operator==( Stringa& s);
//      bool operator<=( Stringa& s) ;
//      bool operator<( Stringa& s) ;
//      bool operator>=( Stringa& s) ;
//      bool operator>( Stringa& s);
      
      /** OPERATORI di I/O */
//      friend ostream& operator<<(ostream& os,  Stringa& s);
      /* INSERITORE della classe.
       */ 
      /** ALTRI OPERATORI */
//      Stringa& operator=( Stringa& s);    // Operatore di assegnazione
//      Stringa& operator=( Stringa& s);    // Operatore di assegnazione con C-string
//      char& operator[](unsigned int i); // operatore []
//      Stringa operator+(Stringa& op); // concatenazione
//      Stringa& operator+=( Stringa& op); // // concatenazione abbreiviato
//      
//            
//      friend istream& operator>>(istream& i, Stringa& s);
      /* ESTRATTORE della classe.
       * NOTE:
       * Legge dallo stream esattamnte len caratteri
       */      
      void leggi(char *s);
  };


#endif	/* STRINGA_H */

