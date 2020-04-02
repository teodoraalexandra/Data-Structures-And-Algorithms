//
// Created by Teodora Dan on 2019-04-03.
//

#include "BagIterator.h"

Bag::Bag()
{
}


Bag::~Bag()
{

}

void Bag::add(TElem e)
{
	//U = [5, 10, -1, 2, 3, -5]
	//P = [0, 1, 2, 3, 4, 1, 0, 0, 5]

	TElem i;
	TElem pos = -1;
	for (i = 0; i < this->unique.getSize(); i++)
	{
		if (e == this->unique[i])
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
		//TElem e exist in U, so we add in P the position found in for loop
	{
		this->positions.add(pos);
	}
	else
		//TElem e does not exist in U, so we add it in U too
	{
		this->unique.add(e);
		this->positions.add(this->unique.getSize() - 1);
	}
}



bool Bag::remove(TElem e)
{
	//U = [5, 10, -1, 2, 3, -5]
	//P = [0, 1, 2, 3, 4, 1, 0, 0, 5]
	TElem i;
	int freq = 0;
	int pos = -1;
	int pos_unique = -1;
	for (i = 0; i < this->positions.getSize(); i++)
	{
		if (e == this->unique[this->positions[i]])
		{
			freq++;
			pos = i;
			pos_unique = this->positions[i];
		}
	}

	if (freq > 1)
	//The case where the element appears more than once
	{
		this->positions[pos] = this->positions[this->positions.getSize() - 1];
		this->positions.removeLast();
		return true;
	}

	if (freq == 1)
	//The case where the element appears exactly once
	{
		int old_pos = this->unique.getSize() - 1;
		this->unique[pos_unique] = this->unique[old_pos];
		this->positions[pos] = this->positions[this->positions.getSize() - 1];
		this->positions.removeLast();
		for (i = 0; i < this->positions.getSize(); i++)
		{
			if (this->positions[i] == old_pos)
				this->positions[i] = pos_unique;
		}
		this->unique.removeLast();

		return true;
	}
	return false;
}


bool Bag::search(TElem e)
{
	//U = [5, 10, -1, 2, 3, -5]
	//P = [0, 1, 2, 3, 4, 1, 0, 0, 5]
	TElem i;
	for (i = 0; i < this->unique.getSize(); i++)
	{
		if ( this->unique[i] == e)
		//In U, search if e exists
		{
			return 1;
		}
	}
	return 0;
}

int Bag::size() const
{
	return this->positions.getSize();
}

int Bag::nrOccurrences(TElem e) const
{
	//U = [5, 10, -1, 2, 3, -5]
	//P = [0, 1, 2, 3, 4, 1, 0, 0, 5]
	TElem i;
	int freq = 0;
	for (i = 0; i < this->positions.getSize(); i++)
	{
		//For example:
			//5 is at pos 0 in U
			//0 appears 3 times in P
			//frequency of 5 is 3
		int position = this->positions[i];
		if (e == this->unique[position])
		{
			freq++;
		}
	}
	return freq;
}


bool Bag::isEmpty() const
{
	if (this->positions.getSize() == 0)
		return true;
	return false;

}

//LAB ACTIVITY
int Bag::minimumFrequency() const {
	if (this->positions.getSize() == 0)
		return 0;

    int minimumFrequency = 100;
    TElem i;
    TElem e;

	for (e = 0; e < this->unique.getSize() ; e++) {
		int freq = 0;
		for (i = 0; i < this->positions.getSize(); i++) {

			int position = this->positions[i];
			if (this->unique[e] == this->unique[position])
			{
				freq++;
			}

		}

		if (minimumFrequency > freq) {
			minimumFrequency = freq;
		}
	}

	return minimumFrequency;
}

int Bag::elementsWithMinimumFrequency() const {
	if (this->positions.getSize() == 0)
		return 0;

	int minimumFrequency = this->minimumFrequency();
	TElem i;
	TElem e;
	int count = 0;

	for (e = 0; e < this->unique.getSize() ; e++) {
		int freq = 0;
		for (i = 0; i < this->positions.getSize(); i++) {

			int position = this->positions[i];
			if (this->unique[e] == this->unique[position])
			{
				freq++;
			}

		}

		if (minimumFrequency == freq) {
			count ++;
		}
	}

	return count;
}

BagIterator Bag::iterator() const
{
	BagIterator it( *this );
	return it;
}


