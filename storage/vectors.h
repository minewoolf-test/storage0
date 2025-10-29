#pragma once

vector <string> split(string value, string separator) {
	int i = 0;
	int i0 = 0;

	value = separator + value;
	vector <string> result = {};

	while (i + 1 + separator.size() < value.size()) {
		i0 = i;
		i = value.find(separator, i0 + 1);
		result.push_back(value.substr(i0 + 1, i - i0 - 1));
	}
	return result;
};
//Исключение элементов одного вектора из другого
vector <string> avoidMatches(vector <string> a, vector <string> b) {
	vector <string> matches;

	for (int i = 0; i < a.size(); i++) {
		bool isValInVec = false;

		for (int ii = 0; ii < b.size(); ii++) {
			if (a[i] == b[ii]) {
				isValInVec = true;
			};
		};
		if (isValInVec != true) {
			matches.push_back(a[i]);
		};
	};
	return matches;
};
//Исключение повторов в векторе
vector <string> avoidSimilar(vector <string> a) {
	vector <string> matches;
	for (int i = 0; i < a.size(); i++) {
		bool isValInVec = false;
		for (int j = 0; j < matches.size(); j++) {
			if (a[i] == matches[j]) {
				isValInVec = true;
			};
		};
		if (isValInVec == false) {
			matches.push_back(a[i]);
		};
	};
	return matches;
};