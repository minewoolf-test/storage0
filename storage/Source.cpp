#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "files.h"
#include "vectors.h"


int main() {
	//Константы
	setlocale(LC_ALL, "ru");
	vector <string>	items = split(read("data.txt"),"\n");
	vector <string>	names = {};
	vector <int>volumes = {};
	vector <int>weights = {};
	vector <float>proportions = {};
	vector <string>	storage = {};
	int cur_volume = 0;
	int cur_weight = 0;

	//Инициализация и чтение
	for (int i = 0; i < items.size(); i++) {
		vector <string>	item = split(items[i], ",");
		names.push_back(item[0]);
		volumes.push_back(stoi(item[1]));
		weights.push_back(stoi(item[2]));
		proportions.push_back(stof(item[2])/ stof(item[1]));
	};
	vector <float>	proportions_copy(proportions);

	//Инициализация объема
	cout << "Введите объем ";
	cin >> cur_volume;

	//Подбор
	while (proportions_copy.size() > 0) {
		//Выбор наиболее выгодного предмета
		float maximum = *max_element(proportions_copy.begin(), proportions_copy.end());
		vector <float>proportions_copy_new = {};
		for (int i = 0; i < proportions_copy.size(); i++) {
			if (proportions_copy[i] != maximum) {
				proportions_copy_new.push_back(proportions_copy[i]);
			};
		};
		//Добавление в рюкзак
		for (int i = 0; i < proportions.size(); i++) {
			if (proportions[i] == maximum && cur_volume>=volumes[i] && proportions[i]>0) {
				storage.push_back(names[i]);
				cur_weight += weights[i];
				cur_volume -= volumes[i];
			};
		};
		//Сохранение изменений вектора
		proportions_copy = proportions_copy_new;
	};

	//Вывод
	cout << "Объекты: " << endl;
	for (int i = 0; i < storage.size(); i++) {
		cout << storage[i]<<endl;
	}
	cout << "Итого веса: "<< cur_weight<<" Объема осталось: "<< cur_volume<<endl;
}