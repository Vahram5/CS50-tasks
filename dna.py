import csv
import sys


def main():

    # TODO: Check for command-line usage
    while True:
        if len(sys.argv) == 3:
            break

    # TODO: Read database file into a variable
    database_file = open(sys.argv[1], "r")
    database_reader = csv.DictReader(database_file)
    strs = database_reader.fieldnames[1:]
    # print(STRs_name)
    dna_file = open(sys.argv[2], "r")
    dna = dna_file.read()
    dna_file.close()

    # TODO: Find longest match of each STR in DNA sequence
    dna_fingerprint = {}
    for STR in strs:
        dna_fingerprint[STR] = longest_match(dna, str(STR))
    # print(dna_fingerprint)

    # TODO: Check database for matching profiles
    for row in database_reader:
        if datacheck(strs, dna_fingerprint, row):
            print(row['name'])
            database_file.close()
            return

    print("No match")
    database_file.close()


def longest_match(sequence, subsequence):

    c = 0
    list = []
    for i in range(len(sequence)):
        if sequence[i:i+len(subsequence)] == subsequence:
            c += 1
            while True:
                i = i + len(subsequence)
                if sequence[i:i+len(subsequence)] == subsequence:
                    c += 1
                else:
                    list.append(c)
                    c = 0
                    break
        else:
            list.append(0)
    maxx = max(list)
    return maxx


def datacheck(str, match, row):
    c = 0
    for i in str:
        if match[i] == int(row[i]):
            c += 1
    if c == len(row)-1:
        return True


main()
