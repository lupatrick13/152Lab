#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

const int max = 5;
enum class why {singularmatrix, zerorow, noconvergence};
int ps[5];
double h[5][5];
double hinv[5][5];
double z[5][5];
int i;
int j;
int n;

void singular(why w)
{
    
    switch (w) {
        case why::singularmatrix :
            printf("Singular matrix in decompose.\n");
            break;
        case why::zerorow :
            printf("Matrix with zero row in decompose.\n");
            break;
        case why::noconvergence :
            printf("No convergence in improve.\n");
            break;
        }
    }

    double abs(double x)
    {
        double abs;

        if (x < 0) x = -x;
        abs = x;

        return abs;
    }

    void decompose(int n, double a[5][5], double lu[5][5])
    {
        double scales[5];
        int i;
        int j;
        int k;
        int pivotindex;
        double normrow;
        double pivot;
        double size;
        double biggest;
        double mult;
        for( i = 1; i <= n; i++) {
                ps[(i)-1] = i;
                normrow = 0;
                for( j = 1; j <= n; j++) {
                        lu[(i)-1][(j)-1] = a[(i)-1][(j)-1];
                        if (normrow < abs(lu[(i)-1][(j)-1])) normrow = abs(lu[(i)-1][(j)-1]);
                    }
                if (normrow != 0) scales[(i)-1] = 1/normrow;
                else {
                        scales[(i)-1] = 0;
                        
                        singular(why::zerorow);
                    }

            }
        for( k = 1; k <= n - 1; k++) {
                pivotindex = 0;
                biggest = 0;
                for( i = k; i <= n; i++) {
                        size = abs(lu[(ps[(i)-1])-1][(k)-1])*scales[(ps[(i)-1])-1];
                        if (biggest < size) {
                                biggest = size;
                                pivotindex = i;
                            }
                    }
                if (biggest == 0) 
                    singular(why::singularmatrix);
                else {
                        if (pivotindex != k) {
                                j = ps[(k)-1];
                                ps[(k)-1] = ps[(pivotindex)-1];
                                ps[(pivotindex)-1] = j;
                            }
                        pivot = lu[(ps[(k)-1])-1][(k)-1];
                        for( i = k + 1; i <= n; i++) {
                                mult = lu[(ps[(i)-1])-1][(k)-1]/pivot;
                                lu[(ps[(i)-1])-1][(k)-1] = mult;
                                if (mult != 0) {
                                        for( j = k + 1; j <= n; j++) {
                                                lu[(ps[(i)-1])-1][(j)-1] = lu[(ps[(i)-1])-1][(j)-1] - mult*lu[(ps[(k)-1])-1][(j)-1];
                                            }
                                    }
                            }
                    }

            }
        if (lu[(ps[(n)-1])-1][(n)-1] == 0) 
            singular(why::singularmatrix);
    }

    void solve(int n, double lu[5][5], double b[5], double x[5])
    {
        int i;
        int j;
        double dot;
        for( i = 1; i <= n; i++) {
                dot = 0;
                for( j = 1; j <= i - 1; j++) {
                        dot = dot + lu[(ps[(i)-1])-1][(j)-1]*x[(j)-1];
                    }
                x[(i)-1] = b[(ps[(i)-1])-1] - dot;
            }
        for( i = n; i >= 1; i--) {
                dot = 0;
                for( j = i + 1; j <= n; j++) {
                        dot = dot + lu[(ps[(i)-1])-1][(j)-1]*x[(j)-1];
                    }
                x[(i)-1] = (x[(i)-1] - dot)/lu[(ps[(i)-1])-1][(i)-1];
            }
    }

    void invert(int n, double a[5][5], double ainv[5][5])
    {
        double lu[5][5];
        double b[5];
        double x[5];
        int i;
        int j;
        
        decompose(n, a, lu);
        for( j = 1; j <= n; j++) {
                for( i = 1; i <= n; i++) {
                        if (i == j) b[(i)-1] = 1;
                        else b[(i)-1] = 0;

                    }
                
                solve(n, lu, b, x);
                for( i = 1; i <= n; i++) ainv[(i)-1][(j)-1] = x[(i)-1];
            }
    }

    void multiply(int n, double a[5][5], double b[5][5], double p[5][5])
    {
        int i;
        int j;
        int k;
        double sum;
        for( i = 1; i <= n; i++) {
                for( j = 1; j <= n; j++) {
                        sum = 0.0;
                        for( k = 1; k <= n; k++) {
                                sum = sum + a[(i)-1][(k)-1]*b[(k)-1][(j)-1];
                            }
                        p[(i)-1][(j)-1] = sum;
                    }
            }
    }

    void printmatrix(double m[5][5])
    {
        int i;
        int j;
        cout << endl;
        for( i = 1; i <= n; i++) {
                for( j = 1; j <= n; j++) printf("%15.6f", m[(i)-1][(j)-1]);
                cout << endl;
            }
        cout << endl;
    }

    int main(int argc, char *args[])
    {
        auto _start = steady_clock::now();

        n = 5;
        for( i = 1; i <= n; i++) {
                for( j = 1; j <= n; j++) {
                        h[(i)-1][(j)-1] = 1.0/(i + j - 1);
                    }
            }
        cout << endl;
        printf("Hilbert matrix:\n");
        
        printmatrix(h);
        
        invert(n, h, hinv);
        printf("Hilbert matrix inverted:\n");
        
        printmatrix(hinv);
        
        multiply(n, h, hinv, z);
        printf("Hilbert matrix multiplied by its inverse:\n");
        
        printmatrix(z);
        
        invert(n, hinv, h);
        printf("Inverse matrix inverted:\n");
        
        printmatrix(h);

        auto _end = steady_clock::now();
        long _elapsed = duration_cast<milliseconds>(_end - _start).count();
        printf("\n[%ld milliseconds execution time.]\n", _elapsed);
    }
