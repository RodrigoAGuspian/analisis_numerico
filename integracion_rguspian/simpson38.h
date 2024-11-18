
/**
 * @file
 * @brief Integracion con el método de simpson 3/8
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */


#ifndef SIMPSON38_H
#define SIMPSON38_H

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
    class simpson38{
        public:
            /**
             * @brief Crea una nueva instancia del metodo
             * @param f_str Texto de la funcion a integrar
             * @param a Limite inferioir del intervalo
             * @param b Limite superior del intervalo
             * @param n Cantidad de segmentos
             */

            simpson38(string f_str, double a, double b, int n){
                
                // Recuerde que para el metodo de simpson 3/8 n tiene que ser par
                if (!(n% 2 != 0 && n% 3 == 0)){
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
            simpson38(vector<double> x, vector<double> y){
                // Calcular n: cantidad de segmentos
                int n = (int) x.size() -1;
                // Si la cantidad de segmentos es impar, la cantidad de datos en x e y es impar.
                if (!(n% 2 != 0 && n% 3 == 0))
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
                int n = (int) x.size() - 1;

                // Para el metodo de simpson 3/8 se requieren al menos 4 valaores de x
                if (n < 3)
                    return NAN;

                // Obtener los valores inferior y superior                
                double b = x[n];
                double a = x[0];

                double h = (b-a) / (double) n;

                
                double sum_1 = 0.0f;
                double sum_2 = 0.0f;
                double sum_3 = 0.0f;
                
                // 1,4,7,...n-2
                for (size_t i = 1; i < n - 1 ; i+=3){
                    sum_1+=y[i];
                }

                // 2,5,8,...n-1
                for (size_t j = 2; j < n ; j+=3){
                    sum_2+=y[j];
                }

                for (size_t k = 3; k < n - 2 ; k+=3){
                    sum_3+=y[k];
                }

                return ((3.0f*h)/(double)8.0f) * (y[0] + 3.0f* (sum_1 + sum_2) + 2.0f* sum_3 + y[n]);
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
            vector<double> x /*<!Valores de la variable independiente */;
            vector<double> y /*<! Valores de la variable dependiente */;
    };
};

#endif