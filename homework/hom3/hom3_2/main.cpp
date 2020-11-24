#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class Complex
{
    float re;
    float im;
public:
    Complex(float re=0.0,float im=0.0);
    float getRe() const{return re;}               // restituisce la parte intera
    float getIm() const {return im;}               // restituisce la parte immaginaria
    void setReale(float r) {re = r;}        // assegna valore alla parte reale
    void setIm(float i){im = i;}            // assegna valore alla parte immaginaria
    float getModulo() ;                     // restituisce il modulo

    float getFase() ;                       // restituisce la fase
    void show() ;                           // stampa a video del numero
    Complex operator+(const Complex& c);    // operatore somma
    Complex operator*(const Complex& c);    // operatore prodotto

// Funzioni FRIEND
// Inseritore della classe
    friend ostream& operator<<(ostream &os, Complex C);
// Estrattore della classe
    friend istream& operator>>(istream &in, Complex &C);
};

Complex::Complex(float _re, float _im) {
   re = _re;
   im = _im;
}

float Complex::getModulo() {
    return sqrt(pow(re,2)+pow(im,2) );
}

float Complex::getFase() {
    //todo varie if per prendere tutti e 4 i quadranti del numero complesso
    if(re>0)
        return atan(im/re);
    else if (re<0 && im >= 0)
        return atan(im/re)+ 3.14;
    else if (re<0 &&  im<0)
        return atan(im/re)-3.14;
    else if (re==0 && im>0)
        return 3.14/2;
    else if (re==0 && im<0)
        return -3.14/2;
    else
        return 0;

}

void Complex::show(){
    std::cout<<"re: "<<re<<"\n";
    std::cout<<"im: "<<im<<"\n";
}

Complex Complex::operator+(const Complex &c) {
    Complex tmp;
    tmp.setReale(this->re+c.getRe());
    tmp.setIm(this->im+c.getIm());
    return tmp;
}
Complex Complex::operator*(const Complex &c) {
    Complex tmp;
    tmp.setReale((this->re*c.getRe())-(this->im*c.getIm()));
    tmp.setIm((2*this->re*c.getIm())+(2*c.getRe()*this->im));
    return tmp;
}

ostream& operator<<(ostream &os, Complex C) {
    os<<C.getRe()<<" "<<C.getIm()<<"j"<<"\n";
    return os;
}

istream& operator>>(istream &in, Complex &C) {

    float _re,_im;
    in>>_re;
    in>>_im;

    C.setReale(_re);
    C.setIm(_im);

    return in;
}

int main(){
    Complex c1, c2, cs, cp;

    /** INPUT **/
    cout<<endl<<"inserire due numeri complessi:"<<endl;
    cout<<"Complesso #1:";
    cin>>c1;
    cout<<"Complesso #2:";
    cin>>c2;

    cout<<"Sono stati inseriti i seguenti numeri complessi:"<<endl;
    cout<<"complesso #1:"<<c1<<endl<<"complesso #2:"<<c2;

    /* FASE E MODULO */
    // #1
    cout<<endl<<"La fase del complesso #1 è:"<<c1.getFase();
    cout<<endl<<"Il modulo del complesso #1 è:"<<c1.getModulo();
    // #2
    cout<<endl<<"La fase del complesso #2 è:"<<c1.getFase();
    cout<<endl<<"Il modulo del complesso #2 è:"<<c1.getModulo();


    /** ELABORAZIONE **/
    cs = c1 + c2;
    cp = c1 * c2;

    /** OUTPUT **/
    cout<<endl<<"la somma dei due numeri è:"<<cs;
    cout<<endl<<"il prodotto dei due numeri è:"<<cp<<endl;

    return 0;
}

