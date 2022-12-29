import csv
import sys


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database.csv sequence.txt")

    # Load the files into memory
    database_path = sys.argv[1]
    sequence_path = sys.argv[2]

    # Read database file into memory
    persons = []
    with open(database_path, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for k, v in row.items():
                if v.isnumeric():
                    row[k] = int(v)
            persons.append(row)

    strs = [key for key in persons[0].keys() if str(persons[0][key]).isnumeric()]

    # Read DNA sequence file into memory
    with open(sequence_path, "r") as txtfile:
        sequence = txtfile.read()

    # Find longest match of each STR in DNA sequence
    longest_matches = {}
    for i in strs:
        longest_matches[i] = longest_match(sequence, i)

     # Check database for matching profiles
    matching_profile = ""
    for p in persons:
        name = p["name"]
        p.pop("name")
        if p == longest_matches:
            matching_profile = name

    # Prints the matching profile if it exits
    print(matching_profile) if matching_profile != "" else print("No match")

    return


# Returns the longest subsequence in a sequence
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
