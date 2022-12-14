// Created by Hyunkun Cho on 9/28/2018
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

class BST
{
	int count = 0;			//counts number of arrays
	string mainKey[10];		//initial value 10 arrays
	string *prt;			//pointer for the mainKey array
	string minV;
public :					//making the menu as a public void function
	void insert(string);
	void dlt(string);
	void search(string);
	void min();
	void max();
	void getNext(string);
	void getPrev(string);
	void list();
	void help();
};
//insert
void BST::insert(string ins)
{
	mainKey[count] = ins;
	prt = mainKey;
	int ct = 0;
	for (int i = 0; i < 10; i++)
	{
		if (mainKey[i]==ins)
		{
			++ct;			//number next to string
		}
		if (ct == 1)
		{
			minV = ins;		//to get the min value string
		}
	}
	cout << ins << " " << ct;
	count++;
};
//delete
void BST::dlt(string ins)
{
	int rightV = 0;
	int ct = 0;
	prt = mainKey;
	for (int i = 0; i < 10; i++)
	{
		if (*(prt + i) == ins)
		{
			rightV = i;
		}
	}
	for (int i = rightV; i < 10 - rightV; ++i)
	{
		mainKey[i] = mainKey[i + 1];	//replacing the deleted empty array with next array value
	}
	for(int i=0;i<10;i++)
	{
		if (mainKey[i] == ins)
		{
			++ct;
		}
	}
	cout << ins << " " << ct;
};
//search
void BST::search(string ins)
{
	int flag = 0;
	int rightV = 0;
	prt = mainKey;
	for (int i = 0; i < 10; i++)
	{
		if (*(prt + i) == ins) {
			rightV = i;
			flag = 1;
			break;
		}
	}
	if (flag == 1) 
	{
		cout << "<" << ins << "> <" << rightV + 1 << ">";
	}
	else
	{
		cout << "<" << ins << "> <0>";
	}
};
//print min
void BST::min()
{
	if (mainKey[0].empty())
	{
		cout << "<no output>";
	}
	else
	{
		cout << mainKey[0] << endl;
		cout << minV << " - this string has only one count too" << endl;
	}
	
};
//print max
void BST::max()
{
	int max = 0;
	if (mainKey->empty())
	{
		cout << "<no output>";
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (mainKey[i].empty())
			{
				max = i - 1;
				break;
			}
		}
		cout << mainKey[max];
	}
};
//print the next
void BST::getNext(string ins)
{
	int nextI = 0;
	prt = mainKey;
	int Ch = 0;
	for (int i = 0; i < 10; i++)
	{
		if (*(prt + i) == ins)
		{
			nextI = i + 1;
			Ch = 1;
			break;
		}
	}
	if (Ch != 1)
	{
		cout << "<no output>";	
	}
	else
	{
		cout << mainKey[nextI];
	}
};
//print the previous
void BST::getPrev(string ins)
{
	int prevI = 0;
	prt = mainKey;
	int Ch = 0;
	for (int i = 0; i < 10; i++)
	{
		if (*(prt + i) == ins)
		{
			prevI = i - 1;
			Ch = 1;
			break;
		}
	}
	if (Ch != 1 && mainKey[prevI].empty())
	{
		cout << endl;	//print a blank line
	}
	else
	{
		cout << mainKey[prevI];
	}
};
//print list
void BST::list()
{
	for (int i = 0; i <= count; i++)
	{
		cout << mainKey[i] << endl;		//print the list of array from array[0] to end
	}
};
void BST::help()
{
	cout << "enter the number of the menu you wish then type in your string on following question.\n";
	cout << "1.insert, 2.delete, 3.search\n4.get min, 5.get max\n6.get next, 7.get prev\n8.get list, 9.help 0.exit\n";
};

int main()
{
	BST bst;
	int ans_U;
	int in_count = 0;
	cout << "type the number \n";
	cout << "1.insert, 2.delete, 3.search\n4.get min, 5.get max\n6.get next, 7.get prev\n8.get list, 9.help 10.exit\n";
	cin >> ans_U;
	while (ans_U != 10)
	{
		if (in_count != 0)
		{
			cout << endl << "what else do you want to do? type the number again\n"; //I intended to make one more line
			cin >> ans_U;
		}
		//insert
		if (ans_U == 1)
		{
			string ans_ins;
			cout << "what do you want to insert? \n";
			cin >> ans_ins;
			bst.insert(ans_ins);
		}
		//delete
		else if (ans_U == 2)
		{
			string ans_ins;
			cout << "what do you want to delete? \n";
			cin >> ans_ins;
			bst.dlt(ans_ins);
		}
		//search
		else if (ans_U == 3)
		{
			string ans_ins;
			cout << "what do you want to search? \n";
			cin >> ans_ins;
			bst.search(ans_ins);
		}
		//min
		else if (ans_U == 4)
		{
			bst.min();
		}
		//max
		else if (ans_U == 5)
		{
			bst.max();
		}
		//get next
		else if (ans_U == 6)
		{
			string ans_ins;
			cout << "type in the string ";
			cin >> ans_ins;
			bst.getNext(ans_ins);
		}
		//get prev
		else if (ans_U == 7)
		{
			string ans_ins;
			cout << "type in the string ";
			cin >> ans_ins;
			bst.getPrev(ans_ins);
		}
		//get list
		else if (ans_U == 8)
		{
			bst.list();
		}
		//get help
		else if (ans_U == 9)
		{
			bst.help();
		}
		//exit
		else if (ans_U == 0)
		{
			break;
		}
		in_count++;
	}

}