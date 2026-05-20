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
}