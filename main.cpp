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

    //пустой конструктор
    Book(){}

    //конструктор для инициализации полей
    Book(string a, string t, int p){
    author = a;
    title = t;
    pages = p;
    }

    //функция для инициализации полей
    void set(string a, string t, int p){
        author = a;
        title = t;
        pages = p;
    }

    //функция для печати полей
    print(){
        cout << "Автор: " << author << endl;
        cout << "Название книги: " << title << endl;
        cout << "Количество страниц: " << pages << endl;
        }

    //get- функции
    int get_pages(){return pages;}
    string get_author(){return author;}
    string get_title(){return title;}

    //set- функции
    void set_title(string t){title = t;}
    void set_pages(int p){pages = p;}
    void set_author(string a){author = a;}


};

void reading_check(ifstream& s){
    cout << "Считано байт: " << s.tellg() << endl;
}

void output_function(Book& B1, ofstream& f){
    B1.print();
    f << B1.get_author() << endl << B1.get_title() << endl << B1.get_pages();
}





int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    ifstream book_list("input.txt");
    //считываем количество книг (оптимизировать
    int n;
    book_list >> n;
    book_list.ignore();

    //создаем динамический массив
    Book *pBook;
    pBook = new Book[n];
    //создаем вектор
    vector<Book> VBook(n);

    reading_check(book_list);

    //вспомогательные переменные для записи в массив
    string atr = "";
    string ttl = "";
    int pgs = 0;

    reading_check(book_list);

    //считываем в массив и в вектор
    for(int i = 0; i < n; ++i){
    getline(book_list, atr);
    getline(book_list, ttl);
    book_list >> pgs;
    book_list.ignore();
    pBook[i].set(atr, ttl, pgs);
    VBook[i].set(atr, ttl, pgs);
    //вспомогательные функции для проверки записи
    pBook[i].print();
    VBook[i].print();
    }

    reading_check(book_list);

    cout << "Книги успешно считаны из файла!"<< endl;

    //открываем вывод
    ofstream ot("output.txt");

    //ищем самую длинную книгу в массиве и записываем в пустую
    Book B0("", "", 0);
    for (int i = 0; i < n; ++i){
        if (pBook[i].get_pages() > B0.get_pages()){

                B0.set_pages(pBook[i].get_pages());
                B0.set_author(pBook[i].get_author());
                B0.set_title(pBook[i].get_title());
        }
    }
    //выводим
    cout << "\nКнига с наибольшим количеством страниц (в массиве): ";
    ot << "\nКнига с наибольшим количеством страниц (в массиве): ";
    output_function(B0, ot);

    //ищем самую длинную книгу в векторе и записываем в пустую
    Book B1("","", 0);
    for (int i = 0; i < n; ++i){
        Book& tmp = VBook[i];
        if(tmp.get_pages() > B1.get_pages()){
            B1.set_pages(tmp.get_pages());
            B1.set_author(tmp.get_author());
            B1.set_title(tmp.get_title());
        }
    }
    //выводим
    cout << "\nКнига с наибольшим количеством страниц (в векторе): ";
    ot << "\nКнига с наибольшим количеством страниц (в векторе): ";
    output_function(B1, ot);

    //закрываем файл и сворачиваемся
    book_list.close();
    return 0;
}
