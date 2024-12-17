
"""
Problem Statement:
Write a python program to store second year percentage of students in array. Write function for sorting array of floating point
numbers in ascending order using 
a) Selection sort
b) Bubble sort and display top five scores
"""

def selection_sort(arr, n):
    for i in range(n):
        min_ind = i
        for j in range(i+1, n):
            if arr[j] < arr[min_ind]:
                min_ind = j
        arr[i], arr[min_ind] = arr[min_ind], arr[i]
    return arr

def bubble_sort(arr, n):
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr [j], arr[j+1] = arr[j+1], arr[j]
    return arr

def accept(arr, n):
    for i in range(n):
        per = float(input("Enter percentage of student: "))
        arr.append(per)
    print("Array of percentage: ")
    print(arr)
    return arr

def main():
    while True:
        print("\n")
        print("\t1: Selection sort")
        print("\t2: Bubble sort")
        print("\t3: Exit")

        ch = int(input("Enter choice: "))


        if ch == 1:
            n = int(input("\nEnter number of students: "))
            arr = []
            accept(arr, n)
            a = selection_sort(arr, n)
            print("Sorted array using selection sort: ")
            print(a)
            print("\nTop five scores: ")
            for i in range(1, 6):
                print(a[n-i], end=" ")
        
        elif ch == 2:
            n = int(input("\nEnter number of students: "))
            arr = []
            accept(arr, n)
            a = bubble_sort(arr, n)
            print("Sorted array using bubble sort: ")
            print(a)
            print("\nTop five scores: ")
            for i in range(1, 6):
                print(a[n-i], end=" ")

        elif ch >= 3:
            print("End of Program")
            break

main()


