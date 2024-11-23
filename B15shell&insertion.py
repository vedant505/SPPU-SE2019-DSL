def insertionsort(arr):
    # Insertion Sort implementation
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def shellsort(array, n):
    # Shell Sort implementation
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2
    return array

def display(percent):
    # Display top 5 scores
    for i in range(len(percent) - 1, 4, -1):
        print(percent[i])

# Main code
n = int(input("Enter the number of students: "))
percent = []
for i in range(n):
    mks = float(input(f"Enter the percentage of student {i + 1}: "))
    percent.append(mks)

while True:
    print("_________________________________")
    print("\n\t******* Sorting Menu *******")
    print("_________________________________")
    ch = int(input("1. Insertion Sort\n2. Shell Sort and Top 5 Scores\n3. Exit\nEnter your choice: "))

    if ch == 1:
        print("\nResult of Insertion Sort is:", insertionsort(percent))
    elif ch == 2:
        print("\nResult of Shell Sort is:", shellsort(percent, n))
        print("Top 5 Scores are:")
        display(percent)
    elif ch == 3:
        print("\n\t***** PROGRAM EXECUTED SUCCESSFULLY *****")
        break
    else:
        print("Invalid Choice")
