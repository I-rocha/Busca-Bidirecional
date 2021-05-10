#include "storage.h"

Storage::Storage() {
	std::vector<std::vector<Estado*>> aux(3, std::vector<Estado*>());
	hash = aux;
}

int Storage::push(Estado* aux) {
	hash[aux->miss_esq - 1].push_back(aux);
	return 1;
}

int Storage::exist(Estado x) {
	int i = 0;

	while (i < this->hash[x.miss_esq].size()) {
		if (x == *hash[x.miss_esq][i]) return 1;
		i++;
	}
	return 0;
}

void Storage::show() {
	for (std::vector<Estado*> x : this->hash) {
		for (Estado* y : x) {
			if(y != nullptr)
			y->show();
		}
	}
}