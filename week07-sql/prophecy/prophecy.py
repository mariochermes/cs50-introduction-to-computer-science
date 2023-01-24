from csv import DictReader
import cs50

db = cs50.SQL("sqlite:///roster.db")

with open("students.csv", "r") as file:
    reader = DictReader(file)

    for row in reader:

        student_name = row["student_name"].strip()
        house_name = row["house"].strip()
        house_head = row["head"].strip()

        student_id = db.execute("INSERT INTO students (student_name) VALUES(?)", student_name)
        db.execute("INSERT OR IGNORE INTO houses (house_name, house_head) VALUES(?, ?)", house_name, house_head)

        db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, (SELECT id from houses WHERE house_name = ?))", student_id, house_name)