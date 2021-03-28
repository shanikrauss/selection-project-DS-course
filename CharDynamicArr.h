#pragma once


	class CharDynamicArr
	{
	private:
		char* arr;
		int logSize;
		int phySize;
		void resize(int size); // initialize the new cells to 0, without changing the old cells

	public:
		CharDynamicArr();
		CharDynamicArr(int size);
		~CharDynamicArr();

		CharDynamicArr(const CharDynamicArr&)=delete; 

		int get(int idx) const;
		void set(int idx, char val);

		void addVal(int idx, char val = '0');

		void setLogSize(int size);
		int getPhySize() const;
		int getLogSize() const;
		void add(char val = '0');

		char* getString();
		const char* getString() const;


		void reset();
	};
