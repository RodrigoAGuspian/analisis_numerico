/**
 * @file
 * @brief Integración de Simpson
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */

#ifndef SIMPSON_H
#define SIMPSON_H

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "expression.h"
#include "simpson13.h"
#include "simpson38.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using integracion::simpson13;
using integracion::simpson38;


namespace integracion{
    /**
     * @brief Metodo Generalizado de Simpson
     */
    class simpson
    {
        public:
            simpson(string f_str, double a, double b, int n){
                this->n = 0;
                if (n<3){
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
                this->n=n;
            }

            /**
             * @brief Crea una nueva instancia del metodo de simpson 
             */
            simpson(vector<double> x, vector<double> y){
                int n = (int) x.size() -1;

                // Si la cantidad de segmentos es par, la cantidad de datos en x e y es impar.
                if (n < 2)
                    return;

                // Los valores x e y tienen que tener la misma cantidad de datos
                if (x.size() != y.size())
                    return;

                this->x = x;
                this->y = y;
                this->n = n;
            }

            
            /**
             * @brief Calcaula el valor de la integral en el intervalo dado
             */

            double calcular(){

                // 1. Si la cantidad de segmentos es par, aplicar Simpson 1/3 y retornar el valor calculado.
                if (n % 2 == 0){
                    //cout<<"Calcular simpson 1/3"<<endl;
                    simpson13 integral(x, y);
                    return simpson13(x, y).calcular();
                }

                // 2. Si la cantidad de segmentos es multiplos de 3, aplicar Simpson 3/8 y retornar el valor calculado.

                if (n % 3 == 0){
                    //cout<<"Calcular simpson 3/8"<<endl;
                    simpson38 integral(x, y);
                    return simpson38(x, y).calcular();
                }

                // 3. Dividir entre 2 y buscar el multiplo de 3 impar más cercano

                cout<<"Calcular la integracion con " <<n<< " segmentos" << endl;

                
                int limite = n/2;

                if (limite % 3 !=0){
                    limite++;
                }
                
                cout<<"Calcular limite: "<<limite<<endl;


                // Si el limite es par
                if (limite % 2 == 0){
                    limite +=3;
                }

                cout<<"Calcular integral combinado Simpson 1/3 con "
                    << n-limite <<" segmentos"
                    << " Y simpson 3/8 con "<<limite<<" segmentos"<<endl;

                int n1 = n-limite;
                vector<double> x13 = {x.begin(), x.begin() + (n1 + 1)}; 
                vector<double> x38 = {x.begin() + (n-limite) , x.end()}; 

                vector<double> y13 = {y.begin(), y.begin() + (n1 + 1)}; 
                vector<double> y38 = {y.begin() + (n-limite) , y.end()};


                simpson13 integracion1(x13, y13);
                simpson38 integracion2(x38, y38);

                cout<<"-------Tabla 1---------- "<<endl;
                integracion1.imprimir_tabla(cout);
                cout<<"-------Tabla 2---------- "<<endl;
                integracion2.imprimir_tabla(cout);

                cout<<"FIN"<<endl;
                return integracion1.calcular()+integracion2.calcular();
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
            int n; /*<! Valor del número de segmentos*/
    };
    
    
    
    
}

#endif