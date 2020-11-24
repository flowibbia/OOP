//Scrivere un programma che carica da file una matrice di reali. Il nome del file, il numero di righe e di colonne
//devono essere richiesti all'utente in maniera interattiva. Un volta acquisita, la matrice sarà stampata a video.
//La memoria per la memorizzazione deve essere allocata dinamicamente, in base alle specifiche fornite
//dall'utente. Nel caso in cui non sia possibile aprire il file, il programma stamperà un opportuno messaggio. Il
//programma dovrà inoltre verificare l'effettiva lettura del numero di elementi specificato dall'utente.
//Il programma dovrà inoltre essere in grado di salvare la matrice su di un file il cui nome è specificato dall'utente.
#include <iostream>
#include <fstream>
#include <string>
//#include <stdlib.h>

float** alloc_mat(int row, int col);
void show_mat(std::ostream *out,float **mat, int rows, int cols);

int main() {

    int row, col;
    float **mat;


    std::string file;
    char a[40];
    std::ifstream in;
    std::ofstream out;

    std::cout << "inserire file da leggere";
    std::cin >> file;

    std::cout << "\ninserire numero di righe della matrice: ";
    std::cin >> row;

    std::cout << "\ninserire numero di colonne della matrice: ";
    std::cin >> col;

    //dynamic allocation for the matrix with a function
    mat = alloc_mat(row, col);

    in.open("/home/nico/CLionProjects/untitled/input.txt", std::ios::in);

    if (!in)
        std::cerr << "errore apertura del file in lettura\n";

    for (int i = 0; i < row; i++){
        char str[6];

        for(int j=0;j<col;j++)
            in>>mat[i][j];

    }

    in.close();
    out.open("/home/nico/CLionProjects/untitled/output.txt",std::ios::out);

    show_mat(&out,mat,row,col);

    out.close();

    return 0;


}

float** alloc_mat(int row, int col){

    float **mat;
    mat= new float*[row];

    //allocation of a vector of col length for any rows
    for(int i=0;i<row;i++)
        mat[i] = new float[col];
    return mat;
}

void show_mat(std::ostream *out,float **mat, int rows, int cols){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           *out<<mat[i][j]<<" ";
           std::cout<<mat[i][j]<<" ";
        }
        *out<<"\n";
        std::cout<<"\n";
    }
}