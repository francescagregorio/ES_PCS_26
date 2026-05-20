#include "gradiente_coniugato.hpp"
#include <iostream>
#include "Eigen/Eigen"
/*Sia Ax = b un sistema lineare; un vettore y (di dimensioni coerenti) è
soluzione di questo sistema se Ay - b = 0; lavorando in c++, devo
considerare una tolleranza, però*/
bool soluzione_corretta(const Eigen::MatrixXd&A, Eigen::VectorXd& b, const Eigen::VectorXd& x){
    const double tol = 1.0e-12;
    return (A*x - b).norm() < tol;
}

int main(){
    //sistema 2x2
    Eigen::MatrixXd A(2,2);
    A << 4, 1,
        1, 3;
    std::cout<< "A = " << A << "\n";
    Eigen::VectorXd a(2);
    a << 6,7;
    std::cout << "a = " << a<< "\n";
    auto x_a = gradiente_coniugato(A,a);
    if (!x_a.has_value()){
        std::cerr << "ERRORE: il sistema Ax = a ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(A,a, x_a.value())){
        std::cerr <<"ERRORE: il metodo del gradiente coniugato ha restituito la soluzione errata!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Il sistema 2x2 Ax = a ha restituito il risultato corretto\n";
    //sistema 3x3
    Eigen::MatrixXd B(3,3);
    B << 4, 1, 0, 
        1, 4, 1,
        0, 1, 4;
    std::cout << "B = " << B <<"\n";
    Eigen::VectorXd b(3);
    b << 8, 12, 13;
    std::cout << "b = " << b << "\n";
    auto x_b = gradiente_coniugato(B,b);
    if (!x_b.has_value()){
        std::cerr << "ERRORE: il sistema Bx = b ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(B,b, x_b.value())){
        std::cerr <<"ERRORE: il metodo del gradiente coniugato ha restituito la soluzione errata!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Il sistema 3x3 Bx = b ha restituito il risultato corretto\n";
    //matrice I 4x4
    const int n = 4;
    Eigen::MatrixXd I = Eigen::MatrixXd::Identity(n,n);
    std::cout << "I = " << I <<"\n";
    Eigen::VectorXd c = Eigen::VectorXd::Random(n);
    std::cout << "c = " << c << "\n";
    auto x_i = gradiente_coniugato(I, c);
    if (!x_i.has_value()){
        std::cerr << "ERRORE: il sistema Ix = c ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(I,c, x_i.value())){
        std::cerr <<"ERRORE: il metodo del gradiente coniugato ha restituito la soluzione errata!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Il sistema 3x3 Ix = c ha restituito il risultato corretto\n";
    //matrice 5x5
    Eigen::MatrixXd D(5,5);
    D << 4, 0, 0, 0, 0,
        0, 2, 0, 0, 0,
        0, 0, 7, 0, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 5;
    std::cout << "D = " << D <<"\n";
    Eigen::VectorXd d(5);
    d << 4, 2, 7, 1, 5;
    std::cout << "d = " << d << "\n";
    auto x_d= gradiente_coniugato(D, d);
    if (!x_d.has_value()){
        std::cerr << "ERRORE: il sistema Dx = d ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(D,d, x_d.value())){
        std::cerr <<"ERRORE: il metodo del gradiente coniugato ha restituito la soluzione errata!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Il sistema 5x5 Dx = d ha restituito il risultato corretto\n";  
    //matrice 1x1
    Eigen::MatrixXd E(1,1);
    E << 5.0;
    std::cout << "E = " << E << "\n";
    Eigen::VectorXd e(1);
    e << 10;
    std::cout<< "e = " << e << "\n";
    auto x_e= gradiente_coniugato(E, e);
    if (!x_e.has_value()){
        std::cerr << "ERRORE: il sistema Ex = e ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(E,e, x_e.value())){
        std::cerr <<"ERRORE: il metodo del gradiente coniugato ha restituito la soluzione errata!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Il sistema 1x1 Ex = e ha restituito il risultato corretto\n";  
    //test matrice non quadrata
    Eigen::MatrixXd F(2,3);
    F << 1, 2, 3,
        3, 2, 1;
    std::cout << "F = " << F << "\n";
    Eigen::VectorXd f(2);
    std::cout << "f = " << f <<"\n";
    auto x_f = gradiente_coniugato(F,f);
    if (x_f.has_value()){
        std::cerr << "ERRORE: matrice non quadrata, non avrebbe dovuto restituire nulla!\n";
        return EXIT_FAILURE;
    }
    std::cout << "OK: la matrice non quadrata F non ha restituito nulla.\n";
    //test matrice non simmetrica
    Eigen::MatrixXd G(2,2);
    G << 1,2,
        3,4;
    std::cout << "G = " << G << "\n";
    Eigen::VectorXd g(2);
    g << 0,0;
    auto x_g = gradiente_coniugato(G,g);
    if (x_g.has_value()){
        std::cerr << "ERRORE: matrice non simmetrica, non avrebbe dovuto restituire nulla!\n";
        return EXIT_FAILURE;
    }
    std::cout << "OK: la matrice non simmetrica G non ha restituito nulla.\n";
    //test matrice non definita positiva - definita negativa
    Eigen::MatrixXd H(2,2);
    H << -1, 0,
        0, -1; //autovalori -1, -1 (entrambi negativi)
    std::cout << "H = " << H << "\n";
    Eigen::VectorXd h(2);
    h << 0,0;
    std::cout << "h = "<< h << "\n";
    auto x_h = gradiente_coniugato(H,h);
    if (x_h.has_value()){
        std::cerr << "ERRORE: matrice non definita positiva, non avrebbe dovuto restituire nulla!\n";
        return EXIT_FAILURE;
    }
    std::cout <<"OK: la matrice definita negativa non ha restituito nulla.\n";
    //test matrice non definita positiva - semidefinita positiva
    Eigen::MatrixXd J(2,2);
    J << -1, 0,
        0, 0; //autovalori -1, 0 (entrambi non positivi)
    std::cout << "J = " << J << "\n";
    Eigen::VectorXd j(2);
    j << 0,0;
    std::cout << "j = "<< j << "\n";
    auto x_j = gradiente_coniugato(J,j);
    if (x_j.has_value()){
        std::cerr << "ERRORE: matrice non definita positiva, non avrebbe dovuto restituire nulla!\n";
        return EXIT_FAILURE;
    }
    std::cout <<"OK: la matrice semidefinita positiva non ha restituito nulla.\n";
    return EXIT_SUCCESS;
}