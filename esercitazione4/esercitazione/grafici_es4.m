%%realizzazione dei grafici
d = [4; 8; 16; 32; 64; 128; 256; 512; 1024; 2048; 4096; 8192];
y_bubble = [4.58e-07; 7.08e-07; 2.25e-06; 8.792e-06; 3.4542e-05; 0.000185542; 0.000515166; 0.00222046; 0.00667708; 0.0218287; 0.0623628; 0.231794];
y_inser = [4.17e-07; 4.58e-07; 1.125e-06; 2.875e-06; 1.0958e-05; 3.0917e-05; 0.000137625; 0.000542583; 0.00148908; 0.00413771; 0.0113358; 0.0441757];
y_select = [3.34e-07; 6.25e-07; 2e-06; 5.458e-06; 1.7792e-05; 5.3958e-05; 0.000228792; 0.000886542; 0.00243296; 0.00507096; 0.0179765; 0.0694559];
y_sort = [2.292e-06; 1e-06; 1.959e-06; 5.459e-06; 9.708e-06; 2.05e-05; 4.6833e-05; 0.000122458; 0.000229292; 0.000271; 0.000536083; 0.00114533];
figure
loglog(d, y_bubble, "--o")
hold on
loglog(d, y_inser,  "--o")
loglog(d, y_select, "--o")
loglog(d, y_sort, "--o")
legend("bubble sort", "insertion sort", "selection sort", "std::sort")
xlabel('dimensione vettore (N)');
ylabel('tempo (secondi)');
title('Confronto algoritmi di ordinamento');