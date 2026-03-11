#include <fstream>
#include <iostream>

int main(int argc, const char *argv[]) {
if (argc <2) {
    std::cerr << "Error: filename not specified\n";
    return 1;
}
for (int i = 1; i < argc; i ++){
    // gestisco il fatto che in input possa mettere più di un nome di file
std:: ifstream ifs(argv[i]);
if (ifs.is_open()){
    for(i = 0; i <= 2; i++){
        std:: string location;
        double temp1;
        double temp2;
        double temp3;
        double temp4;
        ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
        double average = (temp1+temp2+temp3+temp4)/4.0;
        std::cout << location<< "       " << average << "\n" ;
        
    }
    }
else {
std::cerr << "Error: file " << argv[i] <<" not found\n";
return 2;
}}
return 0;
}