# CornerGrocer

Project Summary

The Corner Grocer Item Tracker is a program that helps track how often items are purchased at a store. It reads a list of items from a file, counts how many times each item appears, and gives users options to search for an item, see a full list of item frequencies, or display a histogram. This helps store owners better understand what products are selling the most and make smarter decisions about inventory and store layout.

Reflection on Development

What Went Well

The program is well-organized, using a class to manage item tracking, which makes it easy to read and update. The map data structure is a great fit for storing item counts because it allows fast lookups. Adding a function to convert item names to lowercase helped make searches more accurate by making them case-insensitive. To implement this, I researched different ways to convert strings to lowercase and found that using transform() from <algorithm> and tolower() from <cctype> was the best approach. Reading discussions on Stack Overflow and other programming resources helped me understand how to apply this solution effectively in the program.

Areas for Improvement

While the program works well, there are ways it could be improved. Adding more error handling for missing or corrupted files would make it more reliable. Optimizing how the file is read, especially for large datasets, could make it faster. A logging system could also help track errors and make debugging easier.

Challenges and How They Were Solved

One of the trickiest parts was handling user input correctly. It was important to make sure the menu only accepted valid choices and that item searches didn’t break if someone entered numbers or special characters. Using cin.clear() and cin.ignore() helped fix input errors, and adding a check for alphabetic characters made sure searches worked properly. Online resources like Stack Overflow and C++ documentation were useful in figuring out the best way to handle these issues.

Skills Gained

This project helped reinforce important programming skills like object-oriented design, file handling, and input validation. Learning how to use maps for tracking data efficiently is a technique that will be useful in other projects. It also improved my ability to debug and test user input to make programs more user-friendly.

Keeping the Code Clean and Maintainable

To keep the program easy to work with, the code is structured with clear function names and logical sections. The menu system is simple to follow, making it easy to add more features in the future. Using consistent formatting, in-line comments, and a well-organized class makes it easy for others to read and modify the code.

By following good coding practices, the Corner Grocer Item Tracker is a solid and reliable program for tracking grocery purchases, and it can be expanded or improved as needed.

