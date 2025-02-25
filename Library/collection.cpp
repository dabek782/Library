#include "collection.h"
#include <iostream>
#include <fstream> 
#include <sstream>

void Collection::AddBook(
    int bookId,
    std::u8string author,
    std::u8string title,
    std::u8string genre,
    int publication_year,
    bool IsBorrowed)
{
  books.emplace(bookId, Book(bookId, author, title, genre, publication_year, IsBorrowed));
  std::cout << "Book was added to library" << std::endl;
}
void Collection::AddMember(int MemberID, std::u8string Name, std::u8string Email, int Phone)
{
  members.emplace(MemberID, Member(MemberID, Name, Email, Phone));
  std::cout << "Member was given library id" << std::endl;
}
void Collection::DisplayBook(int ID)
{
  for (std::map<int, Book>::iterator i = books.begin(); i != books.end(); i++)
  {
    if (i->first == ID)
    {
      i->second.Display();
    }
    else
    {
      std::cout << "Book not found" << std::endl;
    }
  }
}
void Collection::DisplayMember(int MemberID)
{
  members[MemberID].Display();
}
void Collection::DisplayBooks()
{
  std::map<int, Book>::iterator i;
  for (i = books.begin(); i != books.end(); i++)
  {
    i->second.Display();
  }
}
void Collection::DisplayMembers()
{
  std::map<int, Member>::iterator m;
  for (m = members.begin(); m != members.end(); m++)
  {
    m->second.Display();
  }
}
void Collection::RemoveBook(int ID)
{
  books.erase(ID);
  std::cout << "Book was removed from library" << std::endl;
}
void Collection::RemoveMember(int MemberID)
{
  std::cout << "Member was deleted from database" << std::endl;
}
void Collection::BorrowBook(int BookID, int MemberID)
{
  auto bookIt = books.find(BookID);
  auto memberIt = members.find(MemberID);
  if (bookIt == books.end())
  {
    std::cout << "Book not found" << std::endl;
  }
  else if (memberIt == members.end())
  {
    std::cout << "Member not found" << std::endl;
  }
  else if (bookIt->second.isBorrowed())
  {
    std::cout << "Book is already borrowed" << std::endl;
  }
  else
  {
    bookIt->second.Change_status(true);
    memberIt->second.AddBook(BookID);
    std::cout << "Book was succesefully borrowed" << std::endl;
  }
}
void Collection::ReturnBook(int BookID, int MemberID)
{
  std::map<int, Book>::iterator i;
  for (i = books.begin(); i != books.end(); i++)
  {
    if (i->first != BookID)
    {
      std::cout << "Book not found" << std::endl;
    }
    else if (i->first == BookID && i->second.isBorrowed() == false)
    {
      std::cout << "Book is not borrowed" << std::endl;
    }
    else
    {
      i->second.Change_status(false);
      members[MemberID].RemoveBook(BookID);
      std::cout << "Book was succesefully returned" << std::endl;
    }
  }
}
void Collection::DisplayBorrowedBooks(int BookID)
{
	std::map<int, Book>::iterator i;
	for (i = books.begin(); i != books.end(); i++)
	{
		if (i->first == BookID && i->second.isBorrowed() == true)
		{
			i->second.Display();

		}
		else
		{
			std::cout << "Book not found" << std::endl;
		}
	}
}
void Collection::WriteToFile(std::u8string Filename)
{
	std::ofstream file;
	file.open(std::string(Filename.begin(),Filename.end()), std::ios::binary);
    if (file.is_open())
    {
        file << "\xEF\xBB\xBF";
		for (auto& [id, book] : books)
        {
			file << "Book"  << "|" << book.getBookId() << "|" << std::string(book.getAuthor().begin() , book.getAuthor().end()) << "|" <<std::string(book.getTitle().begin(), book.getTitle().end()) << "|" << std::string(book.getGenre().begin(), book.getGenre().end()) << "|" << book.getPublicationYear() << "|" << book.isBorrowed() << "\n" << std::endl;
        }
        for (auto& [id, members] : members)
        {
            file << "Member" << "|" << members.getMemberID() << "|" << std::string(members.getName().begin(), members.getName().end()) << "|" << std::string(members.getEmail().begin(), members.getEmail().end()) << "|" << members.getPhone() << "\n" << std::endl;
        }
        
    }
}
void Collection::ReadFromFile(std::u8string Filename)
{
    std::ifstream file;
    file.open(std::string(Filename.begin(), Filename.end()), std::ios::binary);
    int bookId;
    std::u8string author;
    std::u8string title;
    std::u8string genre;
    int publication_year;
    bool IsBorrowed;
    int MemberID;
    std::u8string Name;
    std::u8string Email;
    int Phone;
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string type, field;
            iss >> type;
			std::getline(iss, type , '|');
            if (type == "Book")
            {
                std::getline(iss, field, '|'); bookId = std::stoi(field);
				std::getline(iss, field, '|'); std::string(author.begin(), author.end()) = field;
				std::getline(iss, field, '|'); std::string(title.begin() , title.end()) = field;
				std::getline(iss, field, '|'); std::string(genre.begin(), genre.end()) = field;
				std::getline(iss, field, '|'); publication_year = std::stoi(field);
				std::getline(iss, field, '|'); IsBorrowed = std::stoi(field);

                AddBook(bookId, author, title, genre, publication_year, IsBorrowed);
            }
            else if (type == "Member")
            {
                std::getline(iss, field, '|'); MemberID = std::stoi(field);
                std::getline(iss, field, '|'); std::string(Name.begin(), Name.end()) = field;
                std::getline(iss, field, '|'); std::string(Email.begin() ,Email.end()) = field;
                std::getline(iss, field, '|'); Phone = std::stoi(field);
                AddMember(MemberID, Name, Email, Phone);

            }
        }

    }
    else if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
    }

}

Collection::~Collection()
    {
        std::cout << "Library was deleted" << std::endl;
    }