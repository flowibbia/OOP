    
    #include <iostream>  

    
    // Assegnazione di tipo
    typedef int TipoValue;   
    
    // inclusione del file
    #include "set.h"
    
    using namespace std;
    
    int main(){  
        
        Set s;
        TipoValue tmp;
	int num, i;
        
        s.init(MAX_ELEMENTS);
        
        cout<<endl<<"Quanti elementi vuoi inserire nell'insieme: ";
        cin>>num;
        
        for(i=0; i < num; ++i) {
           cout<<endl<<"inserisci elemento "<<i<<"-esimo: ";
           cin>>tmp;
           s.add(tmp);
        }

       s.show();
  
       cout<<endl<<"inseriti "<<s.size()<<" elementi"<<endl;

         
    }
