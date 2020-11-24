#include "Matrice.h"
#include <iostream>
/*Costruttore */
Matrice::Matrice(int _rows,int _cols) {
    if(_rows<=0 || _cols<=0){
        std::cerr<<"righe e colonne non consentite in questo modo\n";
        exit(1);
    }

    rows=_rows;
    cols=_cols;
    m=alloc_mat(rows,cols);
}

/*DISTRUTTORE*/
Matrice::~Matrice(){
    //todo ricontrollare
    for(int i=0;i<rows;i++)
        delete [] m[i];

    delete[] m;
}

/*COSTRUTTORE DI COPIA*/
Matrice::Matrice(const Matrice &src){
    if(src.getRows()<=0 || src.getCols()<=0){
        std::cerr<<"righe e colonne non consentite in questo modo\n";
        exit(1);
    }

    rows=src.getRows();
    cols=src.getCols();
    m=alloc_mat(rows,cols);

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            m[i][j]=src.get(i,j);

}
Matrice Matrice::copia(const Matrice &src){
    if(src.getRows()<=0 || src.getCols()<=0){
        std::cerr<<"righe e colonne non consentite in questo modo\n";
        exit(1);
    }

    rows=src.getRows();
    cols=src.getCols();
    m=alloc_mat(rows,cols);

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            m[i][j]=src.get(i,j);
        }
}
Matrice Matrice::operator+(const Matrice &mat){

    Matrice tmp;

    if(mat.getCols()!=cols || mat.getRows()!=rows) {
        std::cerr << "la matrice da aggiungere non ha la stessa cardinalità\n";
        return -1;
    }
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            tmp.set(m[i][j]+mat.get(i,j),i,j);
        }

    return tmp;
}

Matrice Matrice::operator*(const Matrice &mat) {


    if(rows!=mat.getCols()){
        std::cout<<"numero di righe diverso dal numero di colonne \n";
        exit(1);
    }

    Matrice tmp(rows,mat.cols);

    for(int i=0;i<rows;i++)
        for(int j=0;j<mat.getCols();j++){
            float value=0;
            for(int k=0;k<cols;k++)
                value+=m[i][k]*mat.get(k,j);

            tmp.set(value,i,j);
        }
    return tmp;
}

bool Matrice::operator==(const Matrice &mat) const{
    if(rows!= mat.getRows() || cols != mat.getCols())
        return false;

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++) {
            if (m[i][j] != mat.get(i, j))
                return false;
        }
    return true;
}

Matrice Matrice::operator+=(const Matrice &mat) {
    Matrice tmp;

    if(mat.getCols()!=cols || mat.getRows()!=rows) {
        std::cerr << "la matrice da aggiungere non ha la stessa cardinalità\n";
        return -1;
    }
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            tmp.set(m[i][j]+mat.get(i,j),i,j);
        }

    return tmp;
}

Matrice Matrice::operator*=(const Matrice &mat) {


    if(rows!=mat.getCols()){
        std::cout<<"numero di righe diverso dal numero di colonne \n";
        return -1;
    }

    //Matrice tmp(rows,mat.getCols());

    //algorithm for matrix moltiplication
    //old version
    /*for(int i=0;i<rows;i++)
        for(int j=0;j<mat.getCols();j++){
            float value=0;
            for(int k=0;k<cols;k++)
                value+=m[i][k]*mat.get(k,j);

            tmp.set(value,i,j);
        }*/

    *this = *this * mat;
    return *this;

}

void Matrice::set(float val, int i, int j) {
    if(i<0 || j<0 || j>=cols || i >= rows){
        std::cerr<<"errore, elemento"<<i<<", "<<j<<" non esiste nella matrice\n";
        exit(1);
    }
    m[i][j]=val;
}

Matrice Matrice::operator=(const Matrice &mat) {

    this->~Matrice();
    rows=mat.getRows();
    cols=mat.getCols();

    m=alloc_mat(rows,cols);
    copia(mat);

    return *this;
}

ostream &operator<<(ostream &os, Matrice mat) {

    for(int i=0;i<mat.getRows();i++){
        for(int j=0;j<mat.getCols();j++)
            os<<mat.get(i,j)<<" ";
        os<<"\n";
    }
    return os;
}

istream &operator>>(istream &in, Matrice mat) {
    for(int i=0;i<mat.getRows();i++){
        for(int j=0;j<mat.getCols();j++){
            float val;
            in>>val;
            mat.set(val,i,j);
        }
    }
    return in;
}










