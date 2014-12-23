#include "StackedBoard.h"



iCard * StackedBoard::getCardX(unsigned int x) {

	if (listCard->size() < x)
		throw std::logic_error("the number is to big");

	std::list<Card*>::iterator it;

	it = listCard->begin();

	for (size_t i = 0; i < x; i++)
		it++;

	return *it;

}

iCard * StackedBoard::takeCardX(unsigned int x) {

	if (listCard->size() < x)
		throw std::logic_error("the number is to big");

	std::list<Card*>::iterator it;
	Card *card;

	it = listCard->begin();

	for (size_t i = 0; i < x; i++)
		it++;

	card = *it;

	listCard->erase(it);

	return card;

}

void StackedBoard::deleteCardX(unsigned int x) {

	if (listCard->size() < x)
		throw std::logic_error("the number is to big");

	std::list<Card*>::iterator it;

	it = listCard->begin();

	for (size_t i = 0; i < x; i++)
		it++;

	listCard->erase(it);

}

unsigned int StackedBoard::getSize() {

	return listCard->size();

}

unsigned int StackedBoard::getMaxSize() {

	return size_max;

}

void StackedBoard::setMaxSize(unsigned int size) {

	size_max = size;

}

void StackedBoard::addCardX(iCard *card, unsigned int x) {

	if (listCard->size() < x) {
		listCard->push_back((Card*)card);
	}
	else {
		std::list<Card*>::iterator it;

		it = listCard->begin();

		for (size_t i = 0; i < x; i++)
			it++;

		listCard->insert(it, (Card*)card);
	}
}

void StackedBoard::addCardX(std::list<iCard*> *listcard, unsigned int x) {

	if (listCard->size() < x)
		throw std::logic_error("the number is to big");

	if (size_max < listCard->size() + listcard->size())
		throw std::logic_error("the listcard is too big");

	std::list<Card*>::iterator it;

	it = listCard->begin();

	for (size_t i = 0; i < x; i++)
		it++;

	listCard->splice(it, reinterpret_cast <std::list<Card*> &>(listcard));

}

bool StackedBoard::isFull() {

	if (listCard->size() == size_max)
		return 1;
	else
		return 0;

}

StackedBoard::~StackedBoard() {
	listCard->erase(listCard->begin(), listCard->end());
	std::cout << "EXTERMINATE (StackedBoard) not yet" << std::endl;
}
