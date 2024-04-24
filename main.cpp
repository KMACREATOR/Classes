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
        cout << "Название книги: " << title << endl;
        cout << "Количество страниц: " << pages << endl;
        }
    int get_pages(){return pages;}
    string get_author(){return author;}
    string get_title(){return title;}
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
    int n;
    book_list >> n;
    book_list.ignore();
    Book *pBook;
    pBook = new Book[n];
    vector<Book> VBook(n);
    reading_check(book_list);
    string atr = "";
    string ttl = "";
    int pgs = 0; //вспомогательные переменные для записи в массив
    reading_check(book_list);
    for(int i = 0; i < n; ++i){
    getline(book_list, atr);
    getline(book_list, ttl);
    book_list >> pgs;
    book_list.ignore();
    pBook[i].set(atr, ttl, pgs);
    VBook[i].set(atr, ttl, pgs);
    pBook[i].print();
    }
    reading_check(book_list);
    cout << "Книги успешно считаны из файла!"<< endl;
    Book B0("", "", 0);
    for (int i = 0; i < n; ++i){
        if (pBook[i].get_pages() > B0.get_pages()){

                B0.set_pages(pBook[i].get_pages());
                B0.set_author(pBook[i].get_author());
                B0.set_title(pBook[i].get_title());
        }
    }
    ofstream ot("output.txt");
    output_function(B0, ot);
    Book B1("","", 0);
    for (int i = 0; i < n; ++i){
        Book& tmp = VBook[i];
        if(tmp.get_pages() > B1.get_pages()){
            B1.set_pages(tmp.get_pages());
            B1.set_author(tmp.get_author());
            B1.set_title(tmp.get_title());
        }
    }
    ot << endl;
    output_function(B1, ot);
    book_list.close();
    return 0;
}
