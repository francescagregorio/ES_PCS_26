#include <iostream>
#include <fstream>
using namespace std;
 int main(void) {
     string filename = "input_es1.txt"; 
     ifstream ifs(filename); 
     if ( ifs.is_open() ) { 
        // Check if file successfully opened
         while( !ifs.eof() ) { 
            string location;
            double temp; 
            ifs >> location >> temp;
             // also >> : S×T →S 
             cout <<  "Temperature at " << location << " is " << temp << "\n"; }
             }
              return 0;
             }