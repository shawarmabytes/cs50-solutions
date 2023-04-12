import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        for row in reader:
            database.append(row)  # csv counterpart of pandas
    #print("database: ", database)
    #print("database length", len(database[0]))
    #print("access: ", database[0][i])

    subsequence = []  # initialize empty list
    subsequence_count = len(database[0])  # length or number of subsequences

    for i in range(1, subsequence_count):  # access the subsequences
        # update subsequence list
        subsequence.append(database[0][i])
    # print(subsequence)

    # TODO: Read DNA sequence file into a variable
    f = open(sys.argv[2], "r")
    sequence = f.read()
    # print(sequence)

    matcher_list = []  # list that will contain collection of longest_run
    # for example: [4, 1, 5] for Bob ideally

    # TODO: Find longest match of each STR in DNA sequence
    for i in range(1, subsequence_count):  # iterate through the number of subsequences
        # finds longest match
        matcher = longest_match(sequence, database[0][i])
        # updates the matcher list after obtaining the longest match
    # print(matcher_list) # prints list collection of matcher
        matcher_list.append(matcher)

    # TODO: Check database for matching profiles
     # length of database
    database_length = len(database)

    for i in range(1, database_length):  # scan the database
        int_database = list(map(int, database[i][1:subsequence_count]))  # convert to int
        if matcher_list == int_database:  # profile matching if statement
            print(database[i][0])  # print output answer
            return
    print("No match")

    return


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

    # print(longest_run)
main()
