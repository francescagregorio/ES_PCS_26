%%realizzazione dei grafici

d = [4; 8; 16; 32; 64; 128; 256; 512; 1024; 2048; 4096; 8192];
y_bubble = [4.16e-07; 7.5e-07; 2.333e-06; 7.792e-06; 2.9958e-05; 0.000117416; 0.000502667; 0.00192137; 0.00753867; 0.0210212; 0.0583772; 0.210822];
y_inser = [4.58e-07; 5.41e-07; 9.59e-07; 2.625e-06; 8.833e-06; 3.5041e-05; 0.000116791; 0.000539625; 0.00143079; 0.00417592; 0.01176; 0.0442274];
y_select = [2.5e-07; 5.84e-07; 1.666e-06; 4.875e-06; 1.6166e-05; 5.7625e-05; 0.000347958; 0.000802792; 0.00239254; 0.0064215; 0.0178292; 0.0694337];
y_sort = [1.209e-06; 1.125e-06; 1.792e-06; 5.291e-06; 9.916e-06; 2.1541e-05; 6.75e-05; 0.000101833; 0.000220958; 0.000328125; 0.000509167; 0.00109471];
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