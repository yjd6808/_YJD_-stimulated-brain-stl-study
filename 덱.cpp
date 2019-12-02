#include "pch.h"
#include "common.h"

template<typename T>
struct Node {
	T data;
	Node* pnext;
	Node* pbefore;
};

template<typename T, typename K>
bool isKeyExist(unordered_map<T, K>& map, T key) {
	if (map.find(key) == map.end())
		return false;

	return true;
}


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	unordered_map<int, int> dateWithSupply;

	for (int i = 0; i < dates.size(); i++)
		dateWithSupply.insert(pair<int, int>(dates[i], supplies[i]));

	for (int i = 0; i < k; i++, stock--) {
		cout << i << "일차 작업시작" << endl;

		if (isKeyExist(dateWithSupply, i)) {
			stock += dateWithSupply[i];
		}


	}

	return 0;
}

TEST(덱) {
	//실제 덱 사용
	solution(4, vector<int>{4, 10, 15}, vector<int>{20, 5, 10}, 30);
}