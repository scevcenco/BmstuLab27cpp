// lab27_ver2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

class Horse
{
	string horseName;                             //parametrs of the object
	int results[5];
public:
	Horse(){}
	void SetHorse(string hName, int scores[])      //adding horse & 5 best results
	{
		cout << "Input the horse name" << endl;
		cin >> horseName;
		cout << "Input 5 best results" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << j + 1 << " result: ";
			cin >> results[j];
		}
		cout << "\n";
	}

	float AverageResult(int Hresults[])             //average result for 1 horse from 5 best
	{
		float sum = 0.0;
		for (int i = 0; i < 5; i++)
			sum += results[i];
		sum = sum / 5;
		return sum;
	}

	void PrintArray()                                  //print for Array Option
	{
		cout << "Horse's name: "<< horseName << "\n";
		cout << "5 best Results:"<< "\n";
		for (int i = 0; i < 5; i++)
		{
			cout << results[i] << " ";
		}
		cout << "\n";
	                
	}
	};


struct el
{
	Horse obj;
	el *p;
};

Horse obj;
Horse *array;

void ArrayHorses()                                      //Array Option
{
	int quantity;
	cout << "How many horses?" << endl;
	cin >> quantity;
	cout << "There're " << quantity << " horses.\n\n";
	cout<< "Input their names & 5 best results:\n\n";

	array = new Horse[quantity];
	string name;
	int results[5];
		
	for (int i = 0; i < quantity; i++)
	{
	 array[i].SetHorse(name, results);	
	}
	
	cout << "Array Stable" << "\n";
	cout << "_____________________________" << "\n";
	for (int i = 0; i < quantity; i++)
	{
		array[i].PrintArray();                             
		cout << "\nAverage result: " << array[i].AverageResult(results)<<"\n\n";
	}
	cout << "\nStable average: ";                                         //average for all horses
	float averageTime=0;
	for (int i = 0; i < quantity; i++)
	{
		averageTime += (averageTime+array[i].AverageResult(results))/quantity;
	}
	cout << averageTime << "\n\n";
	delete[]array;
}

void ListHorses()                                                      //list option
{	
	el *first, *cur;
	int quantity;
	string Lname;
	int Lresults[5];

	float Lsum=0;                                                    
	float averageTimeSum = 0;
	cout << "How many horses?" << endl;
	cin >> quantity;
	cout << "There're " << quantity << " horses!\n";
	cout << "Input the name & 5 best results of the horse N1:\n\n";
	first = new el;
	first->obj.SetHorse(Lname, Lresults);
	Lsum+=first->obj.AverageResult(Lresults);
	cout << "Average result: "<<Lsum << "\n\n";
	cur = first;
	float Lsum2;
	for (int i = 2; i <= quantity; i++)
	{
		cout << "Input the name & 5 best results of the horse N" << i << "\n";
		cur->p = new el;
		cur = cur->p;
		cur->obj.SetHorse(Lname, Lresults);
		Lsum2 = 0;
		Lsum2 += cur->obj.AverageResult(Lresults);
		cout << "Average result: " << Lsum2 << "\n\n";
		averageTimeSum += Lsum2;
	}
	float averageTime=(Lsum+averageTimeSum)/quantity;            //average for all horses
	cout << "\nStable's average: " << averageTime;          
	cur->p = NULL;
	while (first != NULL)
	{
		cur = first;
		first = first->p;
		delete cur;
	}
}

void main()
{
	cout << "__________Array Option____________" << "\n";
	ArrayHorses();
	cout << "____________List Option_____________" << "\n";
	ListHorses();
	_getch();
}

