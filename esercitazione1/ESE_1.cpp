#include <fstream>
#include <iostream>
//per evitare di scrivere sempre std:: avrei potuto utilizzare using namespace std
int main(int argc, const char *argv[]) {
if (argc <2) {
    std::cerr << "Error: filename not specified\n";
    return 1;
}
//dal testo dell'esercitazione posso assumere che ci sia solo un file
std:: ifstream ifs(argv[1]);
if (ifs.is_open()){
    //assumo, come da indicazioni del docente, che il file sia formattato come nell'esempio fornito
    for(int i = 0; i <= 2; i++){
        
       
        std:: string location;
        double temp1;
        double temp2;
        double temp3;
        double temp4;
        ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
        double average = (temp1+temp2+temp3+temp4)/4.0;
        std::cout << location<< " " << average << "\n" ;
        }
    }
else {
std::cerr << "Error: file " << argv[1] <<" not found\n";;

return 2;
}
return 0;
}