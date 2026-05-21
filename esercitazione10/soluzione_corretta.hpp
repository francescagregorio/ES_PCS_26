#pragma once
#include "Eigen/Eigen"
/*Sia Ax = b un sistema lineare; un vettore y (di dimensioni coerenti) è
soluzione di questo sistema se Ay - b = 0; lavorando in c++, devo
considerare una tolleranza, però*/
bool soluzione_corretta(const Eigen::VectorXd& x, const Eigen::VectorXd& x_ex){
    const double tol = 1.0e-12;
    if (x_ex.norm()< tol){
        return x.norm() < tol;
    }
    return (x-x_ex).norm() < tol*(x_ex.norm());
}
