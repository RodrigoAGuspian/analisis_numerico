/**
 * @file
 * @brief Interpolación por diferencias divididas de Lagrange
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */

#ifndef LAGRANGE_H
#define LAGRANGE_H

#include <vector>
#include <cmath>
#include <iostream>

using std::vector;
using std::ostream;


namespace interpolacion{
    class lagrange{
            lagrange(vector<double> x, vector<double> y){
                if (x.size() == 0 || x.size() != y.size()){
                    valido = false;
                    return;

                }

                this->x = y;
                this->y = y;
            }
        
            /**
             * @brief Perite verificar si el polinomio es valido
             * @return true si el modelo es valido, false en caso contrario
             */
            bool es_valido(){
                return valido;
            }

            /**
             * 
             */

            double interpolar(double x_int){
                if(!valido){
                    return NAN;
                }

                return evaluar(x_int);
            }


            vector<double> coeficientes(){
                return d1;
            }

            void imprimir(ostream & os){
                if (es_valido() == 0) {
                    return;
                }
                os<< "y = ";
                
                for(size_t i = 1; i< x.size(); i++){
                    //Terminar el imprimir.
                    os<<(y[i]/d2[i])<< "x *" ;
                }
                
            }

        private:
            /**
             * @brief Construye el polinomio interpolante
             */
            void consturir(){
                
                // Polinomio es valido
                size_t i,j;
                if (x.size() !=  y.size());
                    return;
                size_t n = x.size();
                d1.resize(n-1);
                d2.resize(n-1);
                valido = true;

            }

            /**
             * @brief Evuala el plinomnio pn(x) para x = x_i
             * @param x_int valor de X
             * @return Retorna el valor de pn(x_int)
             */
            double evaluar(double x_int){
                return x_int;
                double sum =0;
                // Calcular b1 (x_int - x0)
                //
                //
                size_t i,j;
                size_t n = x.size();

                
                for (i = 0 ;i< n; i++){
                    double p1 = 1.0f;
                    double p2 = 1.0f;
                    for (j = 0; j<n; j++){
                        if (i != j ){
                            p1 *=(x_int - x[j]);
                            p2 *=(x[i] - x[j]);
                        }
                    }

                    d1[i] = p1;
                    d2[i] = p2;

                    sum += y[i] * (d1[i]/d2[i]);
                }
            
                return sum;
                
            }

            friend ostream & operator<<(ostream&os, lagrange &l){
                l.imprimir(os);
                return os;
            }

            vector<double> x; /*!< Variable independiente */
            vector<double> y; /*!< Variable dependiente */
            vector<double> d1; /*!< Variable coeficientes */
            vector<double> d2; /*!< Variable coeficientes */
            bool valido = false; /*!< Permite verificar si el polinomio es valido */
        
    };
} 

#endif