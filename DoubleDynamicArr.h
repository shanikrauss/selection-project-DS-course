#pragma once


	class DoubleDynamicArr
	{
	private:
		double* arr;
		int logSize;
		int phySize;
		void resize(int size); // initialize the new cells to 0, without changing the old cells

	public:
		DoubleDynamicArr();
		DoubleDynamicArr(int size);
		~DoubleDynamicArr();

		DoubleDynamicArr(const DoubleDynamicArr&); 
		const DoubleDynamicArr& operator=(const DoubleDynamicArr& other);

		const double& operator[](int i) const;

		double& operator[](int i);


		int get(int idx) const;
		void set(int idx, double val);

		void addVal(int idx, double val = 1);

		void setLogSize(int size);
		int getPhySize() const;
		int getLogSize() const;
		void add(double val = 0);
		void swap(int idx1, int idx2);
	};
