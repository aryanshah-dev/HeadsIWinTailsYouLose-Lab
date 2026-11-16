
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

int flipCoin(int n, double p, mt19937& generator)
{
    uniform_real_distribution<double> distribution(0.0, 1.0);

    int heads = 0;

    for (int i = 0; i < n; i++)
    {
        if (distribution(generator) < p)
        {
            heads++;
        }
    }

    return heads;
}

int main()
{
    int flips[] = {100, 200, 300, 400, 500};
    double probabilities[] = {0.25, 0.50, 0.75};
    int m = 10;

    random_device rd;
    mt19937 generator(rd());

    cout << left << setw(20) << "Number of Flips (n)"
         << setw(20) << "Trial Number (m)"
         << setw(25) << "Probability (p)"
         << "Number of Heads" << endl;

    cout << string(80, '-') << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                int heads = flipCoin(flips[j], probabilities[i], generator);

                cout << left << setw(20) << flips[j]
                     << setw(20) << k
                     << setw(25) << probabilities[i]
                     << heads << endl;
            }
        }
    }

    return 0;
}
