#include "Book.h"
#include <string>
#include <iostream>
Book::Book(
    int bookId,
    std::string author,
    std::string title,
    std::string genre,
    int publication_year,
    bool IsBorrowed)
    : bookId(bookId), author(author), title(title), genre(genre), publication_year(publication_year), IsBorrowed(IsBorrowed)

{
}
void Book::Display() const
{
  std::cout << "BookId: " << bookId << std::endl;
  std::cout << "Name: " << author << std::endl;
  std::cout << "Title: " << title << std::endl;
  std::cout << "Genre: " << genre << std::endl;
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
std::string Book::getAuthor() const
{
	return author;
}
std::string Book::getTitle() const
{
	return title;
}
std::string Book::getGenre() const
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