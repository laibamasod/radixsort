#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
void convert(vector<string>& my_array, int maximum, int my_size) {
	for (int i = 0; i < my_size; i++) {
		if (my_array[i].length() < maximum) {
			for (int j = my_array[i].length(); j <= maximum - 1; j++) {
				my_array[i] = my_array[i] + ".";
			}
		}
	}

}

void deconvert(vector<string>& my_array, int maximum, int my_size) {
	for (int i = 0; i < my_size; i++) {
		for (int j = my_array[i].length(); j >= 0; j--) {
			if (my_array[i][j] == '.') {
				my_array[i].pop_back();
			}
		}
	}

}
int get_ind(string a,int cc) {
		char temp = a[cc];
		if (temp == '.') {
			return 0;
		}
		else if (temp == 'a') {
			return 1;
		}
		else if (temp == 'b') {
			return 2;
		}
		else if (temp == 'c') {
			return 3;
		}
		else if (temp == 'd') {
			return 4;
		}
		else if (temp == 'e') {
			return 5;
		}
		else if (temp == 'f') {
			return 6;
		}
		else if (temp == 'g') {
			return 7;
		}
		else if (temp == 'h') {
			return 8;
		}
		else if (temp == 'i') {
			return 9;
		}
		else if (temp == 'j') {
			return 10;
		}
		else if (temp == 'k') {
			return 11;
		}
		else if (temp == 'l') {
			return 12;
		}
		else if (temp == 'm') {
			return 13;
		}
		else if (temp == 'n') {
			return 14;
		}
		else if (temp == 'o') {
			return 15;
		}
		else if (temp == 'p') {
			return 16;
		}
		else if (temp == 'q') {
			return 17;
		}
		else if (temp == 'r') {
			return 18;
		}
		else if (temp == 's') {
			return 19;
		}
		else if (temp == 't') {
			return 20;
		}
		else if (temp == 'u') {
			return 21;
		}
		else if (temp == 'v') {
			return 22;
		}
		else if (temp == 'w') {
			return 23;
		}
		else if (temp == 'x') {
			return 24;
		}
		else if (temp == 'y') {
			return 25;
		}
		else if (temp == 'z') {
			return 26;
		}
}
vector<string> radixsort(vector<string> a, int n,int max) { //max is maxlen
	queue<string> bins[27];
	int curr_char = max-1;  //max-1
	vector<string> arr(n);
	convert(a, max, n);

	while (curr_char >=0) { //>=0
		for (int i = 0; i < n; i++) {
			int ind = get_ind(a[i], curr_char);
			bins[ind].push(a[i]);
		}
		int i = 0;
		for (int k = 0; k < 26; k++) { 
			while (!bins[k].empty()) { 
				arr[i] = bins[k].front();
				bins[k].pop();
				i++;
			}
		}
		curr_char--;
	}
	 deconvert(arr, max, n);
	return arr;
}
int max_len(vector<string> a, int n) {
	int m = a[0].size();
	for (int i = 1; i < n; i++) {
		if (m < a[i].size()) {
			m = a[i].size();
		}
	}
	return m;
}


int main() {
	int strng_num;
	cout << "How many strings do you want to enter?\n";
	cin >> strng_num;
	vector<string> a(strng_num),sorted_a(strng_num);
	for (int i = 0; i < strng_num; i++) {
		cout << "Enter String " << i + 1 << ": ";
		cin >> a[i];
	}
	for (int i = 0; i < strng_num; i++) {
		cout << "String " << i + 1 << ": ";
		cout<< a[i]<<endl;
	}
	int m=max_len(a, strng_num); //finding string of max len
	cout << "After using radix sort:\n";
	sorted_a = radixsort(a, strng_num, m);
	for (int i = 0; i < strng_num; i++) {
		cout << "String " << i + 1 << ": ";
		cout << sorted_a[i] << endl;
	}
}