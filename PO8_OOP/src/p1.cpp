  #include <iostream>

  
  using namespace std;

	class Myclass{      
  	int i;
    public: 
      Myclass operator=(const Myclass &m){cout<<endl<<"ASSEGNAZIONE:"<<this; return *this;}
      Myclass(){cout<<endl<<"COSTRUTTORE:"<<this;}
      Myclass(const Myclass& o){cout<<endl<<"COPIA:"<<this;}
  };
  
	int main() {
    

   Myclass m1, m2, m3;
   
   
   m1 = m2 = m3;
  
   return 0;
 }
