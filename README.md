# CS-201-HW2--Algorithm-Efficiency-and-Sorting

This is a homework assignment given by Bilkent University in the CS 201 course.

Introduction

Bilkent Campus is planning a tree-planting initiative to maintain its aesthetic appeal. The task involves sorting trees of varying heights delivered by different suppliers. The Computer Engineering Department is responsible for this sorting using various algorithms to ensure uniformity and efficiency in labor hours. This homework assignment requires analyzing and recommending the best sorting methods under different scenarios.

Assumptions

Comparing tree heights takes 1 second.
Changing the position of each tree takes 5 seconds (swapping = 3 position changes).
Truck capacities are powers of 2.
Each worker earns 100 TL per hour.
Empirical measurements should be repeated five times, and the average should be taken.

Tasks

Task 1: Which Algorithm? MY ANSWER -Quick Sort
Objective: Evaluate Insertion Sort, Selection Sort, Bubble Sort, and Quick Sort for sorting trees in trucks of various sizes.
Method: Model each truck as an array of tree heights and simulate sorting.
Output: Provide a 10x4 table of time estimations and related plots (duration vs. size). Discuss the results to recommend the best algorithm.

Task 2: An Assumption!  MY ANSWER -Insertion Sort
Scenario: A supplier delivers trees in an almost sorted order (6% of items are far from their correct positions).
Objective: Determine the best sorting algorithm for almost sorted arrays without empirical results.
Output: Recommend an algorithm, provide a 10x4 table of time estimations with related plots, and discuss the results.

Task 3: Increasing the Number of Workers   MY ANSWER -Quick Sort (parallel quick sort)
Scenario: Due to weather constraints, the administration plans to double the number of workers per truck.
Objective: Recommend an efficient algorithm that can be used by two workers simultaneously. Calculate sorting costs and compare with Task 1's best algorithm.
Output: Suggest an algorithm, provide maximum and minimum time estimations for each worker, and discuss the results.


The report for this taks is in the repository and also the algorithm codes used in the simulation and datas are uploaded.
