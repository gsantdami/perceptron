#include <stdio.h>
#include <stdlib.h>

int main() {
    int entradas[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    int saidas[4] = {0,0,0,1};

    float w1 = 0.4;
    float w2 = 0.4;
    float b  = 0.4;

    // 📁 arquivo de pontos
    FILE *f = fopen("pontos.dat", "w");
    for (int i = 0; i < 4; i++) {
        fprintf(f, "%d %d %d\n", entradas[i][0], entradas[i][1], saidas[i]);
    }
    fclose(f);

    FILE *g = fopen("plot.plt", "w");

    fprintf(g, "set title 'Perceptron AND'\n");
    fprintf(g, "set xrange [-0.5:1.5]\n");
    fprintf(g, "set yrange [-0.5:1.5]\n");
    fprintf(g, "set grid\n");

    fprintf(g, "set key outside right top\n");
    fprintf(g, "set key spacing 1.8\n");
    fprintf(g, "set key box \n");

    fprintf(g, "w1 = %f\n", w1);
    fprintf(g, "w2 = %f\n", w2);
    fprintf(g, "b = %f\n", b);

    fprintf(g, "f(x) = (1 - w1*x - b)/w2\n");

    fprintf(g,
    "plot 'pontos.dat' using 1:2 with points pt 7 ps 1.5 lc rgb 'blue' title 'Pontos', \\\n"
    "     'pontos.dat' using 1:2:(stringcolumn(3)) with labels offset 1,1 notitle, \\\n"
    "     f(x) with lines title 'Threshold'\n"
);

    fclose(g);

    system("env -u LD_LIBRARY_PATH gnuplot -persist plot.plt");

    return 0;
}