#include <iostream>
#include <algorithm>
#include <vector>

struct Athlete {
	int mas_;
	int str_;
	Athlete(int mas, int str):mas_(mas), str_(str){}
	bool operator<(const Athlete &b) const {
		return (mas_ + str_) < (b.mas_+b.str_);
	}
};

int greed_is_good(std::vector<Athlete> *athletes);

int main() {
	int m = 0;
	int s = 0;
	std::vector<Athlete> *athletes = new std::vector<Athlete>;

	while (std::cin >> m >> s ) {
		athletes->push_back(Athlete(m, s));
	}

    std::cout << greed_is_good(athletes);

	delete athletes;
	return 0;
}

int greed_is_good(std::vector<Athlete> *athletes) {
    std::sort(athletes->begin(), athletes->end());
	int all_weight = 0;
	int counter = 0;
	for (unsigned i = 0; i < athletes->size(); ++i) {
		if ( athletes->at(i).str_ >= all_weight ) {
			counter++;
			all_weight += athletes->at(i).mas_;
		}
	}
	return counter;
}