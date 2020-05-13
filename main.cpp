#include <stdio.h>
#include <iostream>
#include <libutils/io.h>
#include <cstdlib>
#include "Clock.h"

//template<class T>
//void Random_Filling(std::vector<T>& v, int size) {
//	for (int i = 0; i < size; ++i) {
//		v.push_back(i);
//	}
//	for (int i = 0; i < v.size(); ++i) {
//		std::swap(v[i], v[rand() % (v.size() - i) + i]);
//	}
//}
//
//void Random_Filling(int *arr, int size) {
//	for (int i = 0; i < size; ++i) {
//		arr[i] = i;
//    }
//	for (int i = 0; i < size; ++i) {
//		std::swap(arr[i], arr[rand() % (size - i) + i]);
//	}
//}
//
//void Print(int *arr,int size) {
//	for (int i = 0; i < size; ++i) {
//		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
//    }	
//}
//
//template<class T>
//void Print(std::vector<T> &v) {
//	for (int i = 0; i < v.size(); ++i) {
//		std::cout << "v[" << i << "] = " << v[i] << std::endl;
//	}
//}

int main() {
	int back = 1;	
	OrderedVector<int> oV;	
	do 
	{		
		int User_Choise = utils::read_int(" 1 - Ordered Vector\n 2 - AVLTree\n 3 - Unordered Set\n", 1, 3);		
		int step = utils::read_int("Enter step: ", 1, 5000);
		if (User_Choise == 1) {			
			Clock(oV, step);//accuracy = 10, number of sizes = 10
		}
		else {
			if(User_Choise == 2) {
				Set<int> Set;
				Clock(Set, step);
			}
			else {
				UnorderedSet<int> uSet;
				Clock(uSet, step);
			}
		}		
		back = utils::read_int(" 1 - back\n 0 - end\n", 0, 50);
	} while (back == 1);
		
	system("pause");
	return 0;
}




//
//OrderedVector<int> ov;
//do {
//	int size = utils::read_int("Enter size of collection: ", 0, 50);
//	switch (User_Choise = utils::read_int(" 1 - Ordered Vector\n 2 - AVLTree\n 3 - Unordered Set\n", 1, 3)) {
//	case 1:
//      OrderedVector<int> ov;                    dont work
//		Clock(ov, size);
//		break;
//	case 2: