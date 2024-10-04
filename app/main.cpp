#include <iostream>
#include <string>
#define COL 2
#define ROW 2

using namespace std;

class MATRIX
{
private:
    int i, j;

public:
    MATRIX();
    void format();
    void getMatrix(float [][COL]);
    void printMatrix(float [][COL]);
    float determinant(float [][COL]);
    void adjugate(float [][COL], float [][COL]);
    void inverse(int, float [][COL], float [][COL]);
    void addition(float [][COL], float [][COL], float [][COL]);
    void subtraction(float [][COL], float [][COL], float [][COL]);
    void multiplication(float [][COL], float [][COL], float [][COL]);

};
MATRIX::MATRIX()
{
    cout<<"\t\tWelcome to MATRIX program\n"<<endl;
    cout<<"Available Operations(Format: Index. Operation)";
    cout<<"\n1. Determinant\n2. Adjugate\n3. Inverse\n4. Addition\n5. Subtraction\n6. Multiplication\n0. Exit"<<endl;
}
void MATRIX::format()
{
    cout<<"Matrix elements entry format: "<<endl;
    cout<<"\t1st    2nd\n\t3rd    4th"<<endl;
}
void MATRIX::getMatrix(float matrix[][COL])
{
    cout<<"Input elements of the matrix"<<endl;
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            cin>>matrix[i][j];
        }
    }
}
void MATRIX::printMatrix(float matrix[][COL])
{
    cout<<"\n\t"<<matrix[0][0]<<"    "<<matrix[0][1]
        <<"\n\t"<<matrix[1][0]<<"    "<<matrix[1][1]<<endl;
}
float MATRIX::determinant(float matrix[][COL])
{
    float det;
    det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    return det;
}
void MATRIX::adjugate(float matrix[][COL], float adj[][COL])
{
    adj[0][0] = matrix[1][1];
    adj[0][1] = - matrix[0][1];
    adj[1][0] = - matrix[1][0];
    adj[1][1] = matrix[0][0];
}
void MATRIX::inverse(int det, float adj[][COL], float _inverse[][COL])
{
    _inverse[0][0] = adj[0][0]/det;
    _inverse[0][1] = adj[0][1]/det;
    _inverse[1][0] = adj[1][0]/det;
    _inverse[1][1] = adj[1][1]/det;
}
void MATRIX::addition(float matrix1[][COL], float matrix2[][COL], float add[][COL])
{
    add[0][0] = matrix1[0][0] + matrix2[0][0];
    add[0][1] = matrix1[0][1] + matrix2[0][1];
    add[1][0] = matrix1[1][0] + matrix2[1][0];
    add[1][1] = matrix1[1][1] + matrix2[1][1];
}
void MATRIX::subtraction(float matrix1[][COL], float matrix2[][COL], float sub[][COL])
{
    sub[0][0] = matrix1[0][0] - matrix2[0][0];
    sub[0][1] = matrix1[0][1] - matrix2[0][1];
    sub[1][0] = matrix1[1][0] - matrix2[1][0];
    sub[1][1] = matrix1[1][1] - matrix2[1][1];
}
void MATRIX::multiplication(float matrix1[][COL], float matrix2[][COL], float mul[][COL])
{
    mul[0][0] = (matrix1[0][0] * matrix2[0][0]) + (matrix1[0][1] * matrix2[1][0]);
    mul[0][1] = (matrix1[0][0] * matrix2[0][1]) + (matrix1[0][1] * matrix2[1][1]);
    mul[1][0] = (matrix1[1][0] * matrix2[0][0]) + (matrix1[1][1] * matrix2[1][0]);
    mul[1][1] = (matrix1[1][0] * matrix2[0][1]) + (matrix1[1][1] * matrix2[1][1]);
}

int main()
{
    MATRIX mtr;
    int choice, retry;
    string op1 = "Operation: ";
    string op2 = "Operation Index: ";
    float matrix1[ROW][COL], matrix2[ROW][COL],
            adj[ROW][COL], _inverse[ROW][COL],
            add[ROW][COL], sub[ROW][COL],
            mul[ROW][COL];
    float det;

    retry = 0;
    do
    {
        retry++;
        if (retry == 1)
            cout<<op1;
        else
            cout<<"\n"<<op2;
        cin>>choice;
        switch(choice)
        {
            case 1:
                mtr.format();
                mtr.getMatrix(matrix1);
                det = mtr.determinant(matrix1);
                cout<<"Determinant of the matrix: "<<det<<endl;
                break;
            case 2:
                mtr.format();
                mtr.getMatrix(matrix1);
                cout<<"Adjugate of the matrix: \n";
                mtr.adjugate(matrix1, adj);
                mtr.printMatrix(adj);
                break;
            case 3:
                mtr.format();
                mtr.getMatrix(matrix1);
                det = mtr.determinant(matrix1);
                if (det != 0)
                {
                    mtr.adjugate(matrix1, adj);
                    mtr.inverse(det, adj, _inverse);
                    cout<<"Inverse of the matrix: \n";
                    mtr.printMatrix(_inverse);
                }
                else
                    cout<<"For the inverse of a matrix to exist, the determinant must be different of 0.\n";
                break;
            case 4:
                mtr.format();
                mtr.getMatrix(matrix1);
                mtr.getMatrix(matrix2);
                cout<<"Matrix 1: ";
                mtr.printMatrix(matrix1);
                cout<<"\nMatrix 2: ";
                mtr.printMatrix(matrix2);
                cout<<"\nAdding matrices: ";
                mtr.addition(matrix1, matrix2, add);
                mtr.printMatrix(add);
                break;
            case 5:
                mtr.format();
                mtr.getMatrix(matrix1);
                mtr.getMatrix(matrix2);
                cout<<"Matrix 1: ";
                mtr.printMatrix(matrix1);
                cout<<"\nMatrix 2: ";
                mtr.printMatrix(matrix2);
                cout<<"\nSubtracting matrices: ";
                mtr.subtraction(matrix1, matrix2, sub);
                mtr.printMatrix(sub);
                break;
            case 6:
                mtr.format();
                mtr.getMatrix(matrix1);
                mtr.getMatrix(matrix2);
                cout<<"Matrix 1: ";
                mtr.printMatrix(matrix1);
                cout<<"\nMatrix 2: ";
                mtr.printMatrix(matrix2);
                cout<<"\nMultiplying matrices: ";
                mtr.multiplication(matrix1, matrix2, mul);
                mtr.printMatrix(mul);
                break;
            case 0:
                cout<<"\nThanks for using MATRIX program :) \n";
                return 0;
            default:
                cout<<"\nInvalid Input: \n\t Please input a number from 1 to 6!\n";
        }
    }while(choice!= 0);

    return 0;
}
