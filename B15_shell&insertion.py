
"""
Problem Statement: 
Write a python program to store second year percentage of students in array. Write function for sorting array of floating point
numbers in ascending order using 
a) Insertion sort
b) Shell sort and display top five scores
"""

def accept(arr, n):
    for i in range(n):
        per = float(input("Enter percentage: "))
        arr.append(per)
    print("\nUnsorted array is: ")
    print(arr)

def insertion_sort(arr, n):
    if n <= 1:
        return
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j>=0 and key<arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr

def shell_sort(arr, n):
    gap = n // 2
    while gap>0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j>= gap and arr[j-gap]>temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //= 2

    return arr


def main():
    while True:
        print("\n")
        print("\t1: Insertion sort")
        print("\t2: Shell sort")
        print("\t3: Exit")

        ch = int(input("Enter choice: "))

        if ch == 1:
            n = int(input("Enter number of students: "))
            arr = []
            accept(arr, n)
            a = insertion_sort(arr, n)
            print("Sorted array using insertion sort: ")
            print(a)
            print("\nTop five scores: ")
            for i in range(1, 6):
                print(a[n-i], end=" ")

        if ch == 2:
            n = int(input("Enter number of students: "))
            arr = []
            accept(arr, n)
            a = shell_sort(arr, n)
            b = insertion_sort(a, n)
            print("Sorted array using shell sort: ")
            print(b)
            print("\nTop five scores: ")
            for i in range(1, 6):
                print(b[n-i], end=" ")


        elif ch >= 3:
            print("End of Program")
            break


main()
