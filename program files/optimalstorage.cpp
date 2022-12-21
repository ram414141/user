
#include <bits/stdc++.h>
using namespace std;
int k = 0;

void print(int b[], int l, int op, int m)
{
    b[k] = op;
    k++;
}

void OptimalPath(int L[], int n, int b[], int l, int m)
{
    int OP = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum = sum + L[j];
        }
        OP = OP + sum;
    }
    cout << "= " << OP << endl;
    print(b, l, OP, m);
}

void display(int a[], int n, int b[], int l, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    OptimalPath(a, n, b, l, m);
}

void findPermutations(int a[], int n, int b[], int m, int l)
{
    sort(a, a + n);
    do
    {
        display(a, n, b, l, m);
    } while (next_permutation(a, a + n));
}

unsigned int factorial(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int a[n];
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = factorial(n);
    int b[l];
    int m = sizeof(b) / sizeof(b[0]);
    findPermutations(a, n, b, m, l);
    cout << "The optimal length is " << b[0] << endl;

    return 0;
}