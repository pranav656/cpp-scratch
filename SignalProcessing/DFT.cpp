
#include <bits/stdc++.h>
/*
This is a try of the discrete fourier transform in C++.
The algorithm explanation is here: https://www.youtube.com/watch?v=ITnPS8HGqLo
The discrete fourier transform is given by the equation:
X_k = sigma(x_n * exp(i*2*pi/N *k*n)). The summation goes from
0 to N-1. n is the number of samples. Applying Euler's equation on this
gives you the expression:
X_k = sigma(x_n * (cos(2pi/N * k*n) - isin(2pi/N * k*n))
The cosine part is the real one and the imaginary part is the sine.
Use FFT for faster computations.
*/

using namespace std;

vector<complex<double>> dft(vector<complex<double>> X)
{
    int N = X.size();
    // assume K is same as N
    int K = N;
    
    // vector of doubles complex
    // numbers representing the output
    vector<complex<double>> output;
    output.reserve(K);
    for(int k = 0; k<K; k++)
    {
       complex<double> res_k = complex<double>(0.0, 0.0);
        for (int n = 0; n<N; n++)
        {
            double realPart = cos(((2*M_PI)/static_cast<double>(N))*k*n);
            double imPart = sin(((2*M_PI)/static_cast<double>(N))*k*n);
            complex<double> w(realPart, -1.0*imPart);
            res_k += X[n] * w;
        }
        output.push_back(res_k);
    }

    return output;
}

int main() {
   int N = 1000;
   double phase = M_PI/4.0;
   //double phase = 0.0;
    double sigK = 3.0;
   vector<complex<double>> signal;
    signal.reserve(N);
    for(int x = 0; x<N; x++)
    {
        // construct the signal cos(2*pi/N*3x + phi)
        auto sample = complex<double>(cos((2*M_PI/static_cast<double>(N))*sigK*static_cast<double>(x) + phase), 0.0);
        signal.push_back(sample);
    }
    vector<complex<double>> res = dft(signal);

    for(int i = 0; i< 6; i++)
    {
        cout<< i << " " << 
            setw(12)<<res[i].real() /static_cast<double>(N)<<" "<<
            setw(12)<<res[i].imag() /static_cast<double>(N)<<"i"<<endl;
    }
}
