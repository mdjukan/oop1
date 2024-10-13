#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int DECEMBER = 12;

class Date {
	static bool isLeapYear(int year) {
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
       	}
		
	static int daysInMonth(int mo, int year) {
		int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (mo == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				return 29;
			}
		}

		return daysInMonth[mo];;
	}

	public:
		int day, mo, year;
		Date(int day = 1, int mo = 1, int year = 1) : day(day), mo(mo), year(year) {}
		void inc() {
			if (day==daysInMonth(mo, year)) {
				if (mo==DECEMBER) {
					day = 1;
					mo = 1;
					year += 1;
				} else {
					day = 1;
					mo += 1;
				}
			} else {
				day += 1;
			}
		}

		void moveBy(int n) {
			for (int i=0; i<n; i++) {
				inc();
			}
		}

		int daysSinceFirst() const {
			int days = 0;
			for (int i=1; i<year; i++) {
				if (isLeapYear(i)) {
					days += 366;
				} else {
					days += 365;
				}
			}

			for (int i=1; i<mo; i++) {
				days += daysInMonth(mo, year);
			}

			days += day;

			return days;
		}

};

int operator-(const Date &d1, const Date &d2) {
	return d1.daysSinceFirst() - d2.daysSinceFirst();
}

bool operator<(const Date &d1, const Date &d2) {
	return d1.daysSinceFirst()<d2.daysSinceFirst();
}

ostream& operator<<(ostream &out, const Date &d) {
	cout << d.day << "." << d.mo << "." << d.year;
	return out;
}

istream& operator>>(istream &in, Date &d) {
	in >> d.day >> d.mo >> d.year;
	return in;
}

int main() {
	int n;
	cin >> n;
	vector<Date> dates(n);
	for (int i=0; i<n; i++) {
		cin >> dates[i];
	}

	sort(dates.begin(), dates.end());

	for (int i=0; i<n; i++) {
		cout << dates[i] << endl;
	}
}
