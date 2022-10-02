#include "vectorContain.h"

// local prototype
int vectorMenuOption(const vector<student>& studentRecord);

void vectorContain::vectorMain()
{
    vector<student> v2;
    bool continueVectorMain = true;
    do
    {
        switch (vectorMenuOption(studentRecord))
        {
        case '0': continueVectorMain = false; break;
        case 'A': studentRecord.clear(); cout << "\n\t\tThe record has been cleared.\n"; break;
        case 'B': studentRecord.reserve(amountReserve()); break;
        case 'C': studentRecord.resize(amountResize()); break;
        case 'D': readAndStoreData(studentRecord); break;
        case 'E':
        {
            if (emptyVector())
                studentRecord.pop_back();
        } break;
        case 'F':
        {
            if (emptyVector())
                cout << "\n\tThe element from the front of the vector: [0] " << studentRecord.front() << "\n";
        } break;
        case 'G':;
        {
            if (emptyVector())
                cout << "\n\tThe element from the back of the vector: [" << studentRecord.size() - 1 << "] " << studentRecord.back() << "\n";
        } break;
        case 'H':
        {
            if (emptyVector())
                vectorIndex();
        } break;
        case 'I':
        {
            if (emptyVector())
            {
                iter = studentRecord.begin();
                cout << "\n\tThe iterator referring the first element: " << &*iter << " " << *iter << "\n";
            }
        } break;
        case 'J':
        {
            if (emptyVector())
            {
                iter = studentRecord.end() - 1;
                cout << "\n\tThe iterator referring the past-the-end element: " << &*iter << " " << *iter << "\n";
            }
        } break;
        case 'K':
        {
            if (emptyVector())
                beginAndEndIterator();
        } break;
        case 'L':
        {
            if (emptyVector())
                cout << "\n\tThe reverse iterator pointing to the last element: " << &*studentRecord.rbegin() << " " << *studentRecord.rbegin() << "\n";
        } break;
        case 'M':
        {
            if (emptyVector())
                cout << "\n\tThe reverse iterator pointing to the first element: " << &*(studentRecord.rend() - 1) << " " << *(studentRecord.rend() - 1) << "\n";
        } break;
        case 'N':
        {
            if (emptyVector())
                rBeginAndrEndIterator();
        } break;
        case 'O':
        {
            if (emptyVector())
                eraseIt();
        } break;
        case 'P':
        {
            if (emptyVector())
                eraseBeginAndEnd();
        } break;
        case 'Q': insertElement(); break;
        case 'R':
        {
            if (emptyVector())
                swapVector(v2);
        } break;
        case 'S':
        {
            if (emptyVector())
            {
                sort(studentRecord.begin(), studentRecord.end());
                cout << "\n\tVector sorted.\n";
            }
        } break;

        default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
        }
        system("pause");
    } while (continueVectorMain);
}

// local function to return the user's option
int vectorMenuOption(const vector<student>& studentRecord)
{
    system("cls");
    for (int i = 0; i < studentRecord.size(); i++)
        cout << "\n[" << i << "] " << studentRecord[i] << "\n";
    cout << "\n\t\tVectors are sequence containers representing arrays that can change in size.";
    cout << "\n\t1 > Vector's member functions";
    cout << "\n\t===========================================================================================";
    cout << "\n\t\tA > clear() - Removes all elements from the vector(which are destroyed)";
    cout << "\n\t\tB > reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
    cout << "\n\t\tC > resize(n) - Resizes the container so that it contains n elements";
    cout << "\n\t\tD > Read input.dat and push_back(e) - Adds a new element at the end of the vector";
    cout << "\n\t\tE > pop_back() - Removes the last element in the vector";
    cout << "\n\t\tF > front() - Returns a reference to the first element in the vector";
    cout << "\n\t\tG > back() - Returns a reference to the last element in the vector";
    cout << "\n\t\tH > index using at() or []) - Returns a reference to the element at position n in the vector";
    cout << "\n\t\tI > begin() - Returns an iterator pointing to the first element in the vector";
    cout << "\n\t\tJ > end() Returns an iterator referring to the past - the - end element in the vector";
    cout << "\n\t\tK > Using iterator begin() and end() returns all elements in the vector";
    cout << "\n\t\tL > rbegin() - Returns a reverse iterator pointing to the last element in the vector";
    cout << "\n\t\tM > rend() - Returns a reverse iterator pointing to the theoretical element preceding the first";
    cout << "\n\t\t\t     element in the vector";
    cout << "\n\t\tN > Using iterator rbegin() and rend() returns all elements in the vector";
    cout << "\n\t\tO > erase(it) - Removes from the vector a single element(using an iterator)";
    cout << "\n\t\tP > erase(start_it, end_it) - Removes from the vector a range of elements(using iterators)";
    cout << "\n\t\tQ > insert(it, entry) - Insert a new entry at the iterator.";
    cout << "\n\t\tR > swap() - Exchanges the content of the container by another vector's content of the same type";
    cout << "\n\t\tS > Sort - Sorts the vector.";
    cout << "\n\t===========================================================================================";
    cout << "\n\t\t0 > return";
    cout << "\n\t===========================================================================================";
    int option = inputChar("\n\t\tOption: ");

    return option;
}

bool vectorContain::emptyVector()
{
    if (studentRecord.size() != 0)
    {
        return true;
    }
    else
    {
        cout << "\n\tThe  vector is empty.\n";
        return false;
    }
}

int vectorContain::amountReserve()
{
    int amount = inputInteger("\n\tEnter the capacity(1...100): ");
    return amount;
}
int vectorContain::amountResize()
{
    int amount = inputInteger("\n\tEnter the new size(1...100): ");
    return amount;
}

void vectorContain::readAndStoreData(vector<student>& studentRecord)
{
    ifstream inFile;
    inFile.open("input.dat");
    // Checking for errors
    if (inFile.fail())
    {
        cout << "\n\tERROR: Cannot find the file.\n";
        return;
    }
    // Filling up the vector with the file's data
    while (!inFile.eof())
    {
        string line;

        while (getline(inFile, line)) // grabbing the whole line
        {
            stringstream ss(line);
            string name, year, GPA;

            // Seperating the strings by commas
            getline(ss, name, ',');
            getline(ss, year, ',');
            getline(ss, GPA, ',');
            // Filling the temp class
            student newStudent;
            newStudent.setName(name);
            newStudent.setGradeLevel(year);
            newStudent.setGPA(stod(GPA)); // converts the string into a double

            // storing record into the vector
            studentRecord.push_back(newStudent);
        }
    }
    inFile.close();
    cout << "\n\tCompleted transfering data from file to list.\n";
}

void vectorContain::vectorIndex()
{
    int indexLimit = studentRecord.size() - 1;
    cout << "\n\tEnter the index(0..." << indexLimit << "): ";
    int index = inputInteger("", 0, indexLimit);
    cout << "\t\tvector.at(" << index << "): " << studentRecord.at(index);
    cout << "\n\t\tvector[" << index << "]: " << studentRecord[index] << "\n";
}

void vectorContain::beginAndEndIterator()
{
    cout << "\n\tUsing begin() and end(), the vector contains: ";
    for (iter = studentRecord.begin(); iter != studentRecord.end(); ++iter)
        cout << "\n\t\t" << &*iter << " " << *iter;
    cout << "\n";
}

void vectorContain::rBeginAndrEndIterator()
{
    cout << "\n\tUsing rbegin() and rend(), the vector contains: ";
    for (auto it = studentRecord.rbegin(); it != studentRecord.rend(); ++it)
        cout << "\n\t\t" << &*it << " " << *it;
    cout << "\n";
}

void vectorContain::eraseIt()
{
    if (studentRecord.begin() != (studentRecord.end() - 1))
    {
        studentRecord.erase(studentRecord.begin() + 1);
        cout << "\n\tAn element after the begin iterator " << &*studentRecord.begin() << " has been removed.";
    }
    else
        cout << "\n\tAn element does not exist after begin().";
    cout << "\n";
}

void vectorContain::eraseBeginAndEnd()
{
    cout << "\n\tAll elements starting at begin iterator " << &*studentRecord.begin() << " and going up to the end iterator ";
    cout << &*(studentRecord.end() - 1) << " have been removed.\n";
    studentRecord.erase(studentRecord.begin(), studentRecord.end());
}

void vectorContain::insertElement()
{
    student temp;
    temp.setName(inputString("\n\tEnter a new student name: ", true));
    int level = inputInteger("\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
    temp.setGradeLevel(level == 1 ? "Freshman" : level == 2 ? "Sophmore" : level == 3 ? "Junior" : level == 4 ? "Senior" : "Unknown");
    temp.setGPA(inputDouble("\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));

    if (studentRecord.size() == 0)
    {
        studentRecord.insert(studentRecord.begin(), temp);
        cout << "\n\tThe new element has been inserted at the begin iterator.\n";
    }
    else
    {
        studentRecord.insert((studentRecord.begin() + 1), temp);
        cout << "\n\tThe new element has been inserted after the begin iterator.\n";
    }
}

void vectorContain::swapVector(vector<student>& v2)
{
    if (v2.size() == 0)
        cout << "\n\tVector (v2) is initially empty.\n";

    studentRecord.swap(v2);
    if (studentRecord.size() == 0)
        cout << "\n\tVector (v1) is empty after swapped with vector (v2).\n";
    else
    {
        cout << "\n\tVector (v1) after swapped with vector (v2):\n";
        for (int i = 0; i < studentRecord.size(); i++)
            cout << "\n[" << i << "] " << studentRecord[i] << "\n";
    }

    cout << "\n\tvector (v2) after swapped with vector (v1):\n";
    for (int i = 0; i < v2.size(); i++)
        cout << "\n[" << i << "] " << v2[i] << "\n";
}