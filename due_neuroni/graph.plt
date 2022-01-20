set palette model RGB defined ( 0 'blue', 1 'orange' )
set title 'Classificatore binario' 
plot 0.3 + x / 3, 'dati.txt' u 1:2:( $3 == 0 ? 0 : 1 ) w points palette
