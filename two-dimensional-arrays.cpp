//����������� ������ ���������
#include <iostream>
#include <exception>
#include <math.h>

using namespace std;

//����������� �������
void inArray(int array[3][3], int x, int y);
void inArrayLite(int** array, int x, int y);
//void outArray();
//void outArrayLite();

int main() {
    setlocale(LC_ALL, "ru"); //������������
    
    //���������� ������������� �������

    //������������ ��������-���������� ������
    //int w = 3, h = 4;
    //int* arr = new int[w * h];
    //for (int i = 0; i < h; i++) {
    //    for (int j = 0; j < w; j++) {
    //        arr[i * w + j] = rand() % 10; //���������� ������, ������� ������������ ��� ���������. 
    //    } //��������� ������������ ���������� ������, ���, ��� ��������� �� �����
    //}
    //delete[] arr;


    int** arr;
    arr = new int* [2];
    int i;
    for (int i = 0; i < 2; i++) {
        arr[i] = new int[3];
    }
    try {
        inArrayLite(arr, 3, 3);
    }
    catch(invalid_argument& e) {
        cerr << e.what();

        for (int j = 0; j < 3; j++) {
            cout << arr[i][j];
        }
        delete[] arr[i];

        return 0;
    }

    //���������� ����������� �������
    int array[3][3] = { 0 };
    inArray(array, 3, 3);

    //����� ������������� �������
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j];
        }
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}

void inArray(int array[3][3], int x, int y) {
    try {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cin >> array[i][j];
                if (cin.fail()) {
                    throw invalid_argument("������ �����, ���� ������� ������������� ��������");
                }
            }
        }
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
}


void inArrayLite(int** arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            
            cin >> *(*(arr + i) + j);

            if (cin.fail()) {
                throw invalid_argument("Input error");
            }
        }
    }
}