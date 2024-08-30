/**
 * @file
 * @brief Funciones que permiten comparar metodos
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/
#include <iostream>
#include <string>
#include <vector>

#include "encontrar.h"


using std::cout;
using std::endl;
using std::string;
using std::vector;



void comparar_newton_raphson(string f_str, string df_str, string  df2_str,vector<double> valores_iniciales, double tol, int n){
    cout<<"Comparacion entre Newton Raphson"<<
    " y Newton Raphson Generalizado"<<endl;


    for (auto & p0: valores_iniciales){
        cout<<"Caso con Newton Raphson"<<endl;
        encontrar_newton_raphson(f_str, df_str ,p0, tol, n);

        cout<<"Caso con Newton Raphson Generalizado"<<endl;
        encontrar_newton_raphson_g(f_str, df_str, df2_str ,p0, tol, n);

        cout<<"Fin del Caso========================="<<endl;

    }


}