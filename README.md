# Supermarket Invoice System

**Project Description**  
This C++ console-based invoice system simulates a basic billing process for a supermarket. It allows customers to enter their details, choose products from four categories, specify quantities, and generate a detailed invoice.

## Design Overview
- **Multilevel Inheritance**: `Menu` → `subProducts` → `Product`  
- **Encapsulation**: Product data and logic modularized  
- **File Handling**: Invoices are saved to `customerinvoice.txt`

## Core Functionalities
- View and select items from Clothing, Electronics, Stationary, and Groceries  
- Add multiple products and quantities  
- Display and save formatted invoice with totals

## Error Handling
- Validates product ID input  
- Handles file creation issues

## File Management
- Saves invoice with customer details and purchased items to a text file
