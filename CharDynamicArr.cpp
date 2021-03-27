#include "CharDynamicArr.h"


	CharDynamicArr::CharDynamicArr() : arr(new char[1]), logSize(0), phySize(1)
	{}


	CharDynamicArr::CharDynamicArr(int size) : arr(new char[size]), logSize(0), phySize(size)
	{}


	CharDynamicArr::~CharDynamicArr()
	{
		delete[] arr;
	}


	int CharDynamicArr::get(int idx) const
	{
		return arr[idx];
	}


	void CharDynamicArr::set(int idx, char val)
	{
		arr[idx] = val;
	}


	void CharDynamicArr::addVal(int idx, char val) 
	{
		set(idx, arr[idx] + val);
	}


	int CharDynamicArr::getPhySize() const
	{
		return phySize;
	}


	int CharDynamicArr::getLogSize() const
	{
		return logSize;
	}


	void CharDynamicArr::setLogSize(int size)
	{
		resize(size);
	}


	void CharDynamicArr::resize(int size)
	{
		char* tmp = new char[size];

		for (int i = 0; i < logSize; ++i)
			tmp[i] = arr[i];

		delete[] arr;

		arr = tmp;
		this->phySize = size;
	}

	void CharDynamicArr::reset()
	{
		delete[] arr;
		arr = new char[1];
		logSize = 0;
		phySize = 1;
	}


	void CharDynamicArr::add(char val)
	{
		// resize array if needed
		if (logSize == phySize) {
			resize(phySize * 2 + 1);
		}

		// add new value
		arr[logSize] = val;
		++logSize;
	}


	char* CharDynamicArr::getString()
	{
		char* string = new char(logSize);
		int i=0;
		
		for (i = 0; i < logSize; i++)
		{
			string[i] = arr[i];
		}

		return string;
	}

