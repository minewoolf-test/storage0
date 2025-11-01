#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "files.h"
#include "vectors.h"

class item {
public:
	string name = "item";
	int volume = 1;
	int weight = 1;
	void setRandom(int minVolume, int maxVolume, int minWeight, int maxWeight) {
		volume = minVolume + rand() % (maxVolume - minVolume+1);
		if (volume == 0) { 
			volume = 1; 
		};
		weight = minWeight + rand() % (maxWeight - minWeight+1);
	};
};
void setItems(vector <item> itemList) {
	string data = "";
	for (int i = 0; i < itemList.size(); i++) {
		data += itemList[i].name+ ","+to_string(itemList[i].volume) + "," + to_string(itemList[i].weight) + ",\n";
	};
	write("data.txt", data);
};
int main() {
	//���������
	setlocale(LC_ALL, "ru");
	/*vector <item> itemList = {};
	for (int i = 0; i < 10; i++) {
		item a;
		a.setRandom(1, 1, -10, 10);
		itemList.push_back(a);
	};
	setItems(itemList);*/
	vector <string>	items = split(read("data.txt"),"\n");
	vector <string>	names = {};
	vector <int>volumes = {};
	vector <int>weights = {};
	vector <float>proportions = {};
	int start_volume = 0;
	vector <string>	storage = {};
	int cur_weight = 0;

	//������������� � ������
	for (int i = 0; i < items.size(); i++) {
		vector <string>	item = split(items[i], ",");
		names.push_back(item[0]);
		volumes.push_back(stoi(item[1]));
		weights.push_back(stoi(item[2]));
		proportions.push_back(stof(item[2])/ stof(item[1]));
	};
	vector <float>	proportions_copy(proportions);

	//������������� ������
	cout << "������� ����� ";
	cin >> start_volume;
	int cur_volume = start_volume;

	//������
	while (proportions_copy.size() > 0) {
		//����� �������� ��������� ��������
		float maximum = *max_element(proportions_copy.begin(), proportions_copy.end());
		vector <float>proportions_copy_new = {};
		for (int i = 0; i < proportions_copy.size(); i++) {
			if (proportions_copy[i] != maximum) {
				proportions_copy_new.push_back(proportions_copy[i]);
			};
		};
		//���������� � ������
		for (int i = 0; i < proportions.size(); i++) {
			if (proportions[i] == maximum && cur_volume>=volumes[i] && proportions[i]>0) {
				storage.push_back(names[i]);
				cur_weight += weights[i];
				cur_volume -= volumes[i];
			};
		};
		//���������� ��������� �������
		proportions_copy = proportions_copy_new;
	};
	//��������� ������
	int remains = cur_volume;
	cur_volume = start_volume;
	names = {};
	volumes = {};
	weights = {};
	proportions = {};
	storage = {};
	cur_weight = 0;
	for (int i = 0; i < items.size(); i++) {
		vector <string>	item = split(items[i], ",");
		names.push_back(item[0]);
		volumes.push_back(stoi(item[1]));
		weights.push_back(stoi(item[2]));
		proportions.push_back(stof(item[2]) / stof(item[1])+ stof(item[1])*remains/ start_volume);
	};
	proportions_copy=proportions;

	//������
	while (proportions_copy.size() > 0) {
		//����� �������� ��������� ��������
		float maximum = *max_element(proportions_copy.begin(), proportions_copy.end());
		vector <float>proportions_copy_new = {};
		for (int i = 0; i < proportions_copy.size(); i++) {
			if (proportions_copy[i] != maximum) {
				proportions_copy_new.push_back(proportions_copy[i]);
			};
		};
		//���������� � ������
		for (int i = 0; i < proportions.size(); i++) {
			if (proportions[i] == maximum && cur_volume >= volumes[i] && proportions[i] > 0) {
				storage.push_back(names[i]);
				cur_weight += weights[i];
				cur_volume -= volumes[i];
			};
		};
		//���������� ��������� �������
		proportions_copy = proportions_copy_new;
	};
	//�����
	cout << "�������: " << endl;
	for (int i = 0; i < storage.size(); i++) {
		cout << storage[i]<<endl;
	}
	cout << "����� ����: "<< cur_weight<<" ������ ��������: "<< cur_volume<<endl;
}