# 📚 RFS-system

A modular C++ system for managing book records and library operations, built with a foundational matrix library. This project demonstrates object-oriented design and encapsulation across multiple components including books, records, and library management.

## 🚀 Features

- Matrix operations for internal data handling
- Book and record management via custom classes
- Library system interface for adding, searching, and organizing entries
- Modular structure with clear separation of concerns

## 📁 File Structure

| File           | Description                                      |
|----------------|--------------------------------------------------|
| `main.cpp`     | Entry point for the application                  |
| `RFS.cpp/h`    | Matrix library implementation                    |
| `book.cpp/h`   | Book class with attributes and methods           |
| `record.cpp/h` | Record class for tracking book-related metadata  |
| `library.cpp/h`| Library class for managing collections           |

## 🛠️ Build Instructions

To compile and run the project:

```bash
g++ main.cpp RFS.cpp book.cpp record.cpp library.cpp -o rfs-system
./rfs-system
