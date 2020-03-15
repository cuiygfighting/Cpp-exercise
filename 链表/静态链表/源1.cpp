#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Stu
{
	int num;
	string name;
	int score;
	Stu *next;
};
int main()
{
	Stu stu[3] = { {101,"cui",100},{102,"bin",90},{103,"apo",80} };
	Stu *p, *head;
	head = &stu[0];
	stu[0].next = &stu[1];
	stu[1].next = &stu[2];
	stu[2].next = NULL;
	p = head;
	while (p != NULL)
	{
		cout << p->num <<"   "<< (*p).name <<"   "<< p->score<<endl;
		p = p->next;
	}
	return 0;
}