    
    #include <iostream>  
    
    // Assegnazione di tipo
    typedef int TipoValue;   
    
    // inclusione del file, DOPO typedef
    #include "stack.h"
    
    using namespace std;
    
    int main(){
      
        Stack s;
        TipoValue tmp;
	int num, i;
        
        s.init(MAX_ELEMENTS);
        
        cout<<endl<<"Quanti elementi vuoi inserire (push) nella pila : ";
        cin>>num;
        
        for(i=0; i < num; ++i) {
           cout<<endl<<"inserisci elemento "<<i<<"-esimo: ";
           cin>>tmp;
           s.push(tmp);
        }
        
        cout<<endl<<"inseriti "<<i<<" elementi"<<endl;
        
         
    }
