#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class Book{
private:
    string author;
    string title;
    int pages;
public:
    Book(){
    author = "";
    title = "";
    pages = 0;
    }
    Book(string a, string t, int p){
    author = a;
    title = t;
    pages = p;
    }
    void set(string a, string t, int p){
        author = a;
        title = t;
        pages = p;
    }
    print(){
        cout << "Автор: " << author << endl;
        cout << "Название книги " << title << endl;
        cout << "Количество страниц " << pages << endl;
        }
};

void reading_check(ifstream& s){
    cout << "Считано байт: " << s.tellg() << endl;
}



int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    ifstream book_list("input.txt");
    int n;
    book_list >> n;
    Book *pBook;
    pBook = new Book[n];
    reading_check(book_list);
    string atr = "";
    string ttl = "";
    int pgs = 0; //вспомогательные переменные для записи в массив
    int book_count;
    reading_check(book_list);
    for(int i = 0; i < n; ++i){
    book_list >> atr;
//    cout << atr << endl;
    book_list >> ttl;
//    cout << ttl << endl;
    book_list >> pgs;
//    cout << pgs;
    pBook[i].set(atr, ttl, pgs);
    pBook[i].print();
    }
    reading_check(book_list);
    cout << "Книги успешно считаны из файла!"<< endl;
    cout << "Hello world!" << endl;
    return 0;
    book_list.close();
}
