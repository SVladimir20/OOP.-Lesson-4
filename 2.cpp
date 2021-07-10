#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void compare(vector<int> &a);
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int> array{};
	array.resize(10);
	generate(array.begin(), array.end(), rand);
	compare(array);
	return 0;
}
void compare(vector<int> &a)
{
	sort(a.begin(), a.end());
	set<int> s(a.begin(), a.end());
	cout << "Различных чисел в массиве: " << s.size() << endl << "Неповторяющиеся числа: ";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
}