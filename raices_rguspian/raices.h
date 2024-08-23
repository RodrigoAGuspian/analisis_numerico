/**
 * @file
 * @brief Raices
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/


#ifndef RAICES_H
#define RAICES_H

#include <vector>
#include <iostream>
#include <cfloat>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::setw;

namespace raices{


/**
     * @brief Verifica si el valor de x está por debajo del límite de underflow
     * @param x Valor a Verificar
     * @return true si el valor está por debajo del underflow
     */

    bool es_cero(double x){
        return (fabs(x) <= DBL_EPSILON);
    }

    /**
     * @brief Calcula el error relativo entree dos valores
     * @param nuevo Valor nuevo
     * @param ant Valor anterior
     * @return error relativo entre nuevo y anterior (valor absoluto)
     */

    double error_relativo(double nuevo, double ant){
        return fabs((nuevo - ant) / nuevo);
    }

    struct solucion{
        string f_str;
        vector<double> valores_iniciales;

        /**
         * @brief Constructor de clase solucion
         * @param f_str función como cadena de caracteres
         * @param a Límite inferior de la función
         * @param b Límite superior de la función
         * 
        */
        solucion(string f_str, vector<double> valores_iniciales ):f_str(f_str),valores_iniciales(valores_iniciales){
        }


        double raiz = NAN;
        vector<double> aproximaciones;

        /**
         * @brief función para agregar la aproximación
         * @param x valor aproximado de la raiz a buscar.
        */
        void agregar(double x){
            aproximaciones.push_back(x);
        }

        /**
         * @brief funcinón para imprimr las aproximaciones y la solución raiz de la función
        */

        void imprimir(int precision = 7){
            if (aproximaciones.size() > 0){
                cout<<"Aproximaciones: "<<endl;
                cout<<"Aproximación inicial: "
                    <<setprecision(precision)<< aproximaciones[0]<<
                endl;


                if (aproximaciones.size() >1 ){
                    cout<<setw(15) <<"Nuevo"
                    <<setw(15)<<"Anterior"
                    <<setw(15)<<"Error Relativo porcentual"<< endl; 
                }
                for (size_t i = 1; i<aproximaciones.size();  i ++){
                    cout<<setw(15) << setprecision(precision) << aproximaciones[i]
                    <<setw(15) << setprecision(precision) << aproximaciones[i-1]
                    <<setw(15) << setprecision(precision) << error_relativo(aproximaciones[i], aproximaciones[i-1])<< endl; 
                }
            }

            cout <<"La solución de " <<f_str
                << " con valores iniciales";
            for (auto & x: valores_iniciales){
                cout <<" "<< x;
            }
            cout <<" es: "<<raiz<<endl;
            
        }
    };

    
}


#endif