#pragma once
#include <iostream>
#include "Eigen/Eigen"
#include <optional>
std::optional<Eigen::VectorXd> gradiente_coniugato(Eigen::MatrixXd& A, Eigen::VectorXd& b){
    double tol = 1e-10; //tolleranza 
    //check che la matrice sia quadrata
    const Eigen::Index n_righe = A.rows(); //n righe
    const Eigen::Index n_colonne = A.cols(); //n colonne
    if (n_righe != n_colonne){
        std::cout<<"La matrice non è quadrata!\n";
        return std::nullopt;
    }
    if (n_righe != b.size()){
        std::cout <<"Dimensioni della matrice e del vettore termine noto incompatibili!\n";
        return std::nullopt;
    }
    //check che la matrice sia simmetrica
    /*Se A è simmetrica, A = A.transpose(); faccio il check 
    con una tolleranza dal momento che sto lavorando con dei double e in precisione finita di calcolo*/
    if (!A.isApprox(A.transpose(), tol)){
        //la matrice non è simmetrica --> non posso procedere
        std::cout<<"La matrice non è simmetrica!\n";
        return std::nullopt;
    }
    //Check che la matrice sia definita positiva
    /*Una matrice definita positiva ha tutti gli autovalori maggiori di 0
    Uso la funzione SelfAdjointEigenSolver per valutare gli autovalori di A (simmetrica)*/
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> solver(A);
    auto autovalori = solver.eigenvalues();
    if (autovalori.minCoeff()< tol){
        std::cout << "La matrice non è definita positiva!\n";
        return std::nullopt;
    }
    /*Il check sull'invertibilità della matrice è superfluo dal momento che 
    una matrice simmetrica e definita positiva è sempre invertibile*/
    //creo il vettore x che inizializzo con 0 e che in seguito conterrà la soluzione iterata
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n_righe);
    //creo il vettore residuo
    Eigen::VectorXd r = b - A*x;
    //creo il vettore direzione di discesa p
    Eigen::VectorXd p = r;
    /*Se b è uguale a 0, il vettore nullo è soluzione;
    inoltre, in tal caso res è 0, quindi il ciclo non viene mai avviato*/
    const double res_norm_0 = r.norm(); //valore che utilizzerò nella tolleranza relativa
    const double res_tol = 1e-11;
    unsigned int it = 0; //lo uso come "contatore" nel ciclo while
    while(it < 10* n_righe && r.norm()>res_tol*res_norm_0){ 
        /*In aritmetica floating point, la convergenza non è garantita in al più n passi;
        fissiamo una condizione sul numero massimo di iterazioni (10*n_righe) E una 
        sulla norma del residuo. Usiamo entrambi per evitare loop infiniti nel caso in cui 
        la norma del residuo non scenda mai al di sotto della soglia */
        //in c++ le moltiplicazioni sono più veloci delle divisioni
        //dal momento che torneranno utili più volte, valuto: 
        const Eigen::VectorXd Ap = A*p;
        const double pAp = (p.transpose()*Ap).value(); //è il denominatore nella formula di alpha e beta
        //check che pAp non sia nullo, ovvero che non abbia modulo nullo
        if (std::abs(pAp) < tol){
	        std::cout << "Il denominatore nella formula di alpha e beta è nullo\n";
	        return std::nullopt;
	    }
        const double alpha = (p.transpose()*r).value()/pAp;
        x = x + alpha*p;
        r = b - A*x;
        /*poichè A è simmetrica A.transpose = A, quindi
        (A*p).transpose() = p.transpose()*A.transpose() = p.traspose*A */
        const double beta = (Ap.transpose()*r).value()/pAp;
        p = r - beta*p;
        it++;
    }
    return x;
}
