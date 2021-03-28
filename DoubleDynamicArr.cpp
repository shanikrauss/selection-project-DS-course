#include "DoubleDynamicArr.h"


	DoubleDynamicArr::DoubleDynamicArr() : arr(new double[1]), logSize(0), phySize(1)
	{}


	DoubleDynamicArr::DoubleDynamicArr(int size) : arr(new double[size]), logSize(0), phySize(size)
	{}


	DoubleDynamicArr::~DoubleDynamicArr()
	{
		delete[] arr;
	}



	DoubleDynamicArr::DoubleDynamicArr(const DoubleDynamicArr& other) : arr(nullptr)
	{
		*this = other;
	}


	const DoubleDynamicArr& DoubleDynamicArr::operator=(const DoubleDynamicArr& other)
	{
		if (this != &other) {
			logSize = other.logSize;
			phySize = other.phySize;
			delete[] arr;
			arr = new double[phySize];
			for (int i = 0; i < logSize; i++) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	const double& DoubleDynamicArr::operator[](int i) const 
	{
		return arr[i];
	}


	double& DoubleDynamicArr::operator[](int i) 
	{	
		return arr[i];
	}




	double DoubleDynamicArr::get(int idx) const
	{
		return arr[idx];
	}


	void DoubleDynamicArr::set(int idx, double val)
	{
		arr[idx] = val;
	}


	void DoubleDynamicArr::addVal(int idx, double val) 
	{
		set(idx, arr[idx] + val);
	}


	int DoubleDynamicArr::getPhySize() const
	{
		return phySize;
	}


	int DoubleDynamicArr::getLogSize() const
	{
		return logSize;
	}


	void DoubleDynamicArr::resize(int size)
	{
		double* tmp = new double[size];

		for (int i = 0; i < logSize; ++i)
			tmp[i] = arr[i];

		delete[] arr;

		arr = tmp;
		this->phySize = size;
	}


	void DoubleDynamicArr::setLogSize(int size)
	{
		resize(size);
	}




	


	void DoubleDynamicArr::pushBack(double val) 
	{
		// resize array if needed
		if (logSize == phySize) {
			resize(phySize * 2 + 1);
		}
		// add new value
		arr[logSize] = val;
		++logSize;
	}

	void DoubleDynamicArr::swap(int idx1, int idx2)
	{
		double saveVal = get(idx1);
		set(idx1, get(idx2));
		set(idx2, saveVal);
	}