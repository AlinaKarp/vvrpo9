#include <iostream>
#include "utils.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #5. �������� ������ � ��������\n";
    cout << "Author: ����� ���������� \n";
    std::string filename = "data.txt";
    filterAndSortData(filename);
    return 0;
}