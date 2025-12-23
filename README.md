# HExpense
H-Expense: Group Expense Tracker

Mini Project

Duration: 30-Mar-2025 to 4-May-2025

Author: Harshith Chegondi

Programming Language: C

------------------------------------------------------------

Project Overview

H-Expense is a command-line tool designed to help groups track and manage shared expenses easily. Built using C, this program enables users to log payments, edit and delete entries, categorize expenses, generate reports, and fairly distribute costs among participants.
To efficiently store and manage financial records, H-Expense utilizes a singly linked list, where each entry contains multiple pieces of information about the expense.

------------------------------------------------------------

Features

Add Entry: Record participant name, amount, and expense category.

Edit Entry: Modify name, expense amount, or category using a unique ID.

Delete Entry: Remove a participant’s record by ID and name.

Category View: Display entries filtered by expense category.

Report Generation: Tabular summary of all expenses.

Settlement Calculation: Computes how much each person should pay or receive.

About Section: Displays project background.

Memory Management: Frees allocated memory on program exit.

------------------------------------------------------------
How to Compile and Run

Requirements:
- C compiler (e.g., GCC)

Compilation:
```bash
gcc HExpense_SourceCode.c -o HExpense_SourceCode
```

Run the Program:
```bash
./HExpense_SourceCode
```

------------------------------------------------------------

Menu Options

Option | Description
-----|--------------------------------------
1      | About H-Expense
2      | Add an entry
3      | Delete an entry
4      | Edit an entry
5      | View entries by category
6      | Calculate settlement
7      | Display report
8      | Exit the program

------------------------------------------------------------

Data Structure Used

Linked List:

A singly linked list stores and manages participants’ details, including their unique IDs, names, paid amounts, and expense categories.

Each node in the linked list represents an individual participant, containing the following fields:

ID – Integer uniquely identifying the participant.

Name – Character array (string) storing participant's name.

Exp – Float value representing the amount paid by the participant.

Cat – Character array (string) indicating the expense category.

Next – Pointer to the next participant in the list.

------------------------------------------------------------

Memory Handling

To prevent memory leaks, H-Expense properly releases dynamically allocated memory using the freeList() function when closing the program.

------------------------------------------------------------

Conclusion

This project demonstrates the use of dynamic data structures and user interaction via console I/O. It effectively simulates a real-world group expense tracker, featuring add/edit/delete operations, reporting, and balancing shared expenses.

------------------------------------------------------------

License

Read-Only License

Copyright (c) Harshith Chegondi, 2025

Permission is granted to use, copy, distribute, and commercially exploit this software in its original form only.

Modification, creation of derivative works, or redistribution of modified versions is strictly prohibited without explicit written permission from the author.

Suggestions, bug reports, and improvement ideas are welcome via GitHub issues or pull requests, but all modifications to the code remain under the sole discretion of the author.

THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
