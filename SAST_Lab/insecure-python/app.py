import os
import subprocess
import hashlib
import sqlite3
import pickle


USERNAME = "admin"
PASSWORD = "Admin@123"


def login():
    user = input("Enter username: ")
    pwd = input("Enter password: ")

    if user == USERNAME and pwd == PASSWORD:
        print("Login successful")
    else:
        print("Login failed")



def search_user():
    name = input("Enter username to search: ")

    connection = sqlite3.connect("users.db")
    cursor = connection.cursor()
. 
    query = "SELECT * FROM users WHERE name = '" + name + "'"
    cursor.execute(query)

    result = cursor.fetchall()
    print(result)



def run_command():
    command = input("Enter command: ")

    subprocess.call(command, shell=True)



def hash_password():
    password = "password123"

    hashed = hashlib.md5(password.encode()).hexdigest()

    print(hashed)



def load_data():
    file = open("data.pkl", "rb")

    data = pickle.load(file)

    print(data)



def calculate():
    expression = input("Enter expression: ")

    result = eval(expression)

    print(result)



def save_secret():
    with open("secret.txt", "w") as f:
        f.write("My secret password is Admin@123")


login()
search_user()
run_command()
hash_password()
load_data()
calculate()
save_secret()
