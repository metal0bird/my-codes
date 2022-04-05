#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

class Jug
{
    int capacity;
    int value;

public:
    Jug(int n)
    {
        capacity = n;
        value = 0;
    }

    void Fill()
    {
        value = capacity;
    }

    void Empty()
    {
        value = 0;
    }

    bool isFull()
    {
        return value >= capacity;
    }

    bool isEmpty()
    {
        return value == 0;
    }

    void operator[](Jug &B) // B -> A till its full
    {
        int old_value = value;

        value = value + B.value;
        value = value > capacity ? capacity : value;

        B.value = B.value - (value - old_value);
    }

    int getValue()
    {
        return value;
    }
};

int gcd(int n, int m)
{
    if (m <= n && n % m == 0)
        return m;
    if (n < m)
        return gcd(m, n);
    else
        return gcd(m, n % m);
}

bool check(int a, int b, int c) // if c is multiple of HCF of a and b, then possible
{
    if (c > a)
    {
        cout << "A can't handle this much\n";
        return false;
    }
    if (c % gcd(a, b) == 0)
    {
        return true;
    }

    cout << "Can't reach this state with the given jugs\n";
    return false;
}

void solve(Jug A, Jug B, int result)
{
    while (A.getValue() != result)
    {
        if (!A.isFull() && B.isEmpty())
        {
            cout << "Fill B\t";
            B.Fill();
            cout << "(" << A.getValue() << ", " << B.getValue() << ")\n";
        }
        if (A.isFull())
        {
            cout << "Empty A\t";
            A.Empty();
            cout << "(" << A.getValue() << ", " << B.getValue() << ")\n";
        }
        cout << "B->A\t"; // transferring water from B to A
        A[B];
        cout << "(" << A.getValue() << ", " << B.getValue() << ")\n";
    }
}

int main()
{
    int a, b, result;

    cout << "Enter capacity of A:\n";
    cin >> a;
    cout << "Enter capacity of B:\n";
    cin >> b;
    do
    {
        cout << "Enter required water in A:\n";
        cin >> result;
    } while (!check(a, b, result));

    Jug A(a), B(b);
    cout << "----------Output----------\n";
    cout << "\ninitial\t(" << A.getValue() << ", " << B.getValue() << ")\n";
    solve(A, B, result);

    return 0;
}