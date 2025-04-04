#include <iostream>
#include <vector>




class pair {
private:
	int x;
	int count;
public:
	pair(){};
	pair(int x, int y = 0) : x(x), count(y) {};

	

	int get_x() {
		return x;
	}
	int get_count() {
		return count;
	}
	void set_count() {
		count++;
	}
};




void count_check(pair* arr, int size) {				//������� ��� �������� ������� ��� ���������������� �������
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = i + 1; j < size; ++j) {

			if (arr[i].get_x() > arr[j].get_x())					// ������������ ������� �������
				arr[i].set_count();
			else
				arr[j].set_count();
		}
	}
} 


void sort_by_count(pair* arr, int size) { 
	//count_check(arr, size); // ������� �������� ������ ������� ������
	bool flag = true;
	pair tmp = arr[0];
	int index = 0, tmp_i = tmp.get_count(); //��� �������� while ����� ������� ��������

	while (flag) {
		while (flag && index == tmp_i) { //���������� ������ ������ � �������� ��������, ���� �� ����� �� ����� �������, �� ������ � while
			if (index == size - 1) //���� ����� �� ����� � while,  ������ ������������, ���������� ����
				flag = false;
			else { //����� ��������� � ���� �������� � ����� ��������� ���
				++index;
				tmp = arr[index];
				tmp_i = tmp.get_count();
			}
		}
			tmp_i = tmp.get_count(); // ����������� ����������
			std::swap(arr[tmp_i], tmp); // ���������� �������� ������ tmp � ������ ������� 

	}
}
void print(pair* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i].get_x() << ' ' << arr[i].get_count() << '\n';
	}
}
int main() {
	
	int size = 7;
	pair* arr = new pair[size]{pair(7), pair(400), pair(3), pair(25), pair(1), pair(-15), pair(35)};
	count_check(arr, size);
	print(arr, size); std::cout << '\n';
	sort_by_count(arr, size);
	print(arr, size);
}
