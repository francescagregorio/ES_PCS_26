#include "Eigen/Eigen"
#include "soluzione_corretta.hpp"
#include <iostream>
/*Dal momento che soluzione_corretta verrà usata in tutti i test 
in test_gradiente_coniugato.cpp, è opportuno testarla. 
Se fose sbagliata, tutti i test darebbero dei risultati falsi */
int main(){
    //esempio a
    Eigen::VectorXd x_a_1(2);
    x_a_1 << 1,2;
    std::cout << "x_a_1" <<x_a_1 << "\n";
    Eigen::VectorXd x_a_2(2);
    x_a_2 << 2,2;
    std::cout << "x_a_2" << x_a_2 << "\n";
    if (!soluzione_corretta(x_a_1,x_a_1)){
        std::cerr << "ERRORE: falso negativo!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_a_2,x_a_2)){
        std::cerr << "ERRORE: falso negativo!\n";
        return EXIT_FAILURE;
    }
    if (soluzione_corretta(x_a_2, x_a_1)){
        std::cerr << "ERRORE: falso positivo!\n";
        return EXIT_FAILURE;
    }
    if (soluzione_corretta(x_a_1, x_a_2)){
        std::cerr << "ERRORE: falso positivo!\n";
        return EXIT_FAILURE;
    }
    //esempio b
    Eigen::VectorXd x_b_1(3);
    x_b_1 << 3.1415, 9.26535, 8.9793;
    std::cout << "x_b_1" <<x_b_1 << "\n";
    Eigen::VectorXd x_b_2(2);
    x_b_2 << 3.14155, 9.265355, 8.97935 ;
    std::cout << "x_b_2" << x_b_2 << "\n";
    if (!soluzione_corretta(x_b_1,x_b_1)){
        std::cerr << "ERRORE: falso negativo!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_b_2,x_b_2)){
        std::cerr << "ERRORE: falso negativo!\n";
        return EXIT_FAILURE;
    }
    if (soluzione_corretta(x_b_1, x_b_2)){
        std::cerr << "ERRORE: falso positivo!\n";
        return EXIT_FAILURE;
    }
    if (soluzione_corretta(x_b_2, x_b_1)){
        std::cerr << "ERRORE: falso positivo!\n";
        return EXIT_FAILURE;
    }
    //esempio c
    Eigen::VectorXd x_c_1(4);
    x_c_1 << 0.000011111, 0.000022222, 0.000033333;
    std::cout << "x_c_1" <<x_c_1 << "\n";
    Eigen::VectorXd x_c_2(2);
    x_c_2 << 3.14155, 9.265355, 8.97935 ;
    std::cout << "x_c_2" << x_c_2 << "\n";
    if (!soluzione_corretta(x_c_1,x_c_1)){
        std::cerr << "ERRORE: falso negativo!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_c_2,x_c_2)){
        std::cerr << "ERRORE: falso negativo!\n";
        return EXIT_FAILURE;
    }
    if (soluzione_corretta(x_c_1, x_c_2)){
        std::cerr << "ERRORE: falso positivo!\n";
        return EXIT_FAILURE;
    }
    if (soluzione_corretta(x_c_2, x_c_1)){
        std::cerr << "ERRORE: falso positivo!\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}