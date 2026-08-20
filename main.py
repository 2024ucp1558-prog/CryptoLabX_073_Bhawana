import os
from datetime import datetime
from collections import Counter


def write_log(option):
    os.makedirs("outputs", exist_ok=True)
    with open("outputs/log.txt", "a") as log:
        current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log.write(f"{current_time} - {option}\n")



def analyze_file():
    filename = input("Enter file name (example: sample1.txt): ")

    filepath = os.path.join("datasets", filename)

    if not os.path.exists(filepath):
        print("File not found!")
        return

    with open(filepath, "r") as file:
        text = file.read()

    characters = len(text)
    words = len(text.split())
    lines = len(text.splitlines())
    unique_characters = len(set(text))

    print("\n----- File Analysis -----")
    print("Characters :", characters)
    print("Words      :", words)
    print("Lines      :", lines)
    print("Unique Characters :", unique_characters)

    letters = [char.lower() for char in text if char.isalpha()]
    frequency = Counter(letters)

    print("\nLetter Frequency")
    for letter in sorted(frequency):
        print(f"{letter} : {frequency[letter]}")



while True:

    print("\n========== CryptoLabX ==========")
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Attack")
    print("4. Analyze")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        write_log("Encrypt")
        print("Coming Soon")

    elif choice == "2":
        write_log("Decrypt")
        print("Coming Soon")

    elif choice == "3":
        write_log("Attack")
        print("Coming Soon")

    elif choice == "4":
        write_log("Analyze")
        analyze_file()

    elif choice == "5":
        write_log("Exit")
        print("Thank you for using CryptoLabX.")
        break

    else:
        write_log("Invalid Option")
        print("Invalid choice. Please try again.")
