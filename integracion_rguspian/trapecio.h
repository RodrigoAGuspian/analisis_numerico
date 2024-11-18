
/**
 * @file
 * @brief Integracion con el método del trapecio
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */


#ifndef TRAPECIO_H
#define TRAPECIO_H

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
    class trapecio{
        public:
            /**
             * @brief Crea una nueva instancia del metodo
             * @param f_str Texto de la funcion a integrar
             * @param a Limite inferioir del intervalo
             * @param b Limite superior del intervalo
             * @param n Cantidad de segmentos
             */

            trapecio(string f_str, double a, double b, int n){
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
             * @brief Crea una neuva instancia del metodo trepecio
             */
            trapecio(vector<double> x, vector<double> y):x(x), y(y){
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
                // Para el metodo del trapecio se requieren al menos dos valaores de x
                if (x.size() < 2)
                    return NAN;

                int n = (int) x.size() - 1;
                double sum_int = 0.0f;
                
                for (size_t i = 1; i<n ; i++){
                    cout<<"sumando "<< x[i] << endl;
                    sum_int += y[i];
                }

                double b = x[n];
                double a = x[0];
                double fn = y[n];
                double f0 = y[0];
                double an = a;
                return (b-a) * ((f0 + (2 *sum_int) + fn)/ (2 * n) );
            }

            double calccular_ajustada(string d2f){
                return calcular() + error(d2f);
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

            /**
             * @brief Calcular el error de integracion en el intervalo dado
             * @param d2f_str segunda derivada de la función
             * @return Retorna el error de integración con el signo incluido
             */

            double error(string d2f_str){
                double f2e = calcular_f2e(d2f_str);

                int n = (int) x.size() -1;
                double b = x[n];
                double a = x[0];
                double h = (b-a) / (double) n;
                double et = -(pow(h,3)/12.0f)*f2e;

                return et;
            }
        private:
            vector<double> x;
            vector<double> y;

            /**
             * @brief Encuentra el valor máximo en el valor absoluto de d2f en el intervalo 
             * @param d2f_str segunda derivada de la función
             * @return calcula el valor maximo "sin valor absoluto" de la derivada dada
            */
            double calcular_f2e(string d2f_str){
                if (x.size() < 2)
                    return NAN;

                expression d2f(d2f_str);

                // Asumir que d2f(x0) es el maximo
                size_t pos_maximo = 0;
                double maximo = fabs(d2f(x[0]));

                for (size_t i = 1; i<x.size(); i++){
                    double valor = fabs(d2f(x[i]));
                    if (valor > maximo) {
                        maximo = valor;
                        pos_maximo = i;
                    }
                    
                }

                return d2f(x[pos_maximo]);
            }
    };
};

#endif