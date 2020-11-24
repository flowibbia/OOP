//
// Created by nico on 11/11/20.
//
#pragma once
#include <fstream>
using namespace std;
float** alloc_mat(int rows,int cols){
    float **tmp;

    //allocazione dinamica della matrice
    tmp = new float*[rows];

    for(int i=0;i<rows;i++)
        tmp[i] = new float[cols];

    return tmp;
}


class Matrice
{
    int rows,cols;                          //numero di riche e colonne
    float **m;                              //puntatore alla matrice allocata dinamicamente
public:
    Matrice(int _rows=0,int _cols=0);             //costruttore
    Matrice (const Matrice &src);
    ~Matrice();                             //distruttore
    Matrice copia(const Matrice &src);
    float get(int i,int j) const{return m[i][j];}                 //Restituisce il valore m[i,j]
    int getRows() const{return rows;}                          //Restituisce il numero di righe
    int getCols() const{return cols;}                          //Restituisce il numero di colonne

    void set(float val,int i,int j);       //Assegna il valore val all'elemento M[i,j]

    //OPERATORI
    Matrice operator+(const Matrice &mat);
    Matrice operator*(const Matrice &mat);
    Matrice operator=(const Matrice &mat);
    bool operator==(const Matrice &mat) const;
    Matrice operator+=(const Matrice &mat);
    Matrice operator*=(const Matrice &mat);

    //OPERATORI DI I/O
    friend ostream& operator<<(ostream &os,Matrice mat);
    friend istream& operator>>(istream &in,Matrice mat);

};
