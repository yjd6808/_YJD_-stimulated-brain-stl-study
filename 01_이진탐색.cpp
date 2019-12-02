#include "pch.h"
#include "common.h"



class BinarySearch {
	template<typename T>
	static T Find(T* sourceArray, int arrayLength, int startIndex, int endIndex, const T data, function<bool(const T&, const T&)> comparator) {
		int centerIndex = (startIndex + endIndex) / 2;

		if (sourceArray[centerIndex] == data)
			return sourceArray[centerIndex];

		if (centerIndex >= endIndex || centerIndex < 0) {
			cout << "데이터를 찾지 못했습니다" << endl;
			return -5;
		}

		if (comparator(data, sourceArray[centerIndex]))
			return Find<T>(sourceArray, arrayLength, centerIndex + 1, endIndex, data, comparator);
		else
			return Find<T>(sourceArray, arrayLength, 0, centerIndex, data, comparator);
	}

public:
	template<typename T>
	static T Find(T* sourceArray, int arrayLength, const T data) {
		function<bool(const T&, const T&)> comparator = [](const int& lhs, const int& rhs) {
			return lhs > rhs;
		};
		return Find<T>(sourceArray, arrayLength, 0, arrayLength-1, data, comparator);
	}
};




TEST(이진탐색) {
	for (int i = 0; i < 30; i++) {
		int randIndex = RandomGenerator::GetInteger(1, 30);
		int* testArr = new int[randIndex];
		for (int i = 0; i < randIndex; i++)
			testArr[i] = i;

		for (int i = 0; i < randIndex; i++)
			cout << testArr[i] << " ";
		cout << "--------------" << endl;

		int searchIndex = RandomGenerator::GetInteger(0, randIndex - 1);
		cout << "검색 인덱스 : " << searchIndex << endl;
		int data = BinarySearch::Find<int>(testArr, randIndex, testArr[searchIndex]);
	}

	
	/* 속도 테스트
	int* testArr2 = new int[100000000];

	for (int i = 0; i < 100000000; i++) {
		testArr2[i] = i;
	}

	cout << "1억 만큼 숫자입력완료" << endl;

	int findValue = RandomGenerator::GetInteger(0, 100000000 - 1);
	int data =  BinarySearch::Find<int>(testArr2, 100000000, findValue);
	cout << data << endl;*/
}