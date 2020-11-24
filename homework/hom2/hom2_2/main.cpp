#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

const int max_line= 1000;
bool comp_dim(std::ifstream &in, int &rows, int &cols);
int comp_cols(std::ifstream &in);
float **alloc_mat(int rows,int cols);
const char delim[]= " \t,;";

int main() {
    int rows,cols;
    float **mat;
    std::ifstream in;
    std::string file;

    //mat=alloc_mat(mat,);
    std::cout<<"inserire nome file: ";
    std::cin>>file;

    in.open(file, std::ios::in);

    if(!in)
        std::cerr<<"\nerrore apertura file";

    if(!comp_dim(in,rows,cols)){
        std::cout<<"errore di formato del file\n";
        return -1;
    }

    std::cout<<"il numero delle righe e delle colonne è: "<<rows<<" "<<cols<<"\n";

    in.close();
    in.open("/home/nico/CLionProjects/hom2_2/input.txt", std::ios::in);
    mat=alloc_mat(rows,cols);

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            in>>mat[i][j];

    //show matrix in terminal
    for(int i=0; i<rows;i++){
        for (int j=0;j<cols;j++){
           std::cout<<mat[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}


bool comp_dim(std::ifstream &in, int &rows,int &cols){

    int appo;
    cols=comp_cols(in);

    if(cols==0){
        rows=0;
        return true;
    }
    else rows=1;

   while(in) {
       appo = comp_cols(in);

       if (appo == cols)
           rows++;
       else if(appo>0)
           return false;
   }

   return true;
}

int comp_cols(std::ifstream &in){
    char str[max_line];
    char *tok;
    int n=0;

    //extract line from the stream
    in.getline(str,max_line);

    if(strlen(str)==0){
        return 0;
    }


    //parse the line and divide in token
    tok=strtok(str," " );
    if(tok)
        n=1;
    else return 0;

    while (tok=strtok(0," "))
        n++;

    return n;
}

float **alloc_mat(int rows,int cols){
   float **mat;

   //allocation of a vector for any cols
   mat = new float*[rows];

   //allocation of a vector of cols lenght for any rows
    for (int i=0;i<rows;i++)
       mat[i]= new float[cols];

    return mat;
}