
/**
 * @file
 * @brief Integracion con el método de simpson 1/3
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */


#ifndef SIMPSON13_H
#define SIMPSON13_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "expression.h"


using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::setw;
using std::vector;


namespace integracion{
    class simpson13{
        public:
            /**
             * @brief Crea una nueva instancia del metodo
             * @param f_str Texto de la funcion a integrar
             * @param a Limite inferioir del intervalo
             * @param b Limite superior del intervalo
             * @param n Cantidad de segmentos
             */

            simpson13(string f_str, double a, double b, int n){
                
                // Recuerde que para el metodo de simpson 1/3 n tiene que ser par
                if (n% 2 != 0){
                    return;
                }
                int i = 0;

                // 0. Crea el evaludor de expresiones
                expression f(f_str);

                // 1. Calcula el paso h
                double h = (b-a) / (double) n;

                for (double xi = a; i<= n; i++, xi+=h){
                    x.push_back(xi);
                    y.push_back(f(xi));
                }
            }

            /**
             * @brief Crea una nueva instancia del metodo de simpson 1/3
             */
            simpson13(vector<double> x, vector<double> y){
                // Simpson 1/3

                // Si la cantidad de segmentos es par, la cantidad de datos en x e y es impar.
                if (x.size() % 2 == 0)
                    return;

                // Los valores x e y tienen que tener la misma cantidad de datos
                if (x.size() != y.size())
                    return;

                this->x = x;
                this->y = y;
            }

            /**
             * @brief Calcaula el valor de la integral en el intervalo dado
             */

            double calcular(){
                // Para el metodo del sipson13 se requieren que sea par
                if (x.size() < 2 || x.size() % 2 == 0)
                    return NAN;

                
                int n = (int) x.size() - 1;
                double sum_par = 0.0f;
                double sum_impar = 0.0f;
                
                double b = x[n];
                double a = x[0];

                double h = (b-a) / (double) n;
                
                for (size_t i = 1; i<n ; i++){
                    
                    if (i % 2 == 0){
                        sum_par += y[i];
                    } else{
                        sum_impar += y[i];
                    }
                }

                return (h/(double)3.0f) * (y[0] + 4.0f* sum_impar + 2.0f* sum_par + y[n]);
            }

            /**
             * @brief Envia la tabla de datos a un flujo de salida
             */

            void imprimir_tabla(ostream & os){
                os << setw(15) << "x"
                << setw(15) << "y" << endl;
                for(size_t i = 0; i<x.size(); i++){
                    os << setw(15) << x[i]
                        << setw(15) << y[i]<< endl;
                }
            }

        private:
            vector<double> x /*!Valores de la variable independiente */;
            vector<double> y /*!Valores de la variable dependiente */;
    };
};

#endif