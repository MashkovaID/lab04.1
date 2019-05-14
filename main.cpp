#include <iostream>
#include<cstring>
#include<conio.h>
#include<cassert>

using namespace std;

char nibble_to_hex(uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char symbols[]="0123456789abcdef";
    return symbols[i];
}



char
bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}

void
print_in_hex(uint8_t byte)
{
    cout<<nibble_to_hex(byte>>4)
        <<nibble_to_hex(byte & 0xf);
}


void
print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

void print_in_binary(uint8_t byte)
{
    for(int bit=7; bit>=0; bit--)
        cout<<bit_digit(byte, bit);
}

void print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    for(size_t i=0; i<size; i++)
    {
        print_in_binary(bytes[i]);
        if((i+1)%4 == 0)
            cout<<'\n';
        else
            cout<<' ';
    }
}

void calc(uint16_t op1, char operat, uint16_t op2)
{
    print_in_hex(&op1, sizeof(op1));
    cout<<" "<<operat<<" ";
    print_in_hex(&op2, sizeof(op2));
    cout<<" = ";
    uint16_t res;
    if(operat == '&')
    {
        res = op1 & op2;
    }
    if(operat == '|')
    {
        res = op1 | op2;
    }
    if(operat == '^')
    {
        res = op1 ^ op2;
        cout<<res;
    }
}

struct Student
{
    char name [17];
    uint16_t year;
    float avarage;
    uint8_t gender : 1;
    uint8_t courses;
    Student* starosta;
};

int main()
{
    Student students [3] =
    {
        {"Name1", 2018, 4.5, 1, 1,nullptr},
        {"Name2", 2018, 4.6, 0, 1,&students[0]},
        {"Name3", 2018, 4.4, 1, 1,&students[0]},
    };

    cout<<"Address of students "<<&students<<"\n";
    cout<<"Size of students "<<sizeof (students)<<"\n";


    for( size_t i=0; i<3; i++)
    {
        cout<<"Addres of student " << i+1 <<" : "<< &students[i]<<"\n";
        cout<<"Size of student " << i+1 <<" : "<< sizeof(students[i])<<"\n";
    }



cout<< " For student 2 \n";

cout<< " For field 'name':\n"
    << " Address of this field: "<<&students[1].name<<"\n"
    << " Offset from the beginning of the structure: "<< offsetof (Student , name)<<"\n"
    << " Size of this field: "<< sizeof(students[1].name)<<"\n"
    << " In binary representation: \n";
print_in_binary(&students[1].name, sizeof(students[1].name));
cout<<"\n"<< " In hexadecimal representation: \n";
print_in_hex(&students[1]. name, sizeof(students[1].name));
cout<<"\n";

cout<< " For field 'admission year':\n"
    << " Address of this field: "<<&students[1].year<<"\n"
    << " Offset from the beginning of the structure: "<< offsetof (Student, year)<<"\n"
    << " Size of this field: "<< sizeof(students[1].year)<<"\n"
    << " In binary representation: \n";
print_in_binary(&students[1].year, sizeof(students[1].year));
cout<<"\n"<< " In hexadecimal representation: \n";
print_in_hex(&students[1].year, sizeof(students[1].year));
cout<<"\n";

cout<< " For field 'grade point average': \n"
    << " AAddress of this field: "<<&students[1].avarage<<"\n"
    << " Offset from the beginning of the structure: "<< offsetof (Student , avarage)<<"\n"
    << " Size of this field: "<< sizeof(students[1].avarage)<<"\n"
    << " In binary representation: \n";
print_in_binary(&students[1].avarage, sizeof(students[1].avarage));
cout<<"\n"<< " In hexadecimal representation: \n";
print_in_hex(&students[1].avarage, sizeof(students[1].avarage));
cout<<"\n";

cout<< " For field 'number of completed courses': \n"
    << " AAddress of this field: "<<&students[1].courses<<"\n"
    << " Offset from the beginning of the structure: "<< offsetof (Student , courses)<<"\n"
    << " Size of this field: "<< sizeof(students[1].courses)<<"\n"
    << " In binary representation: \n";
print_in_binary(&students[1].courses, sizeof(students[1].courses));
cout<<"\n"<< " In hexadecimal representation: \n";
print_in_hex(&students[1].courses, sizeof(students[1].courses));
cout<<"\n";

cout<< " For field 'headman': \n"
    << " AAddress of this field: "<<&students[1].starosta<<"\n"
    << " Offset from the beginning of the structure: "<< offsetof (Student , starosta)<<"\n"
    << " Size of this field: "<< sizeof(students[1].starosta)<<"\n"
    << " In binary representation: \n";
print_in_binary(&students[1].starosta, sizeof(students[1].starosta));
cout<<"\n"<< " In hexadecimal representation: \n";
print_in_hex(&students[1].starosta, sizeof(students[1].starosta));
cout<<"\n";

    return 0;
}
