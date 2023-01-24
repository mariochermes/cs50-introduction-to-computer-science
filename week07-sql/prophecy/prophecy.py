from csv import DictReader
from cs50 import SQL

# Create database
open("sqlite:///roster.db", "w").close()
db = SQL("sqlite:///roster.db")

# Open csv File
with open("students.csv", "r") as file:

    # Create DictReader
    reader = DictReader(file)

    # Iterate over CSV file
    for row in reader:

        # Store the values in variables
        student_name = row["student_name"].strip()
        house_name = row["house"].strip()
        house_head = row["head"].strip()

        # Inserts the values into database
        student_id = db.execute("INSERT INTO students (student_name) VALUES(?)", student_name)
        db.execute("INSERT OR IGNORE INTO houses (house_name, house_head) VALUES(?, ?)", house_name, house_head)
        db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, (SELECT id from houses WHERE house_name = ?))", student_id, house_name)