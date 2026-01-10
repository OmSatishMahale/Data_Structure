// Singly Circular

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout<<"Object of SinglyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                newn->next = this->first;
                this->first = newn;
            }

            this->last->next = this->first;

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                this->last->next = newn;
                this->last = newn;
            }

            this->last->next = this->first;

            this->iCount++;
        }

        void DeleteFirst()
        {
            if((this->first == NULL) && (this->last == NULL))
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;

                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                this->first = this->first->next;
                delete this->last->next;
                
                this->last->next = this->first;
            }

            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;

                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = first;

                while(temp->next != this->last)
                {
                    temp = temp->next;
                }

                delete temp->next;
                this->last = temp;

                this->last->next = this->first;
            }

            this->iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;

            do 
            {
                cout<<" | " << temp->data << " | -> ";
                temp = temp->next;

            }while(temp != this->last->next);

            cout<< "\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE newn = NULL;

            if((pos < 1) || (pos > iCount+1))
            {
                cout<<"Invalid Position.\n";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                temp = this->first;

                newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                this->iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid Position.\n";
                return;
            }

            if(pos == 1)
            {
                this->DeleteFirst();
            }
            else if(pos == iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                delete target;

                this->iCount--;
            }
        }
};

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    return 0;
}
