#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;


class Auto {
public:
	string name;
	int year;
	int volume;
	int cost;
	static int NumAuto;

	Auto(string _name, int _year, int _volume, int _cost) {
		name = _name;
		year = _year;
		volume = _volume;
		cost = _cost;
	}


};

int Auto::NumAuto = 0;

ostream& operator << (ostream& out, Auto& car) {
	out << "Name: " << car.name
		<< "\nYear: " << car.year
		<< "\nVolume: " << car.volume
		<< "\nCost: " << car.cost << endl << endl;
	return out;
}

void Add(vector<Auto>& cars) {
	string name;
	int year;
	int volume;
	int cost;
	cout << "Name: ";
	cin >> name;
	cout << "Year: ";
	cin >> year;
	cout << "Volume: ";
	cin >> volume;
	cout << "Cost: ";
	cin >> cost;
	Auto* car = new Auto{ name, year, volume, cost };
	Auto::NumAuto++;
	cars.push_back(*car);
	system("cls");
}

void Show(vector<Auto>& cars) {
	auto bg = cars.begin();
	auto end = cars.end();
	int i = 1;
	while (bg != end) {
		cout << "AutoNum #" << i << endl;
		cout << *bg;
		bg++;
		i++;
	}
}

void Delete(vector<Auto>& cars) {
	int write;
	Show(cars);
	cout << "Enter NumAuto: ";
	cin >> write;
	if (1 <= write && write <= Auto::NumAuto) {
		vector<Auto> tmp{};
		int i = 1;
		for (auto bg = cars.begin(), end = cars.end(); i <= Auto::NumAuto; bg++, i++) {
			if (i == write) {
				continue;
			}
			tmp.push_back(*bg);
		}
		cars = tmp;
	}
	system("cls");
}

void SortbyName(vector<Auto>& cars) {
	vector<Auto> tmpAuto;
	vector<string> tmp;
	int i = 0;
	Auto* tmpA;
	for (auto bg = cars.begin(), end = cars.end(); bg != end; bg++) {
		tmpA = &*bg;
		tmp.push_back(tmpA->name);
	}
	std::sort(tmp.begin(), tmp.end());
	for (auto bgstr = tmp.begin(), endstr = tmp.end(); bgstr != endstr;) {
		for (auto bg = cars.begin(), end = cars.end(); bg != end && bgstr != endstr; bg++) {
			tmpA = &*bg;
			if (tmpA->name == *bgstr) {
				tmpAuto.push_back(*bg);
				bgstr++;
			}
		}
	}
	cars = tmpAuto;
	cout << "Sort complete...";
	Sleep(1000);
	system("cls");
}

void SortbyYear(vector<Auto>& cars) {
	vector<Auto> tmpAuto;
	vector<int> tmp;
	int i = 0;
	Auto* tmpA;
	for (auto bg = cars.begin(), end = cars.end(); bg != end; bg++) {
		tmpA = &*bg;
		tmp.push_back(tmpA->year);
	}
	std::sort(tmp.begin(), tmp.end());
	for (auto bgstr = tmp.begin(), endstr = tmp.end(); bgstr != endstr;) {
		for (auto bg = cars.begin(), end = cars.end(); bg != end && bgstr != endstr; bg++) {
			tmpA = &*bg;
			if (tmpA->year == *bgstr) {
				tmpAuto.push_back(*bg);
				bgstr++;
			}
		}
	}
	cars = tmpAuto;
	cout << "Sort complete...";
	Sleep(1000);
	system("cls");
}

void SortbyVolume(vector<Auto>& cars) {
	vector<Auto> tmpAuto;
	vector<int> tmp;
	int i = 0;
	Auto* tmpA;
	for (auto bg = cars.begin(), end = cars.end(); bg != end; bg++) {
		tmpA = &*bg;
		tmp.push_back(tmpA->volume);
	}
	std::sort(tmp.begin(), tmp.end());
	for (auto bgstr = tmp.begin(), endstr = tmp.end(); bgstr != endstr;) {
		for (auto bg = cars.begin(), end = cars.end(); bg != end && bgstr != endstr; bg++) {
			tmpA = &*bg;
			if (tmpA->volume == *bgstr) {
				tmpAuto.push_back(*bg);
				bgstr++;
			}
		}
	}
	cars = tmpAuto;
	cout << "Sort complete...";
	Sleep(1000);
	system("cls");
}

void SortbyCost(vector<Auto>& cars) {
	vector<Auto> tmpAuto;
	vector<int> tmp;
	int i = 0;
	Auto* tmpA;
	for (auto bg = cars.begin(), end = cars.end(); bg != end; bg++) {
		tmpA = &*bg;
		tmp.push_back(tmpA->cost);
	}
	std::sort(tmp.begin(), tmp.end());
	for (auto bgstr = tmp.begin(), endstr = tmp.end(); bgstr != endstr;) {
		for (auto bg = cars.begin(), end = cars.end(); bg != end && bgstr != endstr; bg++) {
			tmpA = &*bg;
			if (tmpA->cost == *bgstr) {
				tmpAuto.push_back(*bg);
				bgstr++;
			}
		}
	}
	cars = tmpAuto;
	cout << "Sort complete...";
	Sleep(1000);
	system("cls");
}

void SearchbyName(vector<Auto>& cars) {
	string write;
	cout << "Enter Name: ";
	cin >> write;
	int i = 1;
	for (Auto Elem : cars) {
		if (Elem.name == write) {
			cout << "AutoNum #" << i << endl;
			cout << Elem;
		}
		i++;
	}
}

void SearchbyYear(vector<Auto>& cars) {
	int write;
	cout << "Enter Year: ";
	cin >> write;
	int i = 1;
	for (Auto Elem : cars) {
		if (Elem.year == write) {
			cout << "AutoNum #" << i << endl;
			cout << Elem;
		}
		i++;
	}
}

void SearchbyVolume(vector<Auto>& cars) {
	int write;
	cout << "Enter Year: ";
	cin >> write;
	int i = 1;
	for (Auto Elem : cars) {
		if (Elem.volume == write) {
			cout << "AutoNum #" << i << endl;
			cout << Elem;
		}
		i++;
	}
}

void SearchbyCost(vector<Auto>& cars) {
	int write;
	cout << "Enter Year: ";
	cin >> write;
	int i = 1;
	for (Auto Elem : cars) {
		if (Elem.cost == write) {
			cout << "AutoNum #" << i << endl;
			cout << Elem;
		}
		i++;
	}
}

void main() {
	system("color 05");

	int write;

	cout << "Welcome to Auto Show";
	Sleep(300); cout << '.'; Sleep(300); cout << '.'; Sleep(300); cout << '.';
	system("cls");
	vector<Auto> Cars;
	while (true) {
		cout << "Enter function:"
			<< "\n1.Add car"
			<< "\n2.Delete car"
			<< "\n3.Show cars"
			<< "\n4.Sort by name"
			<< "\n5.Sort by year"
			<< "\n6.Sort by volume"
			<< "\n7.Sort by cost"
			<< "\n8.Search by name"
			<< "\n9.Search by year"
			<< "\n10.Search by volume"
			<< "\n11.Search by cost"
			<< "\n12.Total cars"
			<< "\nEnter something to exit << ";
		cin >> write;
		system("cls");
		switch (write) {
		case 1:
			Add(Cars);
			break;
		case 2:
			Delete(Cars);
			break;
		case 3:
			Show(Cars);
			break;
		case 4:
			SortbyName(Cars);
			break;
		case 5:
			SortbyYear(Cars);
			break;
		case 6:
			SortbyVolume(Cars);
			break;
		case 7:
			SortbyCost(Cars);
			break;
		case 8:
			SearchbyName(Cars);
			break;
		case 9:
			SearchbyYear(Cars);
			break;
		case 10:
			SearchbyVolume(Cars);
			break;
		case 11:
			SearchbyCost(Cars);
			break;
		case 12:
			cout << "\n Total cars: " << Auto::NumAuto << endl << endl;
			break;
		default:
			cout << "Thanks for using";
			Sleep(500);
			return;
		}
	}
}