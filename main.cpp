#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "CharDynamicArr.h"
#include "DoubleDynamicArr.h"

using namespace std;

#define isIValid(i,n) (((i >= 1 && i <= n)) ? true : false)
#define isNValid(n) ((n>0) ? true : false)
#define isDigit(x) (((x-'0') >=0) && ((x-'0') <=9) ? true : false)


bool checkValidInputOfNum(CharDynamicArr* input)
{
	int i = 1;
	int len = input->getLogSize();
	int countNumOfDigitAfterDot = 0;
	char ch;
	bool isDot = false;

	while (len - i >= 0 && !isDot)
	{
		ch = input->get(len - i);
		if (isDigit(ch))
		{
			countNumOfDigitAfterDot++;
		}
		else if (ch == '.')
		{
			isDot = true;
		}
		else
		{
			return false;
		}

		if (countNumOfDigitAfterDot > 4)
		{
			return false;
		}
		i++;
	}

	if (countNumOfDigitAfterDot == 0 || (countNumOfDigitAfterDot <= 4 && !isDot))
	{
		return false;
	}
	return true;
}



void insertionSort(DoubleDynamicArr arr)
{
	int i = 0, j = 0;
	double num = 0;

	for (i = 1; i < arr.getLogSize(); i++)
	{
		num = arr.get(i);
		
		for (j = i - 1; j >= 0 && arr.get(j) > num; j--)
		{
			arr.set(j + 1, arr.get(j));
		}
		arr.set(j + 1, num);
	}
}


void swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


int partition(DoubleDynamicArr& arr, int pivot, int index)
{
	int arrSize = index - pivot + 1;
	bool isIndexRightToPivot = true;

	for (int i = 0; i < arrSize; i++)
	{
		if (isIndexRightToPivot)
		{
			if (arr[pivot] > arr[index])
			{
				arr.swap(pivot, index);
				swap(pivot, index);

				isIndexRightToPivot = !isIndexRightToPivot;
				index++;
			}
			else
			{
				index--;
			}
		}
		else
		{
			if (arr[pivot] < arr[index])
			{
				arr.swap(pivot, index);
				swap(pivot, index);

				isIndexRightToPivot = !isIndexRightToPivot;
				i--;
			}
			else
			{
				i++;
			}
		}
	}
}



//double Select(DoubleDynamicArr& arr, int left, int right, int idx)
//{
//	int pivot, leftPart;
//
//	pivot = partition(arr, left, right);
//	leftPart = pivot - left + 1;
//	if (idx == leftPart)
//	{
//		return arr.get(pivot);
//	}
//	if (idx < leftPart)
//	{
//		return Select(arr, left, pivot - 1, idx);
//	}
//	else
//	{
//		return Select(arr, pivot + 1, right, idx - leftPart);
//	}
//}


int main() {
	int n = 0, i = 0, j = 0;
	CharDynamicArr number;
	char ch;

	//getting n, the amount of numbers, and i, the index of the requested number.
	cin >> n >> i;

	//checking if i and n are valid, else exit the program
	if (!isIValid(i, n) || !isNValid(n))
	{
		cout << "wrong input" << endl;
		exit(1);
	}

	ch = getchar(); //getting '\n'

	//getting the numbers from the user
	for (j = 0; i < n; j++) {
		ch=getchar();
		
		while (ch != ' ' && ch != '\n')
		{
			number.add(ch);
			ch = getchar();
			
		} //how to reset the object"number"?
		if(!checkValidInputOfNum(&number))
		{
			cout << "wrong input" << endl;
			exit(1);
		}
		number.reset();
	}







	//if (isNValid(strN)) {
	//	n = stoi(strN);
	//}
	//if (n == 0)
	//{
	//	cout << 0 << endl << 0 << endl << 0 << endl;
	//}
	//else
	//{
	//	getline(cin, str1);
	//	getline(cin, str2);

	//	if (str1.length() != n || str2.length() != n || !isStrValid(str1, str2))
	//	{
	//		cout << " wrong output" << endl;
	//		exit(1);
	//	}

	//	NumArray x(str1);
	//	NumArray y(str2);

	//	auto start = chrono::high_resolution_clock::now();
	//	// unsync the I/O of C and C++.
	//	ios_base::sync_with_stdio(false);
	//	NumArray res = longMult(x, y); // Here you put the name of the function you wish to measure
	//	auto end = chrono::high_resolution_clock::now();
	//	// Calculating total time taken by the program.
	//	double time_taken_long_mult =
	//		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	//	time_taken_long_mult *= 1e-9;

	//	start = chrono::high_resolution_clock::now();
	//	// unsync the I/O of C and C++.
	//	ios_base::sync_with_stdio(false);
	//	NumArray res1 = kartsuba(x, y);// Here you put the name of the function you wish to measure
	//	end = chrono::high_resolution_clock::now();
	//	// Calculating total time taken by the program.
	//	double time_taken_rec_Kartsuba =
	//		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	//	time_taken_rec_Kartsuba *= 1e-9;

	//	start = chrono::high_resolution_clock::now();
	//	// unsync the I/O of C and C++.
	//	ios_base::sync_with_stdio(false);
	//	NumArray res2 = kartsubaStack(x, y); // Here you put the name of the function you wish to measure
	//	end = chrono::high_resolution_clock::now();
	//	// Calculating total time taken by the program.
	//	double time_taken_non_rec_Kartsuba =
	//		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	//	time_taken_non_rec_Kartsuba *= 1e-9;

	//	ofstream myfile("Measure.txt"); // The name of the file
	//	myfile << "Time taken by function <longMult> is : " << fixed
	//		<< time_taken_long_mult << setprecision(9);
	//	myfile << " sec" << endl;

	//	myfile << "Time taken by function <Kartsuba> is : " << fixed
	//		<< time_taken_rec_Kartsuba << setprecision(9);
	//	myfile << " sec" << endl;

	//	myfile << "Time taken by function <KartsubaStack> is : " << fixed
	//		<< time_taken_non_rec_Kartsuba << setprecision(9);
	//	myfile << " sec" << endl;


	//	cout << "Long multiplication : x * y = "<< res << endl;

	//	cout << "Karatsuba(recursive) : x * y = " << res1 << endl;

	//	cout << "Karatsuba (iterative): x * y = "<< res2 << endl;

	//	myfile.close();

	//}
	//return 0;
}