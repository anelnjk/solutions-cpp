// Task #1 (50%)

// Write a program that propmpts the user to input integer N. Then accept N integers and store them in one-dimensional array. 
// Please note, that each integer is in the range [1,N-1].
// Your task is to write a function which returns the number that appears twice in the array.
// It's guaranteed that there is only one pair of numbers with the same value
// (You may use dynamic arrays, functions and pointers)

// Example 1
// Input
// 5
// 1 3 4 2 2

// Output
// 2

// Example 2
// Input
// 3
// 1 1 2

// Output
// 1

// /////////////////////
// /////SOLUTION:///////
// /////////////////////

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

//function signature
void findThePair(int*, int);

int main()
{
	int n;
	cin >> n;
  //allocate dynamic memory for array
	int* bob = new int[n]; 
  //input array by using pointers
	for (int i = 0; i < n; i++)
	{
		cin >> *(bob+i);
	}
  //check if all numbers are in the range [1, n-1]
  for(int i=0;i<n;i++)
  {
    if(bob[i]<1||bob[i]>n)
    {
      return 0;
    }
  }
  //calling the function to find the pair
  findThePair(bob, n);
  return 0;
}
//funcion to find the pair
void findThePair(int* bob, int n)
{
  int res=0;
  int num=0;
  //compare each elements from index 0 with 
  //next elements [0+1] and so on in array
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(bob[i]==bob[j])
      //if the are same elements save it to var "num"
      {
        res++;
        num=bob[i];
      }
    }
    if(res==1)
    //we have to find pair(element that appears twice, 
    //so ther should have been only one repetition)
    {
      cout<<num;
      break;
      //use break to show this element only once
    }
  }
}
// _________________________________________________________________________________________________________________________________

// Task #2 (30%)

// Create two structs

// struct Student which has
// - ID
// - Name
// - grade

// struct Subject which has
// - ID
// - name
// - number of students
// - students(pointer to Students` struct)


// Your task is to show all subjects, which contains the given students in the given range of grades, sorted by grade in ascending order. 
// Have to use structs, pointers and dynamic memory allocation.

// Input
// n (how many subjects) [2 = n = 10]
// n-times 
//     subject id
//     subject name
//     number of students 
//     all information about students
// searched_item range(in format of xxx-yyy)

// Output
// All subject, which contains the given student in the given range
// Example

// Input
// 5
// 101 Physics 2
// 1 Kate 100
// 2 Max 50

// 203 Economics 3
// 1 Kate 30
// 2 Max 70
// 3 Askar 80

// 304 C++ 2
// 3 Askar 100
// 1 Kate 10

// 409 Geography 3
// 1 Kate 40
// 4 Lucy 90
// 2 Max 86

// 1012 Math 2
// 1 Kate 90
// 3 Askar 50

// Kate 30-80

// Output

// 203 Economics
// 409 Geography

// /////////////////////
// /////SOLUTION:///////
// /////////////////////

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
//create structs
struct student
{
	int id;
	string name;
	int grade;
};

struct subject
{
	int id;
	char* name;
	int snum;
	student* students;
};
//function signatures using templates 
template <class T>
void inputSub(T*, int);

template <class T>
void inputStud(T*, int);

template <class T>
void findSub(string, char*, T*, int, int, int);

void convertRange(string, int &, int &);

int k=0;
int main()
{
	int n;
	cin >> n;

	subject* subjects = new subject[n];
  subject* finalList = new subject[n];
	inputSub(subjects, n);
  //enter name of student and his/her grade
	char* range = new char[20];
	string name;
	cin >> name >> range;
  int rangeStart=0, rangeEnd=0;
  convertRange(range, rangeStart, rangeEnd);
	findSub(name, range, subjects, n, rangeStart, rangeEnd);

	return 0;
}


//function that converts sumbols in grade to numbers
//so that we can compare grades in future
//void convertRange(string range, int &rangeLow, int &rangeHigh) 

{
		string s10, s1;
		int i = 0;
		while (range[i] != '-') {
			if (isdigit(range[i])) {
				s10 += range[i];
        			//string 1+0=10 and so on
			}
			i++;
		}
		while (range[i] != '\0') {
			if (isdigit(range[i])) {
				s1 += range[i];
			}
			i++;
		}
		rangeLow = stoi(s10);
	  	rangeHigh = stoi(s1);
}

template <class T>
void inputStud(T* studs, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> studs[i].id >> studs[i].name >> studs[i].grade;
	}
}

template <class T>
void inputSub(T* subs, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> subs[i].id;
		subs[i].name = new char[10];
		cin >> subs[i].name >> subs[i].snum;
		subs[i].students = new student[subs[i].snum];
		inputStud(subs[i].students, subs[i].snum);
	}
}

template <class T>
void findSub(string name, char* range, T* subs, int n, int rangeStart, int rangeEnd)
{
	for (int i = 0; i < n; i++)
  //check each subject
	{
		for (int j = 0; j < subs[i].snum; j++)
    //check each student
		{
			if (name == subs[i].students[j].name)
      //if there is a student with name we entered:
			{
        //check if mark is in the range:
          if((subs[i].students[j].grade>=rangeStart)&&(subs[i].students[j].grade<=rangeEnd))
          {
            cout << subs[i].id<<" "<<subs[i].name<<"\n";
            break;
        }
			}
		}
	}
}

