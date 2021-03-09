#include "Matrix.h"

using namespace std;
void showHelp();

int main(int argc, char* argv[])
{
    unsigned short listChoice;
    char repeat;

  do {

    for (short i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], "-h") == 0 && i == 1)
            {
                showHelp();
            }
        }
    cout << "This program can add, multiply and invert 2 by 2 and 3 by 3 matrices \n";
    cout << "To enter a matrix you can simply enter the numbers in a matrix style\na b c\nd e f\ng h i\nEnter the associated number to begin\n";
    cout << "1.Invert a 2 by 2 matrix.\n2.Add and multiply two 2 by 2 matrices.\n3.Invert a 3 by 3 matrix.\n4.Add and multiply two 3 by 3 matrices.\n";

    Matrix2by2 M1, M2, M3;
    Matrix3by3 N1, N2, N3;
    while (!(cin >> listChoice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid choice\n";
    }
    switch (listChoice)
    {

        case 1:
            M1.setMatrix();
            M2 = M1.invertMatrix();
            // The invertMatrix method will set the isPrintable property of the matrix to false in case it's not invertible
            M2.isPrintable = M1.isPrintable;
            M2.getMatrix();
            break;

        case 2:
            M1.setMatrix();
            M2.setMatrix();
            cout << "The sum is\n";
            (M1 + M2).getMatrix();
            cout << "The product is\n";
            (M1 * M2).getMatrix();
            break;

        case 3:
            N1.setMatrix();
            N2 = N1.invertMatrix();
            N2.isPrintable = N1.isPrintable;
            N2.getMatrix();
            break;

        case 4:
            N1.setMatrix();
            N2.setMatrix();
            cout << "The sum is\n";
            (N1 + N2).getMatrix();
            cout << "The product is\n";
            (N1 * N2).getMatrix();
            break;

        default:
            cout << "Please enter a valid choice\n";
            break;
    }
    cout << "Enter c or C to continue.\n";
    cin >> repeat;
    } while (repeat == 'c' || repeat == 'C');

return 0;
}

void showHelp()
{
    cout << "To enter a matrix you can simply enter the numbers in a matrix style\na b c\nd e f\ng h i\n";
}
