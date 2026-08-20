# Secure Application Assignment - Group 8

## Overview
* **Assigned Application:** E-Commerce Website
* **Group Number:** 8
* **SAST Tool Used:** SonarQube

---

## Implemented Core Functionalities
1. **User Authentication (Login)**
2. **Product Browsing Catalog**
3. **Shopping Cart & Checkout Processing**
4. **Order History Viewer**
5. **Basic User Profile Data Display**

---

## Implemented Vulnerabilities
1. **SQL Injection (`ECommerceApp.java`):**
   * *Description:* User input in the login routine is concatenated directly into SQL query strings without sanitization.
2. **Price Manipulation (`ECommerceApp.java`):**
   * *Description:* Lack of server-side price validation allows negative or tampered pricing during checkout.
3. **Insecure Direct Object Reference - IDOR (`ECommerceApp.java`):**
   * *Description:* Direct lookup of order details by `orderId` without validating user authorization.

---

## How to Run the Application
1. **Compile Code:**
   ```bash
   javac src/ECommerceApp.java
