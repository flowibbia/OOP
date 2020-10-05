    
    #include <iostream>  

    
    // Assegnazione di tipo
    typedef int TipoValue;   
    
    // inclusione del file
    #include "queue.h"
    
    using namespace std;
    
    int main()
    {  
        
        Queue q;
        TipoValue tmp;
	int num, i;
        
        q.init(MAX_ELEMENTS);
        
        cout<<endl<<"Quanti elementi vuoi inserire nella coda?: ";
        cin>>num;
        
        for(i=0; i < num; ++i) {
           cout<<endl<<"inserisci elemento "<<i<<"-esimo: ";
           cin>>tmp;
           q.add(tmp);
        }
        
        cout<<endl<<"inseriti "<<q.size()<<" elementi"<<endl;
        
        return 0;     
    }
