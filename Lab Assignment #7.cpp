// Lab Assignment #7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class RecursionClass
{
public:
    int binToDec(string bin, int i = 0);
    int decToBin(int dec);
    char decToASCII(int n);
    int factorial(int n);
    int fibonacci(int n);
    int gcd(int x, int y);
    int expo(int x, int y);
    int sumArray(int size, int array[]);
    void quickSort(int [], int, int);
    int partition(int [], int, int);
    void hanoi(int n, string source, string dest, string temp);
};

class container
{
public:
    void menu();
    void btdOutput(int bin);
    void dtbOutput(int dec);
    void dtAOutput(char c);
    void factorialOutput(int factorial);
    void fibonacciOutput(int n);
    void gcdOutput(int gcd);
    void expoOutput(int expo);
    void sumArrayOutput(int arraySum);
    void hanoiOutput(string source, string dest);
    void qsOutput(int qsArr[], int qsSize);
};

int main()
{
    RecursionClass rC;
    container c;
    int usersChoice;
    int dec;
    int oDec;
    int fac;
    int fib;
    int num1;
    int num2;
    int base;
    int expo;
    int size;
    int numDisks;
    int qsSize;
    int i;
    string bin;
    string hex;

    do {
        c.menu();
        cout << "Enter your choice: ";
        cin >> usersChoice;

        switch (usersChoice)
        {
        case 1:
            cout << "Enter binary number: ";
            cin >> bin;
            c.btdOutput(rC.binToDec(bin));
            break;

        case 2:
            cout << "Enter decimal number: ";
            cin >> dec;
            c.dtbOutput(rC.decToBin(dec));
            break;

        case 3:
            cout << "Enter decimal number: ";
            cin >> oDec;
            c.dtAOutput(rC.decToASCII(oDec));
            break;

        case 4:
            cout << "Enter the number you want to calculate a factorial for: ";
            cin >> fac;
            c.factorialOutput(rC.factorial(fac));
            break;

        case 5:
            cout << "Enter the number of Fibonacci numbers you want to generate: ";
            cin >> fib;
            c.fibonacciOutput(fib);
            break;

        case 6:
            cout << "Enter your first number: ";
            cin >> num1;
            cout << "Enter your second number: ";
            cin >> num2;
            c.gcdOutput(rC.gcd(num1, num2));
            break;

        case 7:
            cout << "Enter your number: ";
            cin >> base;
            cout << "Enter the exponent: ";
            cin >> expo;
            c.expoOutput(rC.expo(base, expo));
            break;

        case 8:
            cout << "Enter the size of your array: ";
            cin >> size;

            if (size <= 0)   // avoids array of size 0 or less
                cout << "Array cannot be of size " << size << endl;

            else
            {
                int* arr = new int[size];

                cout << "Enter the elements of your array "
                    << "either one by one or all at once: ";

                for (i = 0; i < size; i++)
                    cin >> arr[i];

                c.sumArrayOutput(rC.sumArray(size, arr));

                delete [] arr;
            }
            break;

        case 9:
            cout << "Enter the number of disks: ";
            cin >> numDisks;
            if (numDisks <= 0)
                cout << "Invalid number of disks!\n";
            else
            {
                rC.hanoi(numDisks, "A", "B", "C");
                cout << "All disks have been moved!\n";
            }
            break;

        case 10:
            cout << "Enter the size of your array: ";
            cin >> qsSize;

            if (qsSize <= 0)   // avoids array of size 0 or less
                cout << "Array cannot be of size " << qsSize << endl;

            else
            {
                int* qsArr = new int[qsSize];

                cout << "Enter the elements of your array "
                    << "either one by one or all at once: ";

                for (i = 0; i < qsSize; i++)
                    cin >> qsArr[i];

                c.qsOutput(qsArr, qsSize);

                delete[] qsArr;
            }
            break;

        case 11:
            cout << "Ending program...\n";
            break;

        default:
            cout << "Please enter a valid choice\n";
        }
    } while (usersChoice != 11);
}

void container::btdOutput(int bin)
{
    cout << "Decimal: " << bin << endl;
}

void container::dtbOutput(int dec)
{
    cout << "Binary: " << dec << endl;
}

void container::dtAOutput(char c)
{
    cout << "ASCII: " << c << endl;
}

void container::factorialOutput(int factorial)
{
    cout << "Factorial: " << factorial << endl;
}

void container::fibonacciOutput(int n)
{
    RecursionClass fRC;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++)
        cout << fRC.fibonacci(i) << " ";
    cout << endl;
}

void container::gcdOutput(int gcd)
{
    cout << "GCD: " << gcd << endl;
}

void container::expoOutput(int expo)
{
    cout << "Exponentation: " << expo << endl;
}

void container::sumArrayOutput(int arraySum)
{
    cout << "Sum: " << arraySum << endl;
}

void container::hanoiOutput(string source, string dest)
{
    cout << "Moving disk from " << source
        << " to " << dest << endl;
}

void container::qsOutput(int qsArr[], int qsSize)
{
    RecursionClass qsRC;

    qsRC.quickSort(qsArr, 0, qsSize - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < qsSize; i++)
        cout << qsArr[i] << " ";
    cout << endl;
}

int RecursionClass::binToDec(string bin, int i)
{
    int n = bin.length();

    if (i == n - 1)
        return bin[i] - '0';
    else
        return ((bin[i] - '0') << (n - i - 1)) + binToDec(bin, i + 1);
}

int RecursionClass::decToBin(int dec)
{
    if (dec == 0)
        return 0;
    else
        return (dec % 2 + 10 * decToBin(dec / 2));
}

char RecursionClass::decToASCII(int n)
{
    if (n < 10)
        return '0' + n;
    else if (n < 16)
        return 'A' + n - 10;
    else
        return decToASCII(n - 16) + decToASCII(n % 16);
}

int RecursionClass::factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

int RecursionClass::fibonacci(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int RecursionClass::gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int RecursionClass::expo(int x, int y)
{
    if (y == 0)
        return 1;
    else
        return x * expo(x, y - 1);
}

int RecursionClass::sumArray(int size, int array[])
{
    if (size == 0) // base case for when array
        return 0;  // reaches first/0th element
    else
        return array[size - 1] + sumArray(size - 1, array);
}

void RecursionClass::hanoi(int n, string source, string dest, string temp)
{
    container hC;

    if (n > 0)
    {
        hanoi(n - 1, source, temp, dest);
        hC.hanoiOutput(source, dest);
        hanoi(n - 1, temp, dest, source);
    }
}

void RecursionClass::quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);

        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int RecursionClass::partition(int arr[], int start, int end)
{
    int pivotValue = arr[start];
    int pivotPosition = start;

    for (int pos = start + 1; pos <= end; pos++)
    {
        if (arr[pos] < pivotValue)
        {
            swap(arr[pivotPosition + 1], arr[pos]);
            swap(arr[pivotPosition], arr[pivotPosition + 1]);
            pivotPosition++;
        }
    }
    return pivotPosition;
}

void container::menu()
{
    cout << "1. Binary to Decimal Conversion\n"              // completed
        << "2. Decimal to Binary Conversion\n"               // completed
        << "3. Decimal to ASCII\n"                           // completed
        << "4. Factorial\n"                                  // completed
        << "5. Generate Fibonacci Numbers\n"                 // completed
        << "6. Find Greatest Common Denominator\n"           // completed
        << "7. Raising a Number to a Power/Exponentiation\n" // completed
        << "8. Sum Array Elements\n"                         // completed
        << "9. Towers of Hanoi\n"                            // completed
        << "10. QuickSort\n"                                 // completed
        << "11. End Program\n";                              // completed
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
