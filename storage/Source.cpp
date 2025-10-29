#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "files.h"
#include "vectors.h"


int main() {
	setlocale(LC_ALL, "ru");
	vector <string>	items = split(read("data.txt"),"\n");
	vector <string>	names = {};
	vector <int>volumes = {};
	vector <int>weights = {};
	vector <float>proportions = {};
	for (int i = 0; i < items.size(); i++) {
		vector <string>	item = split(items[i], ",");
		names.push_back(item[0]);
		volumes.push_back(stoi(item[1]));
		weights.push_back(stoi(item[2]));
		proportions.push_back(stof(item[2])/ stof(item[1]));
	};
	vector <float>	proportions_copy(proportions);
	vector <string>	storage = {};
	int cur_volume = 0;
	int cur_weight = 0;
	cout << "Âגוהטעו מבתול ";
	cin >> cur_volume;
	while (proportions_copy.size() > 0) {
		float maximum = *max_element(proportions_copy.begin(), proportions_copy.end());
		//remove(proportions_copy.begin(), proportions_copy.end(), max_index);S
		vector <float>proportions_copy_new = {};
		for (int i = 0; i < proportions_copy.size(); i++) {
			if (proportions_copy[i] != maximum) {
				proportions_copy_new.push_back(proportions_copy[i]);
			};
		};
		for (int i = 0; i < proportions.size(); i++) {
			if (proportions[i] == maximum && cur_volume>=volumes[i] && proportions[i]>0) {
				storage.push_back(names[i]);
				cur_weight += weights[i];
				cur_volume -= volumes[i];
			};
		};
		proportions_copy = proportions_copy_new;
	};
	cout << "Îבתוךעû: " << endl;
	for (int i = 0; i < storage.size(); i++) {
		cout << storage[i]<<endl;
	}
	cout << "Èעמדמ גוסא: "<< cur_weight<<" Îבתולא מסעאכמסü: "<< cur_volume<<endl;
}