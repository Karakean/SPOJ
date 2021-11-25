#include <iostream>
#include <string>
std::string add_one(std::string num, bool* is_over) {
	int len = num.length();
	int i = len - 1;
	while ((i >= 0) && (num[i] == '9')) {
		i--;
	}
	if (i >= 0) {
		num[i]++;
		for (int j = i + 1; j < len; j++) {
			num[j] = '0';
		}
	}
	else {
		num[0] = '1';
		for (int j = 1; j < len; j++) {
			num[j] = '0';
		}
		num.push_back('1');
		std::cout << num << "\n";
		(*is_over) = true;
	}
	return num;
}


std::string duplicate(std::string num, int mid) {
	int len = num.length();
	for (int i = 0; i < mid; i++) {
		num[len - 1 - i] = num[i];
	}
	return num;
}


void find(std::string num, int len, bool is_len_even) {
	int mid = len / 2;
	int left, right;
	std::string new_num = num;
	if (is_len_even) {
		left = mid - 1;
		right = mid;
	}
	else {
		left = mid;
		right = mid + 1;
	}
	for (int i = 0; i < mid; i++) {
		if (num[mid - 1 - i] > num[right + i]) {
			new_num = duplicate(num, mid);
			break;
		}
		else if (num[mid - 1 - i] < num[right + i]) {
			if (num[left] != '9') {
				num[left]++;
			}
			else {
				for (int j = 0; j <= mid; j++) {
					if (num[left - j] == '9') {
						num[left - j] = '0';
					}
					else {
						num[left - j]++;
						break;
					}
				}
			}
			new_num = duplicate(num, mid);
			break;
		}
	}
	std::cout << new_num << "\n";
}


int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		std::string number;
		std::cin >> number;
		bool is_over = false;
		number = add_one(number, &is_over);
		if (!is_over) {
			int length = number.length();
			bool is_len_even;
			if (length == 1) {
				std::cout << number << "\n";
				continue;
			}
			else if (length % 2 == 0) {
				is_len_even = true;
			}
			else {
				is_len_even = false;
			}
			find(number, length, is_len_even);
		}
	}
}
