#pragma once
//������ � ����
void write(string name, string data) {
	ofstream f(name, std::fstream::out);
	f << data;
	f.close();
};
//������ �����
string read(string name) {
	ifstream file(name);
	string data = "";
	string row = "";
	while (getline(file, row)) {
		data += row + '\n';
	}
	file.close();
	return data;
};