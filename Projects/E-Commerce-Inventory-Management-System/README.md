# E-Commerce Inventory Management System

This project is an **E-Commerce Inventory Management System** designed for a multi-user platform where **Admins**, **Sellers**, and **Buyers** interact with the system. The core functionality includes managing stores, products, buyer accounts, and communication between admins and sellers. The system is implemented in C++ using **unordered maps** for efficient storage and retrieval of data, along with **stacks** to manage seller communication messages.

## Features of the System:

### Admin Features:
- **Add Store**: Admin can add new stores with store name, owner name, CNIC, and password.
- **Delete Store**: Admin can delete stores by their CNIC.
- **View All Stores**: Admin can view a list of all registered stores with details like store name, owner name, CNIC, and earnings.
- **Send Messages to Sellers**: Admin can send messages to specific sellers. These messages are stored in a stack for sellers to view in Last-In, First-Out (LIFO) order.

### Seller Features:
- **Register Store**: Sellers can register their stores by providing necessary details.
- **Login to Store**: Sellers can log in using the store CNIC and password.
- **Add Product**: Sellers can add products to their inventory.
- **Update Product Quantity**: Sellers can update the available stock of products in their inventory.
- **Delete Product**: Sellers can remove products from their inventory.
- **View Sales and Earnings**: Sellers can view their store's sales performance and total earnings.
- **View Messages from Admin**: Sellers can view messages sent by the admin, which are stored in a stack and displayed in LIFO order.

### Buyer Features:
- **Register as Buyer**: Buyers can create an account by providing their name, CNIC, password, and balance.
- **Login as Buyer**: Buyers can log in to their account with CNIC and password.
- **Purchase Products**: Buyers can browse and purchase products from stores.
- **Rate Store**: Buyers can give ratings to stores based on their shopping experience.
- **Check Account Balance**: Buyers can check their current balance and account details.

## Data Structures:
- **Unordered Map**: Used to store buyers and stores efficiently. The `unordered_map<string, Buyer>` stores buyers by their CNIC, and the `unordered_map<string, Store>` stores stores by their CNIC.
- **Stack**: Each store has a stack of messages sent by the admin, allowing sellers to view messages in a LIFO order.

## Additional Features:
- The system supports **error handling** for invalid inputs, ensuring smooth interaction with the system.
- The **message system** allows real-time communication between admin and sellers.

## Usage:
- The system runs in a command-line interface (CLI), where users can choose to act as **Admin**, **Seller**, or **Buyer**.
- Admins can manage stores and send messages, sellers can manage their inventory and view messages, and buyers can shop and manage their accounts.

This project serves as a foundational framework for an E-Commerce system, demonstrating the use of **unordered maps** and **stacks** for efficient data management and interaction in a multi-user environment.
