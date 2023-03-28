import os

import sqlite3
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # Get the user's name and birthday from the form data
        name = request.form["name"]
        month = request.form["month"]
        day = request.form["day"]

        # Validate the name
        if not name:
            return jsonify({"error": "Please enter a valid name"})

        # Validate the birthday
        if not month.isdigit() or not day.isdigit():
            return jsonify({"error": "Please enter a valid month and day"})

        month = int(month)
        day = int(day)

        # Validate the month
        if month < 1 or month > 12:
            return jsonify({"error": "Please enter a valid month between 1 and 12"})

        # Validate the day
        if day < 1 or day > 31:
            return jsonify({"error": "Please enter a valid day between 1 and 31"})

        # Insert into the db
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

        return redirect("/")

    else:

        # Retrieve the list of birthdays from the database
        birthdays = db.execute("SELECT * FROM birthdays")

        # Render the index template with the list of birthdays and an empty form
        return render_template("index.html", birthdays=birthdays)


@app.route('/edit-birthday', methods=['POST'])
def edit_birthday():
    # Get the name and birthday from the request
    name = request.form['name']
    day = request.form['day']
    month = request.form['month']

    # Open a connection to the database
    conn = sqlite3.connect('birthdays.db')
    c = conn.cursor()

    # Update the birthday in the database
    c.execute('UPDATE birthdays SET day=?, month=? WHERE name=?', (day, month, name))
    conn.commit()

    # Close the database connection
    conn.close()

    # Return a success response
    return 'Success'


# Route to handle deleting a birthday
@app.route('/delete-birthday', methods=['POST'])
def delete_birthday():
    # Get the name from the request
    name = request.form['name']

    # Delete the birthday from the database
    db.execute('DELETE FROM birthdays WHERE name=?', (name,))

    # Return a success response
    return 'Success'
