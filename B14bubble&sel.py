def bubble(percent):
    # Bubble Sort implementation
    for i in range(len(percent) - 1):
        for j in range(len(percent) - i - 1):
            if percent[j] > percent[j + 1]:
                percent[j], percent[j + 1] = percent[j + 1], percent[j]
    return percent

def selectionSort(array, size):
    # Selection Sort implementation
    for ind in range(size):
        min_index = ind
        for j in range(ind + 1, size):
            if array[j] < array[min_index]:
                min_index = j
        (array[ind], array[min_index]) = (array[min_index], array[ind])
    return array

def display(percent):
    # Display top 5 scores in descending order
    for i in range(len(percent) - 1, 4, -1):
        print(percent[i])

# Main code
n = int(input("Enter the number of students: "))
percent = []
for i in range(n):
    mks = float(input(f"Enter percentage of student {i + 1}: "))
    percent.append(mks)

while True:
    print("\n____________________________________")
    print("\t***** Sorting Menu *****")
    print("_____________________________________")
    ch = int(input("1. Selection Sort \n2. Bubble Sort and Top 5 Scores \n3. Exit \nEnter your choice: "))
    
    if ch == 1:
        print("\nResult of Selection Sort is:", selectionSort(percent, n))
    elif ch == 2:
        print("\nResult of Bubble Sort is:", bubble(percent))
        print("Top 5 Scores are:")
        display(percent)
    elif ch == 3:
        print("\t***** TERMINATED SUCCESSFULLY *****")
        break
    else:
        print("Invalid Choice")
