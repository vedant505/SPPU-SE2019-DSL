#include <iostream>
#include <string>
using namespace std;

int total = 0; // Keeps track of the total number of members

struct node
{
    int PRN;
    string name;
    node *next;
};

// Insert the president at the beginning of the list
node *insertPresident(node *&head, int PRN, string name)
{
    node *temp = new node;
    temp->PRN = PRN;
    temp->name = name;
    temp->next = head;
    head = temp;
    total++;
    return head;
}

// Insert a member at a specific position in the list
node *insertMember(node *&head, int index, int PRN, string name)
{
    node *ptr = head;
    int i = 0;
    while (i != (index - 1))
    {
        ptr = ptr->next;
        i++;
    }

    node *temp = new node;
    temp->PRN = PRN;
    temp->name = name;
    temp->next = ptr->next;
    ptr->next = temp;
    total++;
    return head;
}

// Insert the secretary at the end of the list
node *insertSecretary(node *&head, int PRN, string name)
{
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    node *temp = new node;
    temp->PRN = PRN;
    temp->name = name;
    temp->next = NULL;
    ptr->next = temp;
    total++;
    return head;
}

// Delete the president (first node in the list)
node *deletePresident(node *&head)
{
    node *p = head;
    head = head->next;
    delete p;
    total--;
    return head;
}

// Delete the secretary (last node in the list)
node *deleteSecretary(node *&head)
{
    node *p = head;
    node *temp = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (temp->next != p)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete p;
    total--;
    return head;
}

// Delete a member at a specific position
node *deleteMember(node *&head, int index)
{
    node *p = head;
    node *temp = head->next;
    for (int i = 0; i < (index - 1); i++)
    {
        p = p->next;
        temp = temp->next;
    }

    p->next = temp->next;
    delete temp;
    total--;

    return head;
}

// Display all members in the list
void display(node *&head)
{
    node *temp = head;
    int i = 1;

    while (temp != NULL)
    {
        cout << "For " << i << "th member " << endl;
        cout << "PRN is " << temp->PRN << endl;
        cout << "Name is " << temp->name << endl;
        cout << endl;
        temp = temp->next;
        i++;
    }
}

int main()
{
    node *head = NULL; // Initialize the head of the linked list
    int ch, PRN, index;
    string name;
    while (1)
    {
        // Display menu options
        cout << "\n____________________________\n********* MENU ***********" << endl;
        cout << " 1.Insert President,\n 2.Insert Secretary,\n 3.Insert Member,\n 4.Delete President,\n 5.Delete Secretary,\n 6.Delete Member,\n 7.Total No. Of Members,\n 8.Display Members,\n 9.Exit \n Enter your choice :-" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter PRN : ";
            cin >> PRN;
            cout << "Enter Name : ";
            cin >> name;
            insertPresident(head, PRN, name);
            break;
        case 2:
            cout << "Enter PRN : ";
            cin >> PRN;
            cout << "Enter Name : ";
            cin >> name;
            insertSecretary(head, PRN, name);
            break;
        case 3:
            cout << "Enter PRN : ";
            cin >> PRN;
            cout << "Enter Name : ";
            cin >> name;
            insertMember(head, (total - 1), PRN, name);
            break;
        case 4:
            deletePresident(head);
            break;
        case 5:
            deleteSecretary(head);
            break;
        case 6:
            cout << "Which member you want to delete ? " << endl;
            cin >> index;
            deleteMember(head, index);
            break;
        case 7:
            cout << "Total No. Of Members are : " << total;
            break;
        case 8:
            display(head);
            break;
        case 9:
            cout << "*** TERMINATED SUCCESSFULLY ***" << endl;
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}
