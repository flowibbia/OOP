    
    #include <iostream>  
    
    // Assegnazione di tipo
    typedef int TipoValue;   
    
    // inclusione del file, DOPO typedef
    #include "list.h"
    
    using namespace std;
    
    int main(){
      
        List l;
        TipoValue tmp;
	int num, i;
        
        l.init();
        
        cout<<endl<<"Quanti elementi vuoi inserire (push) nella pila : ";
        cin>>num;
        
        for(i=0; i < num; ++i) {
           cout<<endl<<"inserisci elemento "<<i<<"-esimo: ";
           cin>>tmp;
           l.insert(i, tmp);
        }
        
        cout<<endl<<"inseriti "<<i<<" elementi"<<endl;
        
         
    }
