/*  Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number.
Make use of two collision Handling Techniques (like Linear Probing, Quadratic
probing etc.) and compare them using number of comparisons required to find a set
of telephone number. */

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 10;
int osize;

class Client
{
public:
    string name;
    long pno;

    Client()
    {
        name = "";
        pno = 0;
    }
};
class HashTable
{
public:
    Client arr[SIZE];

    HashTable()
    {
        osize = 0;
    }

    // HASH FUNCITON
    int hash(long pno)
    {
        return pno % SIZE;
    }

    // INSERT USING LINEAR PROBING
    void insertL(Client c)
    {
        // finding key
        int index = hash(c.pno);
        // checking for table if full or not
        if (!isFull(osize))
        {

            while (arr[index].pno != 0) // no collision
            {
                // with linear probing
                index = (index + 1) % SIZE;

            } // insert client
            arr[index].name = c.name;
            arr[index].pno = c.pno;
            osize++;
        }
        else
        {
            cout << "\nTable is full.." << endl;
        }
    }

    // insert using quadratic probing
    void insertQ(Client c)
    {
        // finding key
        int index = hash(c.pno);
        // checking for table if full or not
        if (!isFull(osize))
        {
            int i = 0;
            while (arr[index].pno != 0) // no collision
            {
                i++;
                // with linear probing
                index = (index + i * i) % SIZE;

            } // insert client
            arr[index].name = c.name;
            arr[index].pno = c.pno;
            osize++;
        }
        else
        {
            cout << "\nTable is full.." << endl;
        }
    }

    bool isFull(int osize)
    {
        return (SIZE == osize);
    }

    bool search(long phoneno)
    {
        int index = hash(phoneno);
        int count = SIZE;
        while (count != 0)
        {
            if (arr[index].pno != phoneno) // not present or synonym found
            {
                // with linear probing
                index = (index + 1) % SIZE;
                count--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    void display()
    {
        cout << "\nClient List" << endl;

        // occupied table

        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i].pno != 0)
            {
                cout << arr[i].name << " : " << arr[i].pno << "\n";
            }
        }
        // total size
        cout << "\nTotal table: " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i].name << " : " << arr[i].pno;
            cout << endl;
        }
    }
};
int main()
{
    int ch;
    string nam;
    long no, phoneno;
    int choice;
    HashTable ht;

    do
    {
        cout << "\n1. Insert with linear probing \n2. Insert with quadratic probing\n3. Search \n4. Display ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            Client c;
            cout << "\nEnter name: ";
            cin >> c.name;
            cout << "\nEnter phone number: ";
            cin >> c.pno;
            ht.insertL(c);

            break;
        }

        case 4:
        {
            ht.display();
            break;
        }
        case 2:
        {
            Client c;
            cout << "\nEnter name: ";
            cin >> c.name;
            cout << "\nEnter phone number: ";
            cin >> c.pno;
            ht.insertQ(c);

            break;
        }
        case 3:
        {
            cout << "Enter phone number of user to be searched : ";
            cin >> phoneno;
            bool isFound = ht.search(phoneno);
            if (isFound)
            {
                cout << "\nUser Found!!";
            }
            else
            {
                cout << "\nUser not found..";
            }

            break;
        }
        }

        cout << "do u want to continue? ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}