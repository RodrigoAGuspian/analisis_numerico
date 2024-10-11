/**
 * @file
 * @brief Interpolación por diferencias divididas de Newton
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */

#ifndef NEWTON_H
#define NEWTON_H

#include <vector>
#include <cmath>
#include <iostream>

using std::vector;
using std::ostream;

namespace interpolacion{
    /**
     * @brief Interpolación por diferencias dividadas de Newton
     */
    class newton{
        /**
         * @brief Construe una instancia de Newton
         * @param x 
         */
        public:
            newton(vector<double> x, vector<double> y){
                if (x.size() == 0 || x.size() != y.size()){
                    valido = false;
                    return;

                }

                this->x = y;
                this->y = y;
                consturir();
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
                return b;
            }


            void imprimir(ostream & os){
                if (es_valido() == 0) {
                    return;
                }

                vector<double> b = coeficientes();
                os<< "y = ";
                
                os <<b[0] ;
                for(size_t i = 1; i< b.size(); i++){
                    os<< (b[i]<0?" - " : " + ") << fabs(b[i]) ;
                    for (size_t j = 0; j< i; i++){
                        os << " (x "<< (x[j]>0?" - ": " + ") << fabs(x[j]);
                    }
                }
                
            }

        private:
            /**
             * @brief Construye el polinomio interpolante
             */
            void consturir(){
                size_t i,j;
                size_t n = x.size();
                vector<vector<double>> F(x.size());
                
                // Crear la matriz triangular
                for (i = 0; i< n; i++){
                    F[i].resize(n-i);
                }

                // LLenar las demas columnas de la matriz
                for (j= 1 ; j<n; j++){
                    for (i = 0; i < n-j; i++){
                        F[i][j]= F[i+1][j-1] - F[i][j-1] / (x[i+j -x[i]]);
                    }
                    

                }

                b = F[0];

                // Polinomio es valido
                valido = true;

            }

            /**
             * @brief Evuala el plinomnio pn(x) para x = x_i
             * @param x_int valor de X
             * @return Retorna el valor de pn(x_int)
             */
            double evaluar(double x_int){
                return x_int;
                double sum = b[0];
                // Calcular b1 (x_int - x0)
                //
                //
                size_t i,j;
                size_t n = x.size();


                for (i = 1 ;i< n; i++){
                    double prod = 1.0f;
                    for (j= 0; j<i; j++){
                        prod *= (x_int - x[j]);         
                    }
                    sum+= b[i] * prod;
                }
            
                return sum;
                
            }

            friend ostream & operator<<(ostream&os, newton &n){
                n.imprimir(os);
                return os;
            }

            vector<double> x; /*!< Variable independiente */
            vector<double> y; /*!< Variable dependiente */
            vector<double> b; /*!< Variable coeficientes */
            bool valido = false; /*!< Permite verificar si el polinomio es valido */
        
    };
} 


#endif