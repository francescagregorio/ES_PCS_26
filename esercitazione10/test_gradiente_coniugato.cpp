#include "gradiente_coniugato.hpp"
#include <iostream>
#include "Eigen/Eigen"
#include "soluzione_corretta.hpp"
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
    Eigen::VectorXd x_a_ex(2);
    x_a_ex << 1,2;
    std::cout << "Soluzione: "<< x_a_ex <<"\n";
    if (!x_a.has_value()){
        std::cerr << "ERRORE: il sistema Ax = a ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_a.value(), x_a_ex)){
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
    b << 6, 12, 14;
    std::cout << "b = " << b << "\n";
    Eigen::VectorXd x_b_ex(2);
    x_b_ex << 1, 2, 3;
    std::cout <<"Soluzione: "<< x_b_ex << "\n";
    auto x_b = gradiente_coniugato(B,b);
    if (!x_b.has_value()){
        std::cerr << "ERRORE: il sistema Bx = b ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_b.value(), x_b_ex)){
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
    std::cout << "Soluzione: " << c << "\n";
    auto x_i = gradiente_coniugato(I, c);
    if (!x_i.has_value()){
        std::cerr << "ERRORE: il sistema Ix = c ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_i.value(), c)){
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
    Eigen::VectorXd x_d_ex = Eigen::VectorXd::Ones(5);
    std::cout << "Soluzione: " << x_d_ex << "\n";
    auto x_d= gradiente_coniugato(D, d);
    if (!x_d.has_value()){
        std::cerr << "ERRORE: il sistema Dx = d ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_d.value(), x_d_ex)){
        std::cerr <<"ERRORE: il metodo del gradiente coniugato ha restituito la soluzione errata!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Il sistema 5x5 Dx = d ha restituito il risultato corretto\n";  
    //matrice 1x1
    Eigen::MatrixXd E(1,1);
    E << 5.0;
    std::cout << "E = " << E << "\n";
    Eigen::VectorXd e(1);
    e << 10.0;
    std::cout<< "e = " << e << "\n";
    Eigen::VectorXd x_e_ex(1);
    x_e_ex << 2.0;
    std::cout << "Soluzione: " << x_e_ex << "\n";
    auto x_e= gradiente_coniugato(E, e);
    if (!x_e.has_value()){
        std::cerr << "ERRORE: il sistema Ex = e ha restuituito nullopt!\n";
        return EXIT_FAILURE;
    }
    if (!soluzione_corretta(x_e.value(), x_e_ex)){
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
    //test vettore dei termini noti di dimensione diversa
    Eigen::VectorXd m(3);
    m << 3,3,3;
    std::cout << "m = "<< m << "\n";
    auto x_m = gradiente_coniugato(I, m);
    if (x_m.has_value()){
        std::cerr <<"ERRORE: dimensioni non compatibili tra I (4x4) e m (3), ma il metodo del gradiente coniugato restituisce una soluzione!\n";
        return EXIT_FAILURE;
    }
    std::cout<<"OK: le dimensioni di I e m non sono compatibili, quindi il metodo del gradiente coniugato non restituisce nulla\n";
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
    J << 1, 0,
        0, 0; //autovalori 1, 0 
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