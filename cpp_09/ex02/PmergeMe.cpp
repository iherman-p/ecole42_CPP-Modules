#include "PmergeMe.hpp"

#include <algorithm>
#include <vector>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void) other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe()
{}

void BinaryInsert(std::vector<int>& container, int value) {
	std::vector<int>::iterator pos =
			std::lower_bound(container.begin(), container.end(), value);
	container.insert(pos, value);
}

std::vector<int> PmergeMe::mergeSort(std::vector<int> data)
{
	if (data.size() <= 1)
		return data;

	std::vector<int> smaller;
	std::vector<int> larger;

	smaller.reserve(data.size() / 2);
	larger.reserve(data.size() / 2 + 1);

	for (std::size_t i = 0; i + 1 < data.size(); i += 2)
	{
		if (data[i] < data[i + 1])
		{
			smaller.push_back(data[i]);
			larger.push_back(data[i + 1]);
		}
		else
		{
			smaller.push_back(data[i + 1]);
			larger.push_back(data[i]);
		}
	}

	bool	has_straggler = (data.size() % 2 != 0);
	int		straggler = 0;

	if (has_straggler)
		straggler = data.back();

	larger = mergeSort(larger);

	if (!smaller.empty())
		BinaryInsert(larger, smaller[0]);

	for (std::size_t i = 1; i < smaller.size(); ++i)
		BinaryInsert(larger, smaller[i]);

	if (has_straggler)
		BinaryInsert(larger, straggler);

	return larger;
}
