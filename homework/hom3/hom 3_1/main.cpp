//Esercizio 1
#include <iostream>
using namespace std;

class Myclass{
    int i;
public:
    Myclass() {i=0;   }
    void show(){cout<<endl<<i;};
};



int main(){
    Myclass m;
    m.show();
    return 0;
}