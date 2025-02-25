#include "Book.h"
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
Book::Book(
    int bookId,
    std::u8string author,
    std::u8string title,
    std::u8string genre,
    int publication_year,
    bool IsBorrowed)
    : bookId(bookId), author(author), title(title), genre(genre), publication_year(publication_year), IsBorrowed(IsBorrowed)

{
}
void Book::Display() const
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  std::cout << "BookId: " << bookId << std::endl;
  std::cout << "Author: " << std::string(author.begin() , author.end())<< std::endl;
  std::cout << "Title: " << std::string(title.begin() , title.end()) << std::endl;
  std::cout << "Genre: " << std::string(genre.begin(), genre.end()) << std::endl;
  std::cout << "Publication year: " << publication_year << std::endl;
  std::cout << "Status: " << IsBorrowed << std::endl;
}
void Book::Change_status(bool status)
{
  this->IsBorrowed = status;
}
bool Book::isBorrowed() const
{
  return IsBorrowed;
}
std::u8string Book::getAuthor() const
{
	return author;
}
std::u8string Book::getTitle() const
{
	return title;
}
std::u8string Book::getGenre() const
{
	return genre;
}
int Book::getPublicationYear() const
{
	return publication_year;
}
int Book::getBookId() const
{
    return bookId;
}