#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "collection.h"

int main()
{
  bool exit = false;
  Collection c;
  int choice;

  do
  {
    std::cout << "Welcome to the library" << std::endl;
    std::cout << "What can do for you?" << std::endl;
    std::cout << "1. Add a book" << std::endl;
    std::cout << "2. Add a member" << std::endl;
    std::cout << "3. Display all books" << std::endl;
    std::cout << "4. Display all members" << std::endl;
	std::cout << "5. Display a borrowed book" << std::endl;
    std::cout << "6. Display a book" << std::endl;
    std::cout << "7. Display a member" << std::endl;
    std::cout << "8. Remove a book" << std::endl;
    std::cout << "9. Remove a member" << std::endl;
    std::cout << "10. Borrow a book" << std::endl;
    std::cout << "11. Return a book" << std::endl;
	std::cout << "12. Write library to file" << std::endl;
	std::cout << "13. Extract libreary from file" << std::endl;
    std::cout << "14. Exit" << std::endl;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice)
    {
    case 1:
    {
      int bookId;
      std::string author;
      std::string title;
      std::string genre;
      int publication_year;
      bool IsBorrowed;
      std::cout << "Enter the book ID" << std::endl;
      std::cin >> bookId;
      if (std::cin.fail())
      {
        std::cout << "Only numbers can be given" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> bookId;
      }
      std::cout << "Enter the author's name" << std::endl;
      getline(std::cin >> std::ws, author);
      std::cout << "Enter the title" << std::endl;
      getline(std::cin >> std::ws, title);
      std::cout << "Enter the genre" << std::endl;
      getline(std::cin >> std::ws, genre);
      std::cout << "Enter the publication year" << std::endl;
      std::cin >> publication_year;
      std::cout << "Is the book borrowed? 1 for yes, 0 for no" << std::endl;
      std::cin >> IsBorrowed;
      if (std::cin.fail())
      {
        std::cout << "Write 1 for yes and 0 for no" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> IsBorrowed;
      }
      c.AddBook(bookId, author, title, genre, publication_year, IsBorrowed);
      break;
    }
    case 2:
    {
      int MemberID;
      std::string Name;
      std::string Email;
      std::string Phone;
      std::cout << "Enter the member ID" << std::endl;
      std::cin >> MemberID;
      if (std::cin.fail())
      {
        std::cout << "Only numbers can be given" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> MemberID;
      }

      std::cout << "Enter the member's name" << std::endl;
      getline(std::cin >> std::ws, Name);
      std::cout << "Enter the member's email" << std::endl;
      getline(std::cin >> std::ws, Email);
      std::cout << "Enter the member's phone number" << std::endl;
      getline(std::cin >> std::ws, Phone);
      c.AddMember(MemberID, Name, Email, std::stoi(Phone));
      break;
    }
    case 3:
    {
      c.DisplayBooks();
      break;
    }
    case 4:
    {
      c.DisplayMembers();
      break;
    }
	case 5:
    {
		int ID;
		std::cout << "Enter the book ID" << std::endl;
		std::cin >> ID;
		if (std::cin.fail())
		{
			std::cout << "Only numbers can be given" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> ID;
		}
		c.DisplayBorrowedBooks((ID));
		break;
    }
    case 6:
    {
      std::string ID;
      std::cout << "Enter the book ID" << std::endl;
      getline(std::cin >> std::ws, ID);
      c.DisplayBook(std::stoi(ID));
      break;
    }
    case 7:
    {
      std::string MemberID;
      std::cout << "Enter the member ID" << std::endl;
      getline(std::cin >> std::ws, MemberID);
      c.DisplayMember(std::stoi(MemberID));
      break;
    }
    case 8:
    {
      std::string ID;
      std::cout << "Enter the book ID" << std::endl;
      getline(std::cin >> std::ws, ID);
      c.RemoveBook(std::stoi(ID));
      break;
    }
    case 9:
    {
      std::string MemberID;
      std::cout << "Enter the member ID" << std::endl;
      getline(std::cin >> std::ws, MemberID);
      c.RemoveMember(std::stoi(MemberID));
      break;
    }
    case 10:
    {
      std::string BookID;
      std::string MemberID;
      std::cout << "Enter the book ID" << std::endl;
      getline(std::cin >> std::ws, BookID);
      std::cout << "Enter the member ID" << std::endl;
      getline(std::cin >> std::ws, MemberID);
      c.BorrowBook(std::stoi(BookID), std::stoi(MemberID));
      break;
    }
    case 11:
    {
      std::string BookID;
      std::string MemberID;
      std::cout << "Enter the book ID" << std::endl;
      getline(std::cin >> std::ws, BookID);
      std::cout << "Enter the member ID" << std::endl;
      getline(std::cin >> std::ws, MemberID);
      c.ReturnBook(std::stoi(BookID), std::stoi(MemberID));
      break;
    }
	case 12:
    {
	  std::string Filename;
	  std::cout << "Enter the filename or you can write the name of a file and it will be created in the same folder where files for this program are." << std::endl;
	  getline(std::cin >> std::ws, Filename);
	  c.WriteToFile(Filename);
	  break;
    }
    case 13:
    {
		std::string Filename;
		std::cout << "Enter the filename of file that is in the same folder where this program or enter path to this file" << std::endl;
		getline(std::cin >> std::ws, Filename);
		c.ReadFromFile(Filename);
		break;
    }
    case 14:
    {
      exit = true;
      break;
    }
    default:
      std::cout << "Invalid choice" << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      break;
    }
  } while (!exit);
}