#include "gradiente_coniugato.hpp"
#include <iostream>
#include "Eigen/Eigen"
int main(){
    //sistema 2x2
    Eigen::MatrixXd A(2,2);
    A << 4, 1,
        1, 3;
    std::cout<< "A = " << A << "\n";
    Eigen::VectorXd b(2);
    b << 6,7;
    std::cout << "b = " << b<< "\n";
    auto x = gradiente_coniugato(A,b);
    if(x.has_value()){
        std::cout << "Soluzione: x = "<< *x << "\n";
    }
    Eigen::MatrixXd G(2,2);
    G << 1,2,
        3,4;
    std::cout << "G = " << G << "\n";
    Eigen::VectorXd g(2);
    g << 0,0;
    auto x_g = gradiente_coniugato(G,g);
    if (!x_g.has_value()){
        std::cout << "OK: la matrice non simmetrica G non ha restituito nulla.\n";
    }
    return 0;
}