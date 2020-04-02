class Bag:

    # creates a new, empty Bag

    # the Bag will have two list: one of integers, one of frequencies
    def __init__(self):
        '''
        complexity:
            Theta(1)
        '''
        self.__integer = []
        self.__frequency = []

    # adds a new element to the Bag

    # if the integer is in the list, the frequency is raised with one
    # otherwise, the integer is added at the end of the list, having the frequency one
    def add(self, e):
        '''
        complexity:
            O(n)
        '''
        if e in self.__integer:
            position = self.__integer.index(e)
            self.__frequency[position] += 1
        else:
            self.__integer.append(e)
            self.__frequency.append(1)

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed

    # if integer appear just once, we delete both the integer and frequency
    # if integer appear more than once, the frequency is decreased with one
    def remove(self, e):
        '''
        complexity:
            O(n)
        '''
        if e in self.__integer:
            position = self.__integer.index(e)
            if self.__frequency[position] == 1:
                del self.__integer[position]
                del self.__frequency[position]
            else:
                self.__frequency[position] -= 1
            return True
        return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise

    # search only in the integer list
    def search(self, e):
        '''
        complexity:
            O(n)
        '''
        return e in self.__integer

    # counts and returns the number of times the element e appears in the bag

    # it returns the frequency linked with that integer
    def nrOccurrences(self, e):
        '''
        complexity:
            O(n)
        '''
        if e in self.__integer:
            position = self.__integer.index(e)
            return self.__frequency[position]
        else:
            return 0

    # returns the size of the Bag (the number of elements)

    # search in whole list and add the frequencies
    def size(self):
        '''
        complexity:
            Theta(n)
        '''
        count = 0
        for i in range(len(self.__integer)):
            count += self.__frequency[i]
        return count

    # returns True if the Bag is empty, False otherwise
    def isEmpty(self):
        '''
        complexity:
            Theta(1)
        '''
        return self.__integer == []

    # returns a BagIterator for the Bag
    def iterator(self):
        '''
        complexity:
            Theta(1)
        '''
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        '''
        complexity:
            Theta(1)
        '''
        self.__bag = b
        self.__current_position = 0
        self.__current_frequency = 1

    # returns True if the iterator is valid
    def valid(self):
        '''
        complexity:
            O(n)
        '''
        if self.__current_position < len(self.__bag._Bag__integer):
            if self.__current_frequency <= self.__bag._Bag__frequency[self.__current_position]:
                return True
        return False

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    def getCurrent(self):
        '''
        complexity:
            Theta(1)
        '''
        if not self.valid():
            raise ValueError()
        return self.__bag._Bag__integer[self.__current_position]

    # moves the iterator to the next element
    # throws ValueError if the iterator is not valid
    def next(self):
        '''
        complexity:
            Theta(1)
        '''
        if not self.valid():
            raise ValueError()
        if self.__current_frequency == self.__bag._Bag__frequency[self.__current_position]:
            self.__current_position += 1
            self.__current_frequency = 1
        else:
            self.__current_frequency += 1

    # sets the iterator to the first element from the Bag
    def first(self):
        '''
        complexity:
            Theta(1)
        '''
        self.__current_position = 0
        self.__current_frequency = 1

