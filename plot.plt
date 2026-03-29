set title 'Perceptron AND'
set xrange [-0.5:1.5]
set yrange [-0.5:1.5]
set grid
w1 = 0.400000
w2 = 0.400000
b = 0.400000
f(x) = (1 - w1*x - b)/w2
plot 'pontos.dat' using 1:2:(stringcolumn(3)) with labels offset 1,1 title 'Pontos', \
     f(x) with lines title 'Fronteira'
