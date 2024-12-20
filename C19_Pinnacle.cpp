#include<iostream>
using namespace std;

class student
{
	int roll;
	string name;
	student *next;
	public:
		student* create();
		void display(student *head);
		student* beg_add(student *head);
		student* end_add(student *head);
		student* btwn_add(student *head);
		student* beg_del(student *head);
		student* end_del(student *head);
		student* btwn_del(student *head);
		student* total(student *head);
		student* con(student *head,student *head1);
};

student* student::create()
{
	int n;
	student *head,*p;
	head = NULL;
	cout<<"Enter number of members: ";
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		if(head == NULL)
		{
			head = new student;
			cout<<"\nEnter prn of president: ";
			cin>>head->roll;
			cout<<"Enter name of president: ";
			cin>>head->name;
			head->next = NULL;
			p = head;
		}
		else
		{
			p->next = new student;
			p = p->next;
			cout<<"\nEnter prn of member: ";
			cin>>p->roll;
			cout<<"Enter name of member: ";
			cin>>p->name;
			p->next = NULL;
		}
	}
	return head;

}

void student::display(student *head)
{
	student *p;
	for(p = head; p->next!= NULL; p = p->next)
	{
		cout<<p->roll<<" "<<p->name<<"->";
	}
	cout<<p->roll<<" "<<p->name<<endl;
}

student* student::beg_add(student *head)
{
    student *p;
    p = new student;
    cout<<"\nEnter prn of new president: ";
    cin>>p->roll;
    cout<<"Enter name of new president: ";
    cin>>p->name;
    p->next = NULL;
    p->next = head;
    head = p;
    return head;
}

student* student::end_add(student *head)
{
    student *p,*q;
    p = new student;
    cout<<"\nEnter prn of secretary: ";
    cin>>p->roll;
    cout<<"Enter name of secretary: ";
    cin>>p->name;
    p->next = NULL;
    for(q = head; q->next!=NULL; q = q->next);
    q->next = p;
    return head;
}

student* student::btwn_add(student *head)
{
    int y;
    student *p,*q;
    p = new student;
    cout<<"\nEnter prn of new member: ";
    cin>>p->roll;
    cout<<"Enter name of new member: ";
    cin>>p->name;
    cout<<"Enter prn after which new member is to be added: ";
    cin>>y;
    p->next = NULL;
    q = head;
    while(q!=NULL)
    {
        if(q == NULL)
        {
            cout<<"\nInvalid Data....."<<endl;
        }
        else if(q->roll == y)
        {
            p->next = q->next;
            q->next = p;
        }
        q = q->next;
    }
    return head;
}

student* student::beg_del(student *head)
{
    student *p;
    p = head;
    head = head->next;
    delete p;
    return head;
}

student* student::end_del(student *head)
{
    student *p,*q;
    for(q = head; q->next->next!=NULL; q = q->next);
    p = q->next;
    delete p;
    q->next = NULL;
}

student* student::btwn_del(student *head)
{
    int y;
    student *p,*q;
    cout<<"\nEnter prn of member which is to be deleted: ";
    cin>>y;
    if(head == NULL)
    {
        cout<<"\nLinked list is empty!!";
        return head;
    }
    p = head;
    while(p->next!=NULL)
    {
        if(p->next->roll==y)
        {
            q = p->next;
            p->next = p->next->next;
            delete q;
        }
        p = p->next;
    }
    return head;
}

student* student::total(student *head)
{
    student *p;
    int total = 0;
    for(p = head; p!=NULL; p = p->next)
    {
        total++;
    }
    cout<<"\nTotal Number of students are: "<<total<<endl;
}

student* student::con(student *head,student *head1)
{
    student *p;
    for(p = head; p->next!=NULL; p = p->next);
    p->next = head1;
    return head;
}

int main()
{
	int flag = 1;
	int flag1 = 1;
	int flag2 = 1;
	int char0,char1,char2;
	student *head,*head1;
	student obj;
	while(flag)
    {
        cout<<"\nYOUR CHOICES ARE: ";
        cout<<"\n1. LINKED LIST1: \n2. LINKED LIST2: \n3. CONCATENATE LINKED LIST 1 & 2: \n4. EXIT";
        cout<<"\nEnter choice: ";
        cin>>char0;
        switch(char0)
        {
            case 1:
                while(flag1)
                {
                    cout<<"\nWhat operations on list1 would you like to perform?";
                    cout<<"\n1. Enter prn, name of members: \n2. Add new president: \n3. Add secretary: \n4. Add new members: \n5. Remove president: \n6. Remove secretary: \n7. Remove members: \n8. Total members present: \n9. Exit ";
                    cout<<"\nEnter choice: ";
                    cin>>char1;
                    switch(char1)
                    {
                        case 1:
                            head = obj.create();
                            obj.display(head);
                            break;

                        case 2:
                            head = obj.beg_add(head);
                            obj.display(head);
                            break;

                        case 3:
                            head = obj.end_add(head);
                            obj.display(head);
                            break;

                        case 4:
                            head = obj.btwn_add(head);
                            obj.display(head);
                            break;

                        case 5:
                            cout<<"\nRemoved president: ";
                            head = obj.beg_del(head);
                            obj.display(head);
                            break;

                        case 6:
                            cout<<"\nRemoved secretary: ";
                            obj.end_del(head);
                            obj.display(head);
                            break;

                        case 7:
                            head = obj.btwn_del(head);
                            cout<<"\nMember removed: ";
                            obj.display(head);
                            break;

                        case 8:
                            obj.total(head);
                            break;

                        case 9:
                            flag1 = 0;
                            break;

                        default:
                            cout<<"\nEnter valid choice!!!";
                            break;
                    }
                }
                break;

            case 2:
                while(flag2)
                {
                    cout<<"\nWhat operations on list1 would you like to perform?";
                    cout<<"\n1. Enter prn, name of members: \n2. Add new president: \n3. Add secretary: \n4. Add new members: \n5. Remove president: \n6. Remove secretary: \n7. Remove members: \n8. Total members present: \n9. Exit ";
                    cout<<"\nEnter choice: ";
                    cin>>char2;
                    switch(char2)
                    {
                        case 1:
                            head1 = obj.create();
                            obj.display(head1);
                            break;

                        case 2:
                            head1 = obj.beg_add(head1);
                            obj.display(head1);
                            break;

                        case 3:
                            head1 = obj.end_add(head1);
                            obj.display(head1);
                            break;

                        case 4:
                            head1 = obj.btwn_add(head1);
                            obj.display(head1);
                            break;

                        case 5:
                            cout<<"\nRemoved president: ";
                            head1 = obj.beg_del(head1);
                            obj.display(head1);
                            break;

                        case 6:
                            cout<<"\nRemoved secretary: ";
                            obj.end_del(head1);
                            obj.display(head1);
                            break;

                        case 7:
                            head1 = obj.btwn_del(head1);
                            cout<<"\nMember removed: ";
                            obj.display(head1);
                            break;

                        case 8:
                            obj.total(head1);
                            break;

                        case 9:
                            flag2 = 0;
                            break;

                        default:
                            cout<<"\nEnter valid choice!!!";
                            break;
                    }
                }
                break;

            case 3:
                head = obj.con(head,head1);
                obj.display(head);
                break;
            case 4:
                flag = 0;
                break;
            default:
                cout<<"\nEnter valid choice: ";
                break;
        }
    }

	return 0;
}
