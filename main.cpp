#include <iostream>

using namespace std;

//1- Static Array
// no enlarge or merge in static array

const int siz = 100;

class ArrayStatic
{
private:
    int length;
    int items[siz];
public:
    ArrayStatic()
    {
        length = 0;
    }

    void filling()     //time O(n) memory O(n)
    {
        cout << "enter number of items to fill\n";
        int x;
        cin >> x;

        //validation
        if(x > siz)
        {
            cout << "cant exceed max size\n";
            return;
        }

        for(int i = 0; i < x; i++)
        {
            cout << "item no: " << i << endl;
            cin >> items[i];
            length++;
        }
        cout << "items have been added\n";
    }

    bool isempty() //O(1)
    {
        if(length  == 0)
            return true;
        return false;
    }

    bool isfull() //O(1)
    {
        if(length == siz)
            return true;
        return false;
    }

    //access
    int access(int i)
    {
        if(i < 0 || i > length)
            return -1;
        //cout << items[i];
        return items[i];
    }

    //insert
    void append(int k) //O(1)
    {
        if(isfull())
            return;
        items[length] = k;
    }

    //insert
    void inserte(int index, int k) //O(n)
    {
        if(isempty())
        {
            append(k);
            return;
        }

        for(int i = length; i > index; i--) //O(n)
            items[i] = items[i-1];
        items[index] = k;
        length++;
    }


    void display() //O(n)
    {
        if(isempty())
        {
            cout << "array is empty\n";
            return;
        }

        for(int i = 0; i < length; i++)
            cout << items[i] << " ";
        cout << "\n";
    }

    //delete
    void delet(int index) //O(n)
    {
        if(isempty())
            return;

        for(int i = index; i < length-1; i++)
            items[i] = items[i+1];
        length--;

    }

    //search
    bool searching(int key)
    {
        for(int i = 0; i < length; i++)
        {
            if(items[i] == key)
            {
                cout << "item is found at index: " << i;
                return true;
            }
        }
        cout << "item is not found\n";
        return false;
    }

};

//2- Dynamic Array

class ArrayDynamic
{
private:
    int siz;
    int length;
    int* items;
public:
    ArrayDynamic(int s)  // creation
    {
        siz = s;
        length = 0;
        items = new int[siz]; //new int items[arrSize]
    }

    void filling()      // fill
    {
        cout << "enter how many items you want to fill?\n";
        int x;
        cin >> x;
        // validation
        if(x > siz)
        {
            cout << "you cant exceed the array size\n";
            return;
        }

        for(int i = 0; i < x; i++)
        {
            cout << "enter item no: " << i << endl;
            cin >> items[i];
            length++;
        }
    }

    void display()
    {
        cout << "display the array items\n";
        for(int i = 0; i < length; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    int getSize() {return siz;}
    int getLen() {return length;}

    void searchi(int key)
    {
        for(int i = 0; i < length; i++)
        {
            if(items[i] == key)
            {
                cout << "item is present in index: " << i << endl;
                return;
            }
        }
        cout << "item is not found\n";
        return;

    }

    void append(int x)
    {
        //validation
        if(length == siz)
        {
            cout << "the array is full\n";
            return;
        }

        items[length] = x;
        length++;
        return;
    }

    void insertt(int index, int num)
    {
        //validation
        if(index < 0 || index >= siz)
        {
            cout << "you cant exceed the array size\n";
            return;
        }

        for(int i = length; i > index; i--)
        {
            items[i] = items[i-1];
        }
        items[index] = num;
        length++;
        return;
    }

    void delet(int index)
    {
        //validation
        if(index < 0 || index >= length)
        {
            cout << "no index like that\n";
            return;
        }

        for(int i = index; i < length-1; i++)
            items[i] = items[i+1];
        length--;
        return;
    }

    void enlarge(int newsize)
    {
        if(newsize <= siz)
        {
            cout << "the new size must be larger than the old one\n";
            return;
        }

        siz = newsize;
        int* old = items;
        items = new int[newsize];

        for(int i = 0; i < length; i++)
            items[i] = old[i];
        delete []old;
    }

    void mergee(ArrayDynamic other)
    {
        siz += other.getSize();
        int* old = items;
        items = new int[siz];

        int i;
        for(i = 0; i < length; i++)
            items[i] = old[i];
        delete []old;

        int j = i;
        for(int x = 0; x < other.getLen(); x++)
        {
            items[j++] = other.items[x];
            length++;
        }

    }
};


int main()
{

    ArrayStatic ar;
    ar.filling();
    ar.display();

    cout << "enter index to del\n";
    int m;
    cin >> m;
    ar.delet(m);
    ar.display();

    cout << "enter index and item to insert\n";
    int n, x;
    cin >> n >> x;
    ar.inserte(n, x);
    ar.display();
    cout << endl;

    cout << ar.access(2) << endl;
    ar.searching(100);


    ArrayDynamic myArr(10);
    myArr.filling();
    myArr.display();
    cout << endl;

    ArrayDynamic two(5);
    two.filling();

    myArr.mergee(two);
    myArr.display();

    return 0;
}
