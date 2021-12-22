#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	string date;
	bool flag = false;
	string path = "note.txt";   //переменная с путем файла
	string str;                 //рабочая строковая переменная
	ifstream fin;
	fin.open(path);           //Открытие файла
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}


	cout << "Введите дату в период с 01.09.2020 до 18.11.2021. (ЧЧ.ММ.ГГГГ)" << endl;
	cin >> date;
	char buf[10000];           
	char* patch;
	
	while (!fin.eof()) {
		getline(fin, str);         //Взять строчку из файла
		strcpy(buf, str.c_str());            //копируем строку из str в массив чаров
		patch = strtok(buf, "\";");
		if (patch != NULL && date == patch) {
			cout << endl;
			flag = true;
		}
		for (int i = 0; patch != NULL; i++) {   
			if (flag == true) {

				cout << patch<< "\n";
			}
			patch = strtok(NULL, "\";");    //NULL нужен для предотвращения рекурсии
		}
		flag = false;
	}
	fin.close();
	return 0;
}



